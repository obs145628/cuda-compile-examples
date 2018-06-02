#include "vector3.hh"
#include <cmath>
#include <cstdlib>

Vector3::Vector3()
{
    randomize();
}

Vector3::Vector3(float x, float y, float z)
    : x(x)
    , y(y)
    , z(z)
{}

void Vector3::randomize()
{
    x = float(std::rand()) / float(RAND_MAX);
    y = float(std::rand()) / float(RAND_MAX);
    z = float(std::rand()) / float(RAND_MAX);
}

void Vector3::normalize()
{
    float n = std::sqrt(x*x + y*y + z*z);
    x /= n;
    y /= n;
    z /= n;
}

void Vector3::scramble()
{
    float tx = 0.317f*(x + 1.0) + y + z * x * x + y + z;
    float ty = 0.619f*(y + 1.0) + y * y + x * y * z + y + x;
    float tz = 0.124f*(z + 1.0) + z * y + x * y * z + y + x;
    x = tx;
    y = ty;
    z = tz;
}

