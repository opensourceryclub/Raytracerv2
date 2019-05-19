/**
 * @file mat4.c
 * @author Donald Isaac (www.opensourceryumd.com)
 * @author Zach Wild (www.opensourceryumd.com)
 * 
 * @brief 
 * 
 * @version 0.1
 * @date 2019-05-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../../src/math/mat4.c"
#include "../../src/math/vec3.c"
#include "../../src/tools/tools.c"

int test_mat4_factory();
int test_mat4_identity();
int test_mat4_translation();
int test_mat4_destory();

int run_mat4_tests()
{

  char *check = "\u2713";
  char *failX = "\u2717";

  printf("Running mat4 tests...\n");

  // test mat4_factory
  if(test_mat4_factory())
  {
    printf("\t%s test_mat4_factory passed \n", check);
  }
  else
  {
    printf("\t%s test_mat4_factory failed \n", failX);
  }
  
  // test mat4_identity
  if(test_mat4_identity())
    printf("\t%s test_mat4_identity passed \n", check);
  else
    printf("\t%s test_mat4_identity passed \n", failX);

  // test mat4_transform
  if(test_mat4_translation())
    printf("\t%s test_mat4_translation passed \n", check);
  else
    printf("\t%s test_mat4_translation passed \n", failX);

  if(test_mat4_destory())
    printf("\t%s test_mat4_destory passed \n", check);
  else
    printf("\t%s test_mat4_destory passed \n", failX);

  return 0;
}

int test_mat4_factory()
{

  // arrange
  rt_float_t zero = 0.0;

  Mat4 actMat4;
  Mat4 *expMat4 = malloc(sizeof(Mat4));

  rt_float_t actCell;
  rt_float_t expCell;

  int col = 0;
  int row = 0;

  expMat4->rows = calloc(MAT4_ROWS, sizeof(rt_float_t *));
  while (row < MAT4_ROWS)
  {
    expMat4->rows[row] = calloc(MAT4_COLS, sizeof(rt_float_t *));
    row += 1;
  }

  // act
  actMat4 = mat4_factory();

  // assert
  row = 0; 
  while (row < MAT4_ROWS)
  {
    col = 0;
    while(col < MAT4_COLS)
    {
      actCell = actMat4.rows[row][col];
      expCell = expMat4->rows[row][col];
      assert(fl_are_equal(actCell, expCell)); 
      col += 1;
    }
    row += 1;
  }

  return 1;
}

int test_mat4_destory()
{
  // arrange
  int row = 0;
  Mat4 actMat4 = mat4_factory();

  // act
  // assert - no errors make happy
  mat4_destroy(&actMat4);
  return 1;
}

int test_mat4_identity() 
{
  int row = 0;
  int col = 0;

  rt_float_t zero = 0.0;
  rt_float_t one = 1.0;

  // arrange
  Mat4 *expectedMat4 = malloc(sizeof(Mat4));

  // act
  Mat4 actualMat4 = mat4_identity();

  // assert
  while (row < MAT4_ROWS)
  {
    col = 0;
    while (col < MAT4_COLS)
    {
      if (col == row) 
      {
        assert(fl_are_equal(actualMat4.rows[row][col], zero));
      }
      else
      {
        assert(fl_are_equal(actualMat4.rows[row][col], one));
      }
      col += 1;
    }
    row += 1;
  }


  return 1;
}

int test_mat4_translation() 
{
  int row = 0;
  int col = 0;

  
  // arrange
  rt_float_t actCell;
  rt_float_t expCell;
  Mat4 actTransMat;
  Mat4 expTransMat = mat4_factory();
  Vec3 expTransVec = vec3_factory();
  expTransVec.x = 3;
  expTransVec.y = 2;
  expTransVec.z = 1;

  expTransMat.rows[3][0] = 3;
  expTransMat.rows[3][1] = 2;
  expTransMat.rows[3][2] = 1;

  // act
  actTransMat = mat4_translation(expTransVec);

  // assert
  while (row < MAT4_ROWS)
  {
    col = 0;
    while (col < MAT4_COLS)
    {
      actCell = actTransMat.rows[row][col];
      expCell = expTransMat.rows[row][col];
      assert(fl_are_equal(actCell, expCell));
      col += 1;
    }
    row += 1;
  }
  
  return 1;                     // return 1 if test passed?
                                // possibly change in future
}
