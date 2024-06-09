#pragma once
//#include "CommonInclude.h"
//#include "Scene.h"
#include "..//BWEngine_Source//Scene.h"

namespace ya
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}

