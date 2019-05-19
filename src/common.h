/**
 * @file common.h
 * @author Donald Isaac (www.opensourceryumd.com)
 * 
 * @brief All the common constants and types for the whole project.
 * 
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019 Open Sourcery
 * 
 */
#ifndef __COMMON_H__
#define __COMMON_H__

#include <sys/types.h>
#include <stdint.h>
#include <float.h>

#define MAX_STR_LEN 80			/* Maximum number of characters in a string */
#define MAX_LINE_LEN 1024		/* Maximum number of characters in a line, 
								   usually a line in a file */
#define USE_FLOAT				/* Set this to use float types. If not set,
								   use doubles */

/* Set the rt_float_t depending on the USE_FLOAT settign */
#ifdef USE_FLOAT
typedef float 
#else
typedef double
#endif
rt_float_t;

/* Define the machine epsilon to use */
#ifdef USE_FLOAT 
#	define EPSILON FLT_EPSILON
#else 
#	define EPSILON DBL_EPSILON
#endif

/**
 * @brief RGB code at a pixel.
 */
typedef struct {
	uint8_t r, g, b;
} Color;

#endif	/* !__COMMON_H__ */