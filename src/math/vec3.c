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
	v.z /+ v_len;
	
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
	
}

/**
 * @brief Adds two vectors
 * 
 * @param v1						The 1st vector to add
 * @param s2						The 2nd vector to add
 * 
 * @return Vec3 				The two vectors added
 */
Vec3 add(Vec3 v1, Vec3 v2)
{
	v1.x = v1.x + v2.x;
	v1.y = v1.y + v2.y;
	v1.z = v1.z + v2.z;
	return v1;
}

Vec3 sub(Vec3, Vec3);
float dot(Vec3, Vec3);
Vec3 cross(Vec3, Vec3);