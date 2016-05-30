#include "PhysicsSystem.h"

PhysicsSystem::PhysicsSystem()
{
	//Create your Physics world !
	this->collisionConfig=new btDefaultCollisionConfiguration();
	this->dispatcher=new btCollisionDispatcher(collisionConfig);
	this->broadphase=new btDbvtBroadphase();
	this->solver=new btSequentialImpulseConstraintSolver();
	this->world=new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfig);
	this->world->setGravity(btVector3(0,-10,0));

	addGround();
}

PhysicsSystem::~PhysicsSystem()
{
	for(int i=0;i<bodies.size();i++)
		{
			world->removeCollisionObject(bodies[i]);
			btMotionState* motionState=bodies[i]->getMotionState();
			btCollisionShape* shape=bodies[i]->getCollisionShape();
			delete bodies[i];
			delete shape;
			delete motionState;
		}
		delete dispatcher;
		delete collisionConfig;
		delete solver;
		delete broadphase;
		delete world;
}

void PhysicsSystem::addGround()
{
	btTransform groundTransform;
	groundTransform.setIdentity();
	groundTransform.setOrigin(btVector3(0,0,0));
	this->plane=new btStaticPlaneShape(btVector3(0,1,0),0);

	btMotionState* motion=new btDefaultMotionState(groundTransform);
	btRigidBody::btRigidBodyConstructionInfo info(0.0,motion,plane);
	btRigidBody* body=new btRigidBody(info);

	this->world->addRigidBody(body);
	this->bodies.push_back(body);

}

btRigidBody* PhysicsSystem::addBox(float width,float height,float depth,float x,float y,float z,float mass)
{
	btTransform t;
	t.setIdentity();
	t.setOrigin(btVector3(x,y,z));
	btBoxShape* sphere=new btBoxShape(btVector3(width/2.0,height/2.0,depth/2.0));
	btVector3 inertia(0,0,0);
	if(mass!=0.0)
		sphere->calculateLocalInertia(mass,inertia);

	btMotionState* motion=new btDefaultMotionState(t);
	btRigidBody::btRigidBodyConstructionInfo info(mass,motion,sphere,inertia);
	btRigidBody* body=new btRigidBody(info);
	world->addRigidBody(body);
	bodies.push_back(body);
	return body;
}

btRigidBody* PhysicsSystem::addSphere(float rad,float x,float y,float z,float mass)
{
	btTransform t;
	t.setIdentity();
	t.setOrigin(btVector3(x,y,z));
	btSphereShape* sphere=new btSphereShape(rad);
	btVector3 inertia(0,0,0);
	if(mass!=0.0)
		sphere->calculateLocalInertia(mass,inertia);

	btMotionState* motion=new btDefaultMotionState(t);
	btRigidBody::btRigidBodyConstructionInfo info(mass,motion,sphere,inertia);
	btRigidBody* body=new btRigidBody(info);
	world->addRigidBody(body);
	bodies.push_back(body);
	return body;
}

btRigidBody* PhysicsSystem::addCylinder(float d,float h,float x,float y,float z,float mass)
{
	btTransform t;
	t.setIdentity();
	t.setOrigin(btVector3(x,y,z));
	btCylinderShape* sphere=new btCylinderShape(btVector3(d/2.0,h/2.0,d/2.0));
	btVector3 inertia(0,0,0);
	if(mass!=0.0)
		sphere->calculateLocalInertia(mass,inertia);

	btMotionState* motion=new btDefaultMotionState(t);
	btRigidBody::btRigidBodyConstructionInfo info(mass,motion,sphere,inertia);
	btRigidBody* body=new btRigidBody(info);
	world->addRigidBody(body);
	bodies.push_back(body);
	return body;
}



void PhysicsSystem::step()
{
    this->world->stepSimulation(1.0/60.0);
    this->world->performDiscreteCollisionDetection();
    senseCollision();
}


void PhysicsSystem::senseCollision()
{
	int numManifolds = this->world->getDispatcher()->getNumManifolds();
	for (int i = 0; i < numManifolds; i++) {
	  btPersistentManifold* contactManifold = world->getDispatcher()->getManifoldByIndexInternal(i);
	  btCollisionObject* obA = (btCollisionObject*)(contactManifold->getBody0());
	    btCollisionObject* obB = (btCollisionObject*)(contactManifold->getBody1());
	    contactManifold->refreshContactPoints(obA->getWorldTransform(), obB->getWorldTransform());
	    int numContacts = contactManifold->getNumContacts();
	    //For each contact point in that manifold
	    for (int j = 0; j < numContacts; j++) {
	      //Get the contact information
	        btManifoldPoint& pt = contactManifold->getContactPoint(j);
	        btVector3 ptA = pt.getPositionWorldOnA();
	        btVector3 ptB = pt.getPositionWorldOnB();
	        double ptdist = pt.getDistance();
	    }
	}
}
