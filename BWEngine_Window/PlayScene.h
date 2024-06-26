#pragma once
//#include "Scene.h"
//#include "Scene.h"
#include "..//BWEngine_Source//Scene.h"
#include "..//BWEngine_Source//Player.h"

namespace ya
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		Player* bg;
	};
}
