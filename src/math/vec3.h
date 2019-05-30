/**
 * @file vec3.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef __VEC_3_H__
#define __VEC_3_H__

#include "../common.h"

typedef struct {
	rt_float_t x, y, z;
} Vec3;

int vec3_factory_zero(Vec3 **);
int vec3_factory(rt_float_t x, rt_float_t y, rt_float_t z, Vec3 **);
rt_float_t len(Vec3);
Vec3 nor(Vec3);
rt_float_t sqr (Vec3 v);
Vec3 scl(Vec3, rt_float_t);
Vec3 add(Vec3, Vec3);
Vec3 sub(Vec3, Vec3);
rt_float_t dot(Vec3, Vec3);
Vec3 cross(Vec3, Vec3);
rt_float_t dist(Vec3, Vec3);
Vec3 centroid(int, Vec3 *);

#endif /* !__VEC_3_H__ */