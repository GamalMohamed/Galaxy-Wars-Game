/*
 * ResourcesSystem.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: jimmy
 */

#include "ResourcesSystem.h"

ResourcesSystem::ResourcesSystem()
{
	this->shader=new Shader("Game Resources/Shaders/ModelsVertexShader.glsl", "Game Resources/Shaders/ModelsFragmentShader.glsl");

	models=new Model*[numOfModels];

	//models[0]=new Model("Game Resources/Models/Others/Ocean/Ocean.obj");

	models[0]=new Model("Game Resources/Models/Others/Space/2dSpace.obj");

/*
	models[1]=new Model("Game Resources/Models/SpaceShips/Arc-170/obj 2/Arc170.obj");
	models[2]=new Model("Game Resources/Models/SpaceShips/CombatShip/CombatShip.obj");
	models[3]=new Model("Game Resources/Models/SpaceShips/MRX22 Recon Flyer/MRX22 Recon Flyer.obj");
	models[7]=new Model("Game Resources/Models/SpaceShips/X-17 Viper/X-17 Viper flying.obj");

	models[8]=new Model("Game Resources/Models/UFOs/Flying Disk/flying Disk flying.obj");

	models[13]=new Model("Game Resources/Models/Others/Moon/moon.obj");
*/

	//models[5]=new Model("Game Resources/Models/SpaceShips/starcruiser military/Starcruiser military.obj");
	models[6]=new Model("Game Resources/Models/SpaceShips/Wraith Raider Starship/Wraith Raider Starship.obj");
	//models[4]=new Model("Game Resources/Models/SpaceShips/SpaceTrident/SpaceTrident.obj");

	models[9]=new Model("Game Resources/Models/UFOs/ufo/UFO.obj");

	models[10]=new Model("Game Resources/Models/Obstacles/Asteroid/Asteroid.obj");
	/*models[11]=new Model("Game Resources/Models/Obstacles/Missile/missile.obj");
	models[12]=new Model("Game Resources/Models/Obstacles/Rock/rock.obj");
	*/

}



ResourcesSystem::~ResourcesSystem()
{
	for(int i=0;i<numOfModels-1;i++){
		delete models[i];
	}

	delete models;
	delete shader;
}



