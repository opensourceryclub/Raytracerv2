/**
 * @file mat4.h
 * @author Zach Wild (www.opensourceryumd.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef __MAT_4_H__
#define __MAT_4_H__

#include "../common.h"
#include "vec3.h"

#define MAT4_COLS 4
#define MAT4_ROWS 4

typedef struct {
	rt_float_t **rows;
} Mat4;

Mat4 mat4_identity();
Mat4 mat4_translation(Vec3);
Mat4 mat4_rotation_x(Vec3);
Mat4 mat4_rotation_y(Vec3);
Mat4 mat4_rotation_z(Vec3);
Mat4 mat4_rotation_x(Vec3);
Mat4 mat4_translate(Mat4, Vec3);

#endif