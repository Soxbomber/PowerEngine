#include "PlayScene.h"
#include "GameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"

namespace ya
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		//for (size_t i = 0; i < 100; i++)
		//{
		//	GameObject* obj = new GameObject();
		//	obj->SetPosition(rand() % 1280, rand() % 720);
		//	AddGameObject(obj);
		//}
		{
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();
			tr->SetPos(300, 450);
			tr->SetName(L"TR");

			SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();
			tr->SetPos(800, 450);
			tr->SetName(L"TR");

			SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();
			tr->SetPos(100, 650);
			tr->SetName(L"TR");

			SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			AddGameObject(pl);
		}

	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}