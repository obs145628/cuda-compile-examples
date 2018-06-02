#include "logger.hh"
#include "particle.hh"
#include <cstdio>
#include <cstdlib>

__global__
void advance_particles(float dt, Particle* arr, int len)
{
    int idx = threadIdx.x + blockIdx.x*blockDim.x;
    if(idx < len)
        arr[idx].advance(dt);
}

int main(int argc, char **argv)
{
    int n = 1000000;     
    if(argc > 1)
        n = std::atoi(argv[1]);     // Number of Particles
    if(argc > 2)
        std::srand(std::atoi(argv[2])); // Random seed

    Logger logger(std::cout);
    logger << "Initialization...\n";

    Particle* arr  = new Particle[n];
    Particle* dev_arr = nullptr;
    cudaMalloc(&dev_arr, n*sizeof(Particle));
    cudaMemcpy(dev_arr, arr, n*sizeof(Particle), cudaMemcpyHostToDevice);
    for(int i=0; i<100; i++)
    {   // Random distance each step
        float dt = (float)rand()/(float) RAND_MAX;
        advance_particles<<< 1 +  n/256, 256>>>(dt, dev_arr, n);
        cudaDeviceSynchronize();
    }

    cudaMemcpy(arr, dev_arr, n*sizeof(Particle), cudaMemcpyDeviceToHost);
    Vector3 total_dist(0,0,0);
    Vector3 temp;
    for(int i=0; i<n; i++)
    {
        temp = arr[i].total_distance_get();
        total_dist.x += temp.x;
        total_dist.y += temp.y;
        total_dist.z += temp.z;
    }
    float avgX = total_dist.x /(float)n;
    float avgY = total_dist.y /(float)n;
    float avgZ = total_dist.z /(float)n;
    float avgNorm = std::sqrt(avgX*avgX + avgY*avgY + avgZ*avgZ);
    printf("Moved %d Particles 100 steps. Average distance traveled is |(%f, %f, %f)| = %f\n", 
                                          n, avgX, avgY, avgZ, avgNorm);
    return 0;
}
