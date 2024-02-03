#pragma once

#include "spch.h"


namespace Soul
{
	class GameObject;

	class Component
	{
	public:
		GameObject* gameObject;
		Component() {}
		virtual ~Component() {}

		virtual void Start() {}
		virtual void UpdateComponent(float deltaTime) {}
		virtual void DrawComponent() {}
	};

	using ComponentID = std::size_t;

	inline ComponentID GetComponentTypeID()
	{
		static ComponentID lastID = 0;
		return lastID++;
	}

	template <typename T>
	inline ComponentID GetComponentTypeID() noexcept
	{
		static ComponentID typeID = GetComponentTypeID();
		return typeID;
	}

	constexpr std::size_t maxComponents = 32;

	using ComponentBitset = std::bitset<maxComponents>;
	using ComponentArray = std::array<Component*, maxComponents>;
}