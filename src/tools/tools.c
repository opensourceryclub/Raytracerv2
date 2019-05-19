/**
 * @file tools.c
 * @author Zach Wild (opensourceryumd.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

/**
 * @brief Compares two floating point numbers and checks if they are
 * approximately equal, taking machine epsilon into account.
 * 
 * @param a                     The first floating point number
 * @param b                     The second floating point number
 * 
 * @return int                  1 if the numbers are equal; 0 otherwise.
 */
int fl_are_equal(rt_float_t a, rt_float_t b)
{
  if (a - b < EPSILON)
    return 1;
  else if (b - a < EPSILON)
    return 1;
  return 0;
}

