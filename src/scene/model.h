/**
 * @file model.h
 * @author Donald Isaac (www.opensourceryumd.com)
 * 
 * @brief Contains functionality for 3D models.
 * 
 * Models are put into Scenes to be rendered by the raytracer. They are 
 * represented by a triangle mesh. Intersections are calculated by running a
 * triangle/ray intersection check on each triangle in the mesh.
 * 
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019 Open Sourcery
 * 
 */

#ifndef __MODEL_H__
#define __MODEL_H__

#include <stdio.h>
#include "../math/vec3.h"
#include "../math/ray3.h"

typedef struct
{
	/* TODO */
} Material;

typedef struct
{
	/** @breif Array of the verticies that represent the model */
	Vec3 *verticies;

	/** @breif Array of normal vectors. There is one normal vector for each vertex */
	Vec3 *normals;

	/** 
	 * @breif The triangles that make up the mesh. Each face is composed of three
	 * verticies.
	 * This is a 2D array of Vec3 pointers.
	 */
	Vec3 ***faces;
	/**
	 * @brief 
	 * 
	 */
	Material material;
	int vertex_count, face_count;
} Model;

/* Struct Management */
int create_model(Model *model, char *filepath);
int destroy_model(Model *model);
int parse_obj_file(Model *model, FILE *obj_file);

/* Functionality */
int does_intersect(Model *model, Ray3 *r);

#endif /* !__MODEL_H__ */
