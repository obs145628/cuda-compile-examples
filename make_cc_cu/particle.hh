#pragma once

#include "vector3.hh"

class Particle
{
public:
    Particle();
    __host__ __device__ void advance(float dist);
    const Vector3& total_distance_get() const;

private:
    Vector3 position_;
    Vector3 velocity_;
    Vector3 total_distance_;
};
