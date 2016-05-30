#ifndef PHYSICSSYSTEM_H_
#define PHYSICSSYSTEM_H_

#include"GameManager.h"
class PhysicsSystem
{
private:
	//Physics world parameters
	btDynamicsWorld* world;	//every physical object go to the world
	btDispatcher* dispatcher;	//what collision algorithm to use?
	btCollisionConfiguration* collisionConfig;	//what collision algorithm to use?
	btBroadphaseInterface* broadphase;	//should Bullet examine every object, or just what close to each other
	btConstraintSolver* solver;					//solve collisions, apply forces, impulses
	btStaticPlaneShape* plane;
	std::vector<btRigidBody*> bodies;


public:
	PhysicsSystem();
	~PhysicsSystem();

	void step();

    void senseCollision();

	void addGround();
	btRigidBody* addBox(float,float,float,float,float,float,float);
	btRigidBody* addSphere(float,float,float,float,float);
	btRigidBody* addCylinder(float,float,float,float,float,float);


};

#endif /* PHYSICSSYSTEM_H_ */
