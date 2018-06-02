#include "particle.hh"

Particle::Particle()
    : position_()
    , velocity_()
    , total_distance_(0, 0, 0)
{}

void Particle::advance(float d)
{
    velocity_.normalize();
    float dx = d * velocity_.x;
    position_.x += dx;
    total_distance_.x += dx;
    float dy = d * velocity_.y;
    position_.y += dy;
    total_distance_.y += dy;
    float dz = d * velocity_.z;
    position_.z += dz;
    total_distance_.z += dz;
    velocity_.scramble();
}

const Vector3& Particle::total_distance_get() const
{
    return total_distance_;
}
