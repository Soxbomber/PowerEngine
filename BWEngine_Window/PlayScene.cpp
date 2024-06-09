#include "PlayScene.h"
//#include "GameObject.h"
//#include "Player.h"
//#include "Transform.h"
//#include "SpriteRenderer.h"
//#include "Input.h"
#include "PlayScene.h"
#include "Layer.h"
//#include "SceneManager.h"
#include "..//BWEngine_Source//GameObject.h"
//#include "..//BWEngine_Source//Player.h"
#include "..//BWEngine_Source//Transform.h"
#include "..//BWEngine_Source//SpriteRenderer.h"
#include "..//BWEngine_Source//Input.h"
#include "..//BWEngine_Source//SceneManager.h"
#include "..//BWEngine_Source//Object.h"


namespace ya
{
	PlayScene::PlayScene()
		//: bg(nullptr)
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		{
			//bg = new Player();
			//Transform* tr = bg->AddComponent<Transform>();
			//tr->SetPosition(Vector2(0, 0));
			//tr->SetName(L"TR");

			//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			//sr->SetName(L"SR");
			//sr->ImageLoad(L"C:\\Users\\kaget\\Desktop\\GameEngine\\PowerEngine\\Resources\\CloudOcean.png");
			//AddGameObject(bg, enums::eLayerType::BackGround);
			bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"..\\Resources\\CloudOcean.png");
			//AddGameObject(bg, enums::eLayerType::BackGround);
		}
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		//bg = new Player();
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}
