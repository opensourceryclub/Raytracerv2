/**
 * @file vec3.c
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
#include "../../src/math/vec3.c"
#include "../../src/tools/tools.c"

int test_vec3_len();
int test_vec3_nor();
int test_vec3_scl();

int main() {

  char *check = "\u2713";
  char *failX = "\u2717";

  printf("Running vec3 tests...\n");

  // test len
  if (test_vec3_len())
  {
    printf("\t%s test_vec3_len passed \n", check);
  }
  else
  {
    printf("\t%s test_vec3_len failed \n", failX);
  }
  

  return 0;
}

int test_vec3_len() {
  // arrange
  rt_float_t expectedLen = 4;

  Vec3* actVec3 = malloc(sizeof(Vec3));
  actVec3->x = 0;
  actVec3->y = 0;
  actVec3->z = 4;

  // act
  rt_float_t actualLen = len(*actVec3);

  // assert
  assert(fl_are_equal(actualLen, expectedLen));

  // free
  free(actVec3);

  return 1;
}

int test_vec3_nor() {
  // arrange
  Vec3 actVec3 = vec3_factory();
  actVec3.x = 3;
  actVec3.y = 3;
  actVec3.z = 3;

  rt_float_t expX = 1;
  rt_float_t expY = 1;
  rt_float_t expZ = 1;

  // act
  Vec3 actNor = nor(actVec3);

  // assert

  // free
  free(&actVec3);

  return 0;

}

int test_vec3_scl() {
  // arrange

  // act
  // assert

  return 0;
}

