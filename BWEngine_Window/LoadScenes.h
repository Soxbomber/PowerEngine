#pragma once
#include "PlayScene.h"
//#include "SceneManager.h"
#include "SceneManager.h"


namespace ya
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::LoadScene(L"PlayScene");
	}
}