#ifndef DEFS_H
#define DEFS_H

#define GLM_FORCE_RADIANS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>
#include "SOIL/SOIL.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "bullet/btBulletDynamicsCommon.h"

const int screenWidth = 1024;
const int screenHeight = 710;
const int numOfModels = 100;
const float PI= 3.141f;

//btRigidBody* ptr=NULL;

/*
struct Vertex2D{
    GLfloat positionCoordinates[3];
    GLfloat textureCoordinates[2];
};
*/

struct Vertex3D {
    // Position
    glm::vec3 Position;
    // Normal
    glm::vec3 Normal;
    // TexCoords
    glm::vec2 TexCoords;
};

struct Texture {
    GLuint id;
    std::string type;
    aiString path;
};

#endif // DEFS_H
