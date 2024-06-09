#pragma once
#include "PlayScene.h"
#include "TitleScene.h"
//#include "SceneManager.h"
#include "..//BWEngine_Source//SceneManager.h"


namespace ya
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::LoadScene(L"PlayScene");
		SceneManager::LoadScene(L"TitleScene");
	}
}