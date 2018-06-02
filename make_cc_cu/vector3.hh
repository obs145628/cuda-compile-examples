#pragma once

class Vector3
{
public:
    Vector3();
    Vector3(float x, float y, float z);

    void randomize();
    __host__ __device__ void normalize();
    __host__ __device__ void scramble();

    float x;
    float y;
    float z;
};
