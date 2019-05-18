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
#include <sys/types.h>
#include <stdint.h>

#ifndef __COMMON_H__
#define __COMMON_H__

#define MAX_STR_LEN 80			/* Maximum number of characters in a string */
#define MAX_LINE_LEN 1024		/* Maximum number of characters in a line, 
								   usually a line in a file */
#define USE_FLOAT				/* Set this to use float types. If not set,
								   use doubles */

#ifdef USE_FLOAT
typedef float 
#else
typedef double
#endif
rt_float_t;

/**
 * @brief RGB code at a pixel.
 */
typedef struct {
	uint8_t r, g, b;
} Color;

#endif	/* !__COMMON_H__ */