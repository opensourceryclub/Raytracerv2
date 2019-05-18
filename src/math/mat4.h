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

#include "../common.h"
#include "vec3.h"

#define MAT4_SIZE 16

typedef struct {
	rt_float_t **cells
} Mat4;

Mat4 mat4_identity();
Mat4 mat4_translation(Vec3);
Mat4 mat4_rotation_x(Vec3);
Mat4 mat4_rotation_y(Vec3);
Mat4 mat4_rotation_z(Vec3);
Mat4 mat4_rotation_x(Vec3);
Mat4 mat4_translate(Mat4, Vec3);