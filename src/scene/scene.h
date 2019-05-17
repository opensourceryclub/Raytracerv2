/**
 * @file scene.h
 * @author Donald Isaac (www.opensourceryumd.com)
 * 
 * @brief The scene contains all the data required to create a rendering, such
 * as a list of models, lights, etc. 
 * 
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019 Open Sourcery
 * 
 */

#ifndef __SCENE_H__
#define __SCENE_H__

#include "model.h"

typedef struct {
	Model *models;
} Scene;
#endif /* !__SCENE_H__ */