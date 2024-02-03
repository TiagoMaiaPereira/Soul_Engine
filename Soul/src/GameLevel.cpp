#include "spch.h"


namespace Soul
{
	void GameLevel::Start()
	{
		for (auto obj : objectsInLevel)
		{
			obj->Start();
		}
	}

	void GameLevel::Update(float deltaTime)
	{
		for (size_t i = 0; i < objectsInLevel.size(); ++i)
		{
			objectsInLevel[i]->Update(deltaTime);
		}
	}

	void GameLevel::Draw()
	{

	}

	void GameLevel::Refresh()
	{
		objectsInLevel.erase(std::remove_if(std::begin(objectsInLevel), std::end(objectsInLevel),
			[](const std::shared_ptr<GameObject>& mGameObject)
			{
				return !mGameObject->IsActive();
			}),
			std::end(objectsInLevel));
	}
}
