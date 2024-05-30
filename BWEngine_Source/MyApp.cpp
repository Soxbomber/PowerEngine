#include "MyApp.h"
#include "Input.h"
#include "FrameTime.h"
#include "SceneManager.h"

namespace ya
{
	MyApp::MyApp()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
		//, mGameObjects{}
	{

	}
	MyApp::~MyApp()
	{

	}

	void MyApp::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);

		createBuffer(width, height);

		InitializeEtc();
		SceneManager::Initialize();

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
		SceneManager::Update();
	}
	void MyApp::LateUpdate()
	{

	}
	void MyApp::Render()
	{
		clearRenderTarget();
		Time::Render(mBackHdc);

		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}
	void MyApp::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1281, 721);
	}

	void MyApp::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}

	void MyApp::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void MyApp::createBuffer(UINT width, UINT height)
	{
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		mBackHdc = CreateCompatibleDC(mHdc);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}
	void MyApp::InitializeEtc()
	{
		//mPlayer.SetPosition(0, 0);
		Input::Initialize();
		Time::Initialize();
	}
}