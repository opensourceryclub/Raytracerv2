/**
 * @file image.c
 * @author Donald Isaac (www.opensourceryumd.com)
 * @author Zach Wild (www.opensourceryumd.com)
 * 
 * @brief Functionality for writing the result of the render to an image file.
 * 
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019 Open Sourcery
 * 
 */

#include "image.h"
#include <stdlib.h>
#include <sysexits.h>

/**
 * @brief Creates and initializes a image object.
 * 
 * @param img[out] 				Double pointer to the ImageData variable
 * 								being initialized
 * @param width[in] 			Image's width in pixels
 * @param height[in] 			Image's height in pixels
 * @param name[in] 				The name of the image. This will also be the 
 * 								name of the finished image file
 * 
 * @returns						EX_OK on success;
 * 								EX_DATAERR if image/name are NULL or if;
 * 								EX_OSERR if memory allocation fails;
 * 								EX_NOINPUT if the image file can't be opened
 * 								
 */
int create_image(ImageData **image, int width, int height, int antialiasing, char *name)
{
	ImageData *img;								/* Newly created image */

	if (
		!image ||								/* image is a null pointer    */
    	!name ||  								/* No file path provided 	  */	
		!strcmp(name, "")						/* Empty string passed		  */
	) return EX_DATAERR;						/* Throw a bad user data err  */

	img = malloc(sizeof(ImageData));
	if (!img) return EX_OSERR;					/* Memory allocation fails 	  */

	img->img_file = fopen(filepath, "w");		/* Open the file for writing  */
	if(!img->img_file) return EX_NOINPUT;		/* Failed to open the file	  */

	img = malloc(sizeof(ImageData));
    img->height = height;
    img->width = width;
    img->img_type = PPM;						/* TODO: Support PNG encoding */
	img->antialiasing = antialiasing;
	strcpy(img->name, name);

	*image = img;

	return EX_OK;
}

/**
 * @brief 
 * 
 * @param img 
 * 
 * @returns						EX_OK on success; EX_USAGE if img is NULL.
 */\
 
int destroy_image(ImageData *img)
{    
	if (!img) return EX_USAGE;
    free(img);

    return EX_OK;
}

/**
 * @brief Calculates the aspect ratio of an image
 * 
 * @param image 				The image to operate on
 * 
 * @return rt_float_t 			The image's aspect ratio
 */
rt_float_t aspect_ratio(ImageData *image)
{
	return (rt_float_t)image->width / (rt_float_t)image->height;
}