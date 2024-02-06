#pragma once

#include "GameObject.h"

namespace Soul
{
	class GameLevel
	{
	protected:
		std::vector<std::shared_ptr<GameObject>> objectsInLevel;

	public:

		GameLevel() = default;
		virtual ~GameLevel() {};

		void Start();

		void Update(float deltaTime);

		void Draw();

		void Refresh();

		template<typename T, typename... TArgs>
		T* CreateObject(TArgs&&...mArgs)
		{
			T* obj(new T(std::forward<TArgs>(mArgs)...));
			std::shared_ptr<GameObject> sPtr{ obj };

			objectsInLevel.emplace_back(std::move(sPtr));

			obj->Start();

			return obj;
		}



	};
}

