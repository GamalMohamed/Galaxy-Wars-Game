#ifndef RENDERINGSYSTEM_H_
#define RENDERINGSYSTEM_H_

#include"GameManager.h"
class Scene;

class RenderingSystem
{
	 GLfloat height;
	 GLfloat width;

	void set2D(); //Set a 2D scene !

	 //Setting MVPs
	void setTransformationMatrices(Scene*);

	//Actually draws models appropriately !
	void DrawModels(Scene*);

	//Draws the Background environment
	void DrawBackground(Scene*,int);

	void ComputeLight(Scene*);

public:
	RenderingSystem();
	~RenderingSystem();

	void Render(Scene*);




};

#endif /* RENDERINGSYSTEM_H_ */
