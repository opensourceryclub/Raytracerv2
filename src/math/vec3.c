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

/**
 * @brief Creates and initializes a Vec3 on the heap with all coordinates
 * set to 0.
 * 
 * @param[out] vec 					Address of the Vec3 pointer to initialize
 * 
 * @return int 						1 on success, 0 on failure
 */
int vec3_factory_zero(Vec3 **vec)
{
	*vec = malloc(sizeof(Vec3));

	if (!vec)
		return 0;
	(*vec)->x = 0;
	(*vec)->y = 0;
	(*vec)->z = 0;

	return 1;
}

/**
 * @brief Creates a new Vec3 with its coordinates set to a location.
 * 
 * @param[in] x 				x component of new vector
 * @param[in] y 				y component of new vector
 * @param[in] z 				z component of new vector 
 * @param[out] vec 				Address of the Vec3 pointer to initialize
 * 
 * @return int 					1 on success, 0 on failure
 */
int vec3_factory(rt_float_t x, rt_float_t y, rt_float_t z, Vec3 ** vec)
{
	*vec = malloc(sizeof(Vec3));

	if (!vec)
		return 0;
	(*vec)->x = x;
	(*vec)->y = y;
	(*vec)->z = z;

	return 1;
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

rt_float_t sqr(Vec3 v)
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
	return u.x * v.x +
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

/**
 * @brief Calculates the centroid of a set of Vec3s.
 * 
 * The centroid is the average point of the Vec3 set. It is calculated by 
 * performing the arithmetic mean.
 * 
 * If there are no Vec3s in the list, the zero Vec3 is returned.
 * 
 * @param c 					The number of Vec3s in the set
 * @param vecs 					The set of Vec3s
 * 
 * @return Vec3 				The calculated centroid Vec3
 */
Vec3 centroid(int c, Vec3 *vecs)
{
	Vec3 centroid = {0, 0, 0};
	int i;
	rt_float_t denominator;

	if (c <= 0)
		return centroid;

	denominator = 1.0 / (rt_float_t)c;

	for (i = 0; i < c; i++)
	{
		centroid = add(centroid, vecs[i]);
	}
	
	centroid = scl(centroid, denominator);
	return centroid;
}
