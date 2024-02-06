#include "spch.h"
#include "GameObject.h"

namespace Soul
{
	void GameObject::Start()
	{

	}

	void GameObject::Update(float deltaTime)
	{
		for (auto& c : components)
		{
			c->UpdateComponent(deltaTime);
		}
	}

	void GameObject::Draw()
	{
		for (auto& c : components)
		{
			c->DrawComponent();
		}
	}
}
