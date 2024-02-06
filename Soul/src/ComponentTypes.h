#pragma once
#include "spch.h"
#include "Component.h"

#include "Renderer.h"
#include "Engine.h"

namespace Soul
{
	struct PositionComponent : public Component
	{
		glm::vec2 pos;

		PositionComponent() = default;
		PositionComponent(const PositionComponent& other) = default;
		PositionComponent(const glm::vec2 position)
			:pos(position)
		{
		}

		~PositionComponent(){}

		void Start() override
		{

		}

		void UpdateComponent(float deltaTime) override
		{

		}

		void DrawComponent() override
		{

		}

		void SetPos(float x, float y)
		{
			pos.x = x;
			pos.y = y;
		}

		void AddPos(float x, float y)
		{
			pos.x += x;
			pos.y += y;
		}
	};

	struct SpriteComponent: public Component
	{

		SpriteComponent() = default;

		SpriteComponent(const char* path)
		{

		}

		void Start() override
		{

		}

		void UpdateComponent(float deltaTime) override
		{
		}

		void DrawComponent() override
		{
		}
	};
	

}
