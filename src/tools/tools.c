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

rt_float_t EPSILON = 0.0000000001;

int fl_are_equal(rt_float_t a, rt_float_t b)
{
  if (a - b < EPSILON)
    return 1;
  else if (b - a < EPSILON)
    return 1;
  return 0;
}

