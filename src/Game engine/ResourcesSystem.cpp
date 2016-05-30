#include "ResourcesSystem.h"
#include "PhysicsSystem.h"

ResourcesSystem::ResourcesSystem(PhysicsSystem* physicsSystem)
{
	this->ModelShader=new Shader("Game Resources/Shaders/ModelsVertexShader.glsl", "Game Resources/Shaders/ModelsFragmentShader.glsl");
	this->lightingShader=new Shader("Game Resources/Shaders/LightVertexShader.glsl", "Game Resources/Shaders/LightFragmentShader.glsl");

	models=new Model*[numOfModels];


	models[0]=new Model("Game Resources/Models/Others/Space/2dSpace.obj");

	models[1]=new Model("Game Resources/Models/SpaceShips/MRX22 Recon Flyer/ModifiedReconFlyer.obj");
	models[1]->setRigidBody(physicsSystem->addBox(15,5,5,5,0,0,1.0));

	for (int i = 2; i <=6; i++) {
		models[i]=new Model("Game Resources/Models/Obstacles/Asteroid/ModifiedAstroid2.obj");
		models[i]->setRigidBody(physicsSystem->addBox(5,5,5,0,0,0,1.0));
	}

	for (int i = 7; i <=11; i++) {
		models[i]=new Model("Game Resources/Models/UFOs/ufo/ModifiedUfo.obj");
		models[i]->setRigidBody(physicsSystem->addBox(5,5,5,0,0,0,1.0));
	}


	/*Rest of models
	models[0]=new Model("Game Resources/Models/Others/Ocean/Ocean.obj");
	models[5]=new Model("Game Resources/Models/SpaceShips/starcruiser military/Starcruiser military.obj");
	models[4]=new Model("Game Resources/Models/SpaceShips/SpaceTrident/SpaceTrident.obj");
	models[11]=new Model("Game Resources/Models/Obstacles/Missile/missile.obj");
	models[12]=new Model("Game Resources/Models/Obstacles/Rock/rock.obj");


	models[1]=new Model("Game Resources/Models/SpaceShips/Arc-170/obj 2/Arc170.obj");
	models[2]=new Model("Game Resources/Models/SpaceShips/CombatShip/CombatShip.obj");
	models[7]=new Model("Game Resources/Models/SpaceShips/X-17 Viper/X-17 Viper flying.obj");
	models[8]=new Model("Game Resources/Models/UFOs/Flying Disk/flying Disk flying.obj");
	models[13]=new Model("Game Resources/Models/Others/Moon/moon.obj");
	*/

}



ResourcesSystem::~ResourcesSystem()
{
	for(int i=0;i<numOfModels-1;i++)
	{
		delete models[i];
	}

	delete models;
	delete ModelShader;
	delete lightingShader;
}



