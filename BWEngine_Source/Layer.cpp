#include "Layer.h"

namespace ya
{
	Layer::Layer()
	{
	}
	Layer::~Layer()
	{
	}

	void Layer::Initialize()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == nullptr)
				continue;
			gameobj->Initialize();
		}
	}
	void Layer::Update()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == nullptr)
				continue;
			gameobj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == nullptr)
				continue;
			gameobj->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == nullptr)
				continue;

			gameobj->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
}
