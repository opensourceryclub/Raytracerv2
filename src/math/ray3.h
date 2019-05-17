/**
 * @file ray3.h
 * @author Donald Isaac (www.opensourceryumd.com)
 * 
 * @brief Represents a ray in 3D space
 * 
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019 Open Sourcery
 * 
 */

#ifndef __RAY_3_H__
#define __RAY_3_H__

#include "vec3.h"
#include "../common.h"

typedef struct {
	Vec3 origin;
	Vec3 direction;
} Ray3;

Vec3 get_point(Ray3 *, rt_float_t);
Ray3 create_from_points(Vec3, Vec3);

#endif /* !__RAY_3_H__ */
