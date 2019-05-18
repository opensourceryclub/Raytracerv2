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

int testLen();

int main() {

  // test len
  testLen();

  return 0;
}

int testLen() {
  // arrange
  rt_float_t expectedLen = 4;

  Vec3* actVec3 = malloc(sizeof(Vec3));
  actVec3->x = 0;
  actVec3->y = 0;
  actVec3->z = 4;

  // act
  rt_float_t actualLen = len(*actVec3);

  // assert
  assert(actualLen == expectedLen);

  // free
  free(actVec3);

  return 0;
}

int testNor() {
  // arrange
  Vec3* actVec3 = malloc(sizeOf(Vec3));
  actVec3->x = 3;
  actVec3->y = 3;
  actVec3->z = 3;

  rt_float_t expX = 1;
  rt_float_t expY = 1;
  rt_float_t expZ = 1;

  // act
  Vec3 actNor = nor(*actVec3);

  // assert
  assert()

  // free
  free(actVec3);

}

int testScl() {
  // arrange

  // act
  // assert
}

