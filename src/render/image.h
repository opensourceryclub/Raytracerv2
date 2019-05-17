/**
 * @file image.h
 * 
 * @author Donald Isaac (www.opensourceryumd.com)
 * 
 * @brief Functionality for writing the result of the render to an image file.
 * 
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019 Open Sourcery
 * 
 */
#include <stdio.h>
#include "../common.h"

#ifndef __IMAGE_H__
#define __IMAGE_H__

typedef struct image_data{
	int width, height;			/* Width and height of the image in pixels 	  */
	char name[MAX_STR_LEN + 1];	/* Image file's name						  */
	int antialiasing;			/* Should antialiasing be enabled			  */
	enum { PPM, PNG } img_type;	/* The encoding format the image is stored as */
} ImageData;

int create_image(ImageData **, int, int, int, char *);
rt_float_t aspect_ratio(ImageData *);
int destroy_image(ImageData *);

#endif /* !__IMAGE_H__ */
