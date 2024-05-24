#pragma once
#include "GameObject.h"
namespace ya
{
	class MyApp
	{
	public:
		MyApp();
		~MyApp();
		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
		GameObject mPlayer;
	};
}

