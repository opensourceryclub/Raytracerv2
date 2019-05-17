/**
 * @file camera.h
 * @author Donald Isaac (www.opensourceryumd.com)
 * 
 * @brief Represents the camera in 3d space. The camera takes a picture
 * of a Scene and does the brunt work of the raytracing/raycasting.
 * 
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019 Open Sourcery
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "../common.h"
#include "image.h"
#include "camera.h"
#include "../math/ray3.h"

/**
 * @brief 
 * 
 * @param camera 
 * @param img 
 * @param x 
 * @param y 
 * @param width 
 * @param height 
 * @param rays 
 * @param ray_count 
 * @return int 
 */
static int construct_perspective_ray(Camera *camera, ImageData *img, int x,
			int y, Ray3 **rays, int *ray_count)
{
	rt_float_t num_rays_per_side = img->antialiasing ? AA_RAYS_PER_SIDE : 1,
			base = 1.0 / (2.0 * num_rays_per_side),
			i,
			j,
			camX,
			camY,
			width = img->width,
			height = img->height;

	*ray_count = num_rays_per_side * num_rays_per_side;
	(*rays) = malloc(*ray_count * sizeof(Ray3));

	for (i = 0.0; i < num_rays_per_side; i++)
	for (j = 0.0; j < num_rays_per_side; j++)
	{
		rt_float_t mx = base + i/num_rays_per_side,
				my = base + j/num_rays_per_side;

		camX = (2.0 * (mx / (width) - 1.0) * aspect_ratio(img));
		camY = -(2.0 * (my / height) - 1.0);

		(*rays)[num_rays_per_side * i + j]
	}

	

}

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @return Color 
 */
static Color raytrace(int x, int y)
{

}

/**
 * @brief 
 * 
 * @param img_data 
 * @param output_stream 
 * @return int 
 */
int take_picture(Camera *camera, ImageData img_data, int output_stream)
{
	int x, y;
	for (y = 0; y < img_data.height; y++)
	for (x = 0; x < img_data.width; x++)
	{
		/* Run the raytracing algorithm at the current pixel */
		Color pixel = raytrace(x, y);
		/* Write the result to the output stream */
		write(output_stream, &pixel, sizeof(Color));
	}

	return 0;
}
