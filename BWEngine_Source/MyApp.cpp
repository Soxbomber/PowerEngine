#include "MyApp.h"
#include "Input.h"
#include "Time.h"

namespace ya
{
	MyApp::MyApp()
		: mHwnd(nullptr)
	    , mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
	{

	}
	MyApp::~MyApp()
	{

	}

	void MyApp::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd); 

		RECT rect = {0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0,0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

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
		Rectangle(mBackHdc, 0, 0, 1280, 720);
		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}