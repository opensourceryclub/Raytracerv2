/**
 * @file vec3.c
 * @author Donald Isaac (www.opensourceryumd.com)
 * 
 * @brief 
 * 
 * @version 0.1
 * @date 2019-05-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "vec3.h"
#include <math.h>
#include "../common.h"

rt_float_t len(Vec3 v)
{
	#ifdef USE_FLOAT
		return sqrtf(sqr(v));
	#else
		return sqrt(sqr(v));
	#endif
}

Vec3 vec3_factory()
{
	Vec3 *vec = malloc(sizeof(Vec3));
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;

	return *vec;
}

/**
 * @brief Creates a new Vec3 with x,y,z
 * 
 * @param x 										x component of new vector
 * @param y 										y component of new vector
 * @param z 										z component of new vector 
 * @return Vec3 								new Vec3 with x,y,z
 */
Vec3 vec3_factory_x_y_z(rt_float_t x, rt_float_t y, rt_float_t z)
{
	Vec3 vec = vec3_factory();
	vec.x = x;
	vec.y = y;
	vec.z = z;

	return vec;
}

/**
 * @brief Normalizes a vector. Normalized vectors have a magnitude of 1.
 * 
 * @param v 					The vector to normalize
 * 
 * @return Vec3 				The normalized vector
 */
Vec3 nor(Vec3 v)
{
	rt_float_t v_len = len(v);
	
	/* Normalize that boye */
	v.x /= v_len;
	v.y /= v_len;
	v.z /= v_len;
	
	return v;
}

/**
 * @brief Scales a vector by a scalar
 * 
 * @param v						The vector to scale
 * @param s						The scalar
 * 
 * @return Vec3 				The scaled vector
 */
Vec3 scl(Vec3 v, rt_float_t s)
{
	v.x = v.x * s;
	v.y = v.y * s;
	v.z = v.z * s;
	
	return v;
}

rt_float_t sqr (Vec3 v)
{
	return 1;
}

/**
 * @brief Adds two vectors
 * 
 * @param u						The 1st vector to add
 * @param s2						The 2nd vector to add
 * 
 * @return Vec3 				The two vectors added
 */
Vec3 add(Vec3 u, Vec3 v)
{
	u.x = u.x + v.x;
	u.y = u.y + v.y;
	u.z = u.z + v.z;

	return u;
}

/**
 * @brief Subtracts v from u.
 * 
 * @param u            The vector to subtract from
 * @param v            The vector to subtract
 * @return Vec3 
 */
Vec3 sub(Vec3 u, Vec3 v)
{
  u.x = u.x - v.x;
  u.y = u.y - v.y;
  u.z = u.z - v.z;

  return u;
}


/**
 * @brief Gets the distance between two vectors.
 * 
 * @param u 					The first vector
 * @param v 					The second vector
 * 
 * @return rt_float_t 			The distance between the two vectors
 */
rt_float_t dist(Vec3 u, Vec3 v)
{
  return sqrt(dot(u, v));
}

/**
 * @brief Takes the dot product of two vectors.
 * 
 * @see https://en.wikipedia.org/wiki/Dot_product
 * 
 * @param u 					The first vector
 * @param v 					The second vector
 * 
 * @return rt_float_t 			The result of the dot product
 */
rt_float_t dot(Vec3 u, Vec3 v)
{
	return 	u.x * v.x +
			u.y * v.y +
			u.z * v.z;
}

/**
 * @brief Takes the cross product of two vectors.
 * 
 * @see https://en.wikipedia.org/wiki/Cross_product
 * 
 * @param u 					The first vector
 * @param v 					The second vector
 * 
 * @return Vec3 				The result of the cross product
 */
Vec3 cross(Vec3 u, Vec3 v)
{
	Vec3 cross;
	cross.x = u.y * v.z - u.z * v.y; 
	cross.y = u.z * v.x - u.x * v.z; 
	cross.z = u.x * v.y - u.y * v.x;

	return cross;
}
