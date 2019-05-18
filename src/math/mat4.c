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
 * @brief Returns a 4x4 matrix of 0's.
 * 
 * @return Mat4                 4x4 matrix of 0's
 */
Mat4 mat4_factory() {
  int row = 0;
  int col = 0;

  Mat4 *mat = malloc(sizeof(Mat4));                              // alloc mat4
  mat->rows = calloc(MAT4_ROWS, sizeof(rt_float_t *));           // alloc rows

  while (row < MAT4_ROWS) 
  {
    mat->rows[row] = calloc(MAT4_COLS, sizeof(rt_float_t * ));   // alloc cols
    row += 1;
  }

  return *mat;
}

/**
 * @brief Returns the 4x4 identity matrix
 * 
 * @return Mat4                 4x4 identity matrix
 */
Mat4 mat4_identity()
{
  int row = 0;
  int col = 0;

  Mat4 mat = mat4_factory();

  while (row < MAT4_ROWS) 
  {
    col = 0;
    while (col < MAT4_COLS) 
    {
      if (col == row) 
      {
        mat.rows[row][col] = 1.0;
      }
      col += 1;
    }
    row += 1;
  }

  return mat;
}

/**
 * @brief Creates a translation matrix for the specified vector
 * @
 * 
 * @param v                     vector to translate by
 * @return Mat4                 4x4 translation matrix
 */
Mat4 mat4_translation(Vec3 v)
{
  Mat4 mat = mat4_identity();

  /* todo: should we write something to generalize this
    to n-dimensional vectors??? i know that isn't relevant for this
    project but idk maybe who knows fuck it mask off
  */

  // wikipedia - https://en.wikipedia.org/wiki/Translation_(geometry)
  mat.rows[3][0] = v.x;
  mat.rows[3][1] = v.y;
  mat.rows[3][2] = v.z;

  return mat;
}

Mat4 mat4_rotation_x(Vec3);
Mat4 mat4_rotation_y(Vec3);
Mat4 mat4_rotation_z(Vec3);
Mat4 mat4_rotation_x(Vec3);
Mat4 mat4_translate(Mat4, Vec3);