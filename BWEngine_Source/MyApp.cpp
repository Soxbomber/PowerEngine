#include "MyApp.h"
#include "Input.h"

namespace ya
{
	MyApp::MyApp()
		: mHwnd(nullptr)
	    , mHdc(nullptr)
	{

	}
	MyApp::~MyApp()
	{

	}

	void MyApp::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd); 
		mPlayer.SetPosition(0,0);
		Input::Initialize();
	}

	void MyApp::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void MyApp::Update()
	{
		Input::Update();
		mPlayer.Update();
	}
	void MyApp::LateUpdate()
	{

	}
	void MyApp::Render()
	{
		mPlayer.Render(mHdc);
	}
}