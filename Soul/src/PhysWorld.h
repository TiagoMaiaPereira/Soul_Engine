#pragma once
#include "spch.h"
#include "GameLevel.h"


namespace Soul
{
	class PhysWorld : public b2ContactListener
	{
	public:
		PhysWorld();
		~PhysWorld() {};
		void Update(float deltaTime);

		void DestroyBody(b2Body* body);


		b2Body* CreateBody(b2BodyDef body);

		void QueueCreateBody(b2Body*& body, const b2BodyDef& bodyDef);
		void QueueFixtureCreation(b2Body*& body, const b2FixtureDef& fixtureDef, const b2PolygonShape& shape);
		void ProcessPendingCreations();


		static PhysWorld& GetPhysicsWorld() { return *m_Instance; }
		GameLevel& GetWorld() { return *m_World; }

		void SetWorld(GameLevel* world);


		void BeginContact(b2Contact* contact) override;


		void EndContact(b2Contact* contact) override;


		void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) override;


		void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) override;

	private:
		static PhysWorld* m_Instance;

		GameLevel* m_World;

		b2Vec2 gravity = b2Vec2(0.0f, -9.8f);
		b2World* level;

		std::vector<b2BodyDef> pendingBodyAssigns;
		std::vector<b2Body**> pendingBodies;

		std::vector<b2FixtureDef> pendingFixtures;
		std::vector<b2PolygonShape> pendingShapes;
		std::vector<b2Body**> pendingFixtureAssings;

	};
}