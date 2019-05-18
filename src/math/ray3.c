/**
 * @file ray3.c
 * @author Donald Isaac (www.opensourceryumd.com)
 * 
 * @brief Implements the functionality for rays in 3D space
 * 
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019 Open Sourcery
 * 
 */

#include "ray3.h"

/**
 * @brief Gets a point along a ray.
 * 
 * @param ray 					The ray the point lays on
 * @param dist 					The distance along the ray
 * 
 * @return Vec3 				The desired point on the ray
 */
Vec3 get_point(Ray3 ray, rt_float_t dist)
{
	/* point = origin + dist * direction */
	return add(ray.origin, scl(ray.direction, dist));
}

/**
 * @brief Create a ray from point to another
 * 
 * @param p1 					The first point. Becomes the ray's origin
 * @param p2 					The second point. Determines the ray's direction
 * 
 * @return Ray3 				The created ray
 */
Ray3 create_from_points(Vec3 p1, Vec3 p2)
{
	Ray3 ray;

	ray.origin = p1;
	ray.dir = nor(dist(p2, p1));
}
