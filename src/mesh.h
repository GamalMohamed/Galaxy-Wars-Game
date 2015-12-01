#ifndef MESH_H
#define MESH_H
#include"Defs.h"
#include"shader.h"

class Mesh
{
public:
    //Mesh Data
    vector<Vertex3D> vertices;
    vector<GLuint> indices;
    vector<Texture> textures;

    Mesh(vector<Vertex3D> vertices, vector<GLuint> indices, vector<Texture> textures);

    // Render the mesh
    void Draw(Shader shader) ;

private:
    //Render data
    GLuint VAO, VBO, EBO;

    // Initializes all the buffer objects/arrays
    void setupMesh();

};



#endif // MESH_H
