/**
 * @file mat4.c
 * @author Zach Wild (www.opensourceryumd.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "vec3.h"
#include "mat4.h"

/**
 * @brief Returns the 4x4 identity matrix
 * 
 * @return Mat4   4x4 identity matrix
 */
Mat4 mat4_identity()
{
  int row = 0;
  int col = 0;

  Mat4 *mat = malloc(sizeof(Mat4));                              // alloc mat4
  mat->rows = calloc(MAT4_ROWS, sizeof(rt_float_t *));           // alloc rows

  while (row < MAT4_ROWS) 
  {

    mat->rows[row] = calloc(MAT4_COLS, sizeof(rt_float_t * ));   // alloc cols

    col = 0;
    while (col < MAT4_COLS) 
    {
      if (col == row) 
      {
        mat->rows[row][col] = 1.0;
      }
      col += 1;
    }

    row += 1;
  }

  return *mat;
}

Mat4 mat4_translation(Vec3);
Mat4 mat4_rotation_x(Vec3);
Mat4 mat4_rotation_y(Vec3);
Mat4 mat4_rotation_z(Vec3);
Mat4 mat4_rotation_x(Vec3);
Mat4 mat4_translate(Mat4, Vec3);
