#include "p5/spherebody.hpp"
#include "math/vector.hpp"
#include "math/matrix.hpp"
#include "scene/sphere.hpp"
#include <iostream>
#include <exception>
#include <algorithm>

namespace _462 {

SphereBody::SphereBody( Sphere* geom )
{
    sphere = geom;
    position = sphere->position;
    radius = sphere->radius;
    orientation = sphere->orientation;
    mass = 1.0;
    velocity = Vector3::Zero();
    angular_velocity = Vector3::Zero();
    force = Vector3::Zero();
    torque = Vector3::Zero();
}

Vector3 SphereBody::step_position( real_t dt, real_t motion_damping )
{
    sphere->position = position;
    return Vector3::Zero();
}

Vector3 SphereBody::step_orientation( real_t dt, real_t motion_damping )
{
    sphere->orientation = orientation;
    return Vector3::Zero();
}

void SphereBody::apply_force( const Vector3& f, const Vector3& offset )
{
	force = f;
	torque = cross(offset, f);
}

}