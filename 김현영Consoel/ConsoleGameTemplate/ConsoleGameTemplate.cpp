// ConsoleDoubleBuffering.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include <stdio.h>
#include "SceneManager.h"


float speed = 2.3f;

static bool g_bQuit = false;
static void ProcessInput();
void Update();
void Render();


COORD g_Player = { 0,0 };

int main()
{	
	ConsoleRender::ScreenInit();	

	SceneManager::SceneInit();

	Time::InitTime();

	while (!g_bQuit)
	{
		Time::UpdateTime();
		Input::Update();	

		SceneManager::SceneUpdate();
		SceneManager::SceneRender();
		//Update();
		//Render();
	};

	ConsoleRender::ScreenRelease();
}


void static ProcessInput()
{
	if (Input::IsKeyDown(VK_LEFT)) { //왼쪽
		g_Player.X--;
	}
	else if (Input::IsKeyPressed(VK_LEFT) && Input::IsKeyDown(VK_UP)) {
		g_Player.X++;
		g_Player.Y++;
		if ((Input::IsKeyPressed(VK_LEFT) || Input::IsKeyReleased(VK_LEFT)) && Input::IsKeyReleased(VK_UP))
			g_Player.Y-- * speed;
	}
	else if (Input::IsKeyDown(VK_RIGHT)) { //오른쪽
		g_Player.X++;
	}
	else if (Input::IsKeyPressed(VK_RIGHT) && Input::IsKeyDown(VK_UP)) {
		g_Player.X++;
		g_Player.Y++;
		if ((Input::IsKeyPressed(VK_RIGHT) || Input::IsKeyReleased(VK_RIGHT)) && Input::IsKeyReleased(VK_UP))
			g_Player.Y-- * speed;
	}
	else if (Input::IsKeyDown(VK_UP)) { //위
		g_Player.Y--;
	}
	else if (Input::IsKeyDown(VK_DOWN)) { //아래
		g_Player.Y++;
	}
	else if (Input::IsKeyDown(VK_ESCAPE)) { //종료
		g_bQuit = true;
		}

}

//void Update()
//{
//	ProcessInput();
//
//	if (g_Player.X < 0) g_Player.X = 0;
//	if (g_Player.X >= ConsoleRender::ScreenWidth()) g_Player.X = ConsoleRender::ScreenWidth() - 1;
//	if (g_Player.Y < 0) g_Player.Y = 0;
//	if (g_Player.Y >= ConsoleRender::ScreenHeight()) g_Player.Y = ConsoleRender::ScreenHeight() - 1;
//}

//void Render()
//{
//	ConsoleRender::ScreenClear();
//
//	char buf[256] = { 0, };
//	float time = Time::GetTotalTime();
//	sprintf_s(buf,"프로그램 시작이후의 시간입니다. %f",Time::GetTotalTime());
//	
//	ConsoleRender::ScreenDrawString(0, 0, buf, FG_PINK_DARK);
//	ConsoleRender::ScreenDrawString(0, 1,L"특수문자는 Wide Character의 출력이 필요합니다.abcd한글🌊🏄‍♂️🚁😀⭠⭡⭢⭣⭦⭧⭨⭩⬤111", FG_PINK_DARK);
//	ConsoleRender::ScreenDrawChar(g_Player.X, g_Player.Y, L'A', FG_WHITE);
//	
//	ConsoleRender::ScreenFlipping();
//}


