#pragma once
#include "spch.h"

namespace Soul
{
	class GameObject
	{

	public:

		GameObject() = default;
		virtual ~GameObject() {};

		virtual void Start();
		virtual void Update(float deltaTime);
		virtual void Draw();

		void AddTag(const std::string& tag) {
			Tag = tag;
		}

		std::string GetTag() const
		{
			return Tag;
		}

		bool HasTag(const std::string& tag)
		{
			if (tag == Tag) {
				return true;
			}
			return false;
		}

		bool IsActive() const { return isActive; }

		void Destroy()
		{
			isActive = false;
		}

		template <typename T>
		bool HasComponent() const
		{
			return componentBitset[GetComponentTypeID<T>()];
		}

		template <typename T, typename... TArgs>
		T& AddComponent(TArgs&&... mArgs)
		{
			T* c(new T(std::forward<TArgs>(mArgs)...));
			c->gameObject = this;
			std::unique_ptr<Component> uPtr{ c };
			components.emplace_back(std::move(uPtr));

			componentArray[GetComponentTypeID<T>()] = c;
			componentBitset[GetComponentTypeID<T>()] = true;

			c->Start();
			return *c;
		}

		template<typename T>
		T& GetComponent() const
		{
			auto ptr(componentArray[GetComponentTypeID<T>()]);
			return *static_cast<T*>(ptr);
		}

	private:

		bool isActive;
		std::string Tag = "Default";

		std::vector<std::unique_ptr<Component>> components;

		ComponentArray componentArray;
		ComponentBitset componentBitset;
	};
}

