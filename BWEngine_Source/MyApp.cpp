#include "MyApp.h"
#include "Input.h"
#include "Time.h"

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
		Time::Initialize();
	}

	void MyApp::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void MyApp::Update()
	{
		Time::Update();
		Input::Update();
		mPlayer.Update();
	}
	void MyApp::LateUpdate()
	{

	}
	void MyApp::Render()
	{
		Time::Render(mHdc);
		mPlayer.Render(mHdc);
	}
}