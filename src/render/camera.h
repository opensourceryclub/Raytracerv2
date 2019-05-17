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

#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "../math/vec3.h"

/** 
 * Number of rays per side when antialiasing is used. The total number of rays
 * per pixel is AA_RAYS_PER_SIDE^2
 */
#define AA_RAYS_PER_SIDE 3

typedef struct {
	/** Camera's position relative to the Scene's origin */
	Vec3 position;

	/** Focal length. Larger values yield images that look further away */
	rt_float_t focal_length;	

	/** field of view angle in radians */
	rt_float_t fov;
} Camera;
/* int take_picture(ImageData img_data, int output_stream); */

#endif /* !__CAMERA_H__ */
