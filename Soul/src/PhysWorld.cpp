#include "spch.h"
#include "PhysWorld.h"
#include "ComponentTypes.h"

namespace Soul 
{

	PhysWorld* PhysWorld::m_Instance;

	PhysWorld::PhysWorld() {
		m_Instance = this;
		level = new b2World(gravity);

		level->SetContactListener(this);
		level->SetContinuousPhysics(true);
		level->SetAllowSleeping(false);

	}

	void PhysWorld::Update(float deltaTime)
	{
		level->Step(deltaTime, 12, 8);

		ProcessPendingCreations();
	}

	void PhysWorld::QueueCreateBody(b2Body*& body, const b2BodyDef& bodyDef) {
		pendingBodyAssigns.push_back(bodyDef);
		pendingBodies.push_back(&body);
	}

	void PhysWorld::QueueFixtureCreation(b2Body*& body, const b2FixtureDef& fixtureDef, const b2PolygonShape& shapeDef)
	{
		pendingShapes.push_back(shapeDef);
		pendingFixtureAssings.push_back(&body);
		pendingFixtures.push_back(fixtureDef);
	}

	void PhysWorld::ProcessPendingCreations() {
		for (int i = 0; i < pendingBodyAssigns.size(); ++i)
		{

			b2Body* newBody = CreateBody(pendingBodyAssigns[i]);
			*(pendingBodies[i]) = newBody;

			for (int j = 0; j < pendingFixtures.size(); ++j)
			{
				if (pendingBodies[i] == pendingFixtureAssings[j])
				{
					b2FixtureDef newFix;
					newFix.shape = &pendingShapes[j];
					newFix.density = pendingFixtures[j].density;
					newFix.friction = pendingFixtures[j].friction;
					newFix.restitution = pendingFixtures[j].restitution;
					newFix.restitutionThreshold = pendingFixtures[j].restitutionThreshold;

					newFix.userData.pointer = pendingFixtures[j].userData.pointer;
					newFix.isSensor = pendingFixtures[j].isSensor;

					newBody->CreateFixture(&newFix);
				}
			}
		}

		pendingBodyAssigns.clear();
		pendingBodies.clear();
		pendingFixtures.clear();
		pendingFixtureAssings.clear();
	}

	void PhysWorld::DestroyBody(b2Body* body)
	{
		level->DestroyBody(body);
	}

	b2Body* PhysWorld::CreateBody(b2BodyDef body)
	{
		std::cout << "Created Physics Body" << std::endl;
		return level->CreateBody(&body);
	}

	void PhysWorld::SetWorld(GameLevel* world)
	{
		m_World = world;
	}

	void PhysWorld::BeginContact(b2Contact* contact)
	{
		GameObject* actorA = ((GameObject*)contact->GetFixtureA()->GetUserData().pointer);
		GameObject* actorB = ((GameObject*)contact->GetFixtureB()->GetUserData().pointer);


		if (actorA != nullptr && actorB != nullptr) {
			actorA->OnContact(actorB);
			actorB->OnContact(actorA);
		}

	}

	void PhysWorld::EndContact(b2Contact* contact)
	{
		GameObject* actorA = ((GameObject*)contact->GetFixtureA()->GetUserData().pointer);
		GameObject* actorB = ((GameObject*)contact->GetFixtureB()->GetUserData().pointer);

		if (actorA != nullptr && actorB != nullptr) {
			actorA->OnContactEnd(actorB);
			actorB->OnContactEnd(actorA);
		}

	}

	void PhysWorld::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
	{

	}

	void PhysWorld::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
	{

	}

}