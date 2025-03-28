#include "PlayScene.h"

extern COORD g_Player; 
//스코어 객체 초기화 
Score ScoreItem = { 0, ConsoleRender::ScreenWidth(), ConsoleRender::ScreenHeight() - 1 };
MapSize Mapsize = { ConsoleRender::ScreenWidth() , ConsoleRender::ScreenHeight() };

// 콘솔창에 띄울 맵 
const char* map = new char[Mapsize.MAP_Y * Mapsize.MAP_X + Mapsize.MAP_X];

bool isActive = false; // 어택 가능한 지 체크하는 변수 

// 플레이 시작 시에 플레이어에게 주어지는 초기화 값 
void PLAY::PlayInit()
{
	Time::InitTime();
}

void PLAY::PlayUpdate()
{
	void ProcessInput();

	if (g_Player.X < 0) g_Player.X = 0;
	if (g_Player.X >= ConsoleRender::ScreenWidth()) g_Player.X = ConsoleRender::ScreenWidth() - 1;
	if (g_Player.Y < 0) g_Player.Y = 0;
	if (g_Player.Y >= ConsoleRender::ScreenHeight()) g_Player.Y = ConsoleRender::ScreenHeight() - 1;
}

void PLAY::PlayRender()
{
	ConsoleRender::ScreenClear();

	char buf[256] = { 0, };
	float time = Time::GetTotalTime();
	sprintf_s(buf, "프로그램 시작이후의 시간 : %f", Time::GetTotalTime());

	ConsoleRender::ScreenDrawString(0, 0, buf, FG_PINK_DARK);
	ConsoleRender::ScreenDrawString(0, 1, L"PlayScene입니다.", FG_PINK_DARK);
	ConsoleRender::ScreenDrawChar(g_Player.X, g_Player.Y, L'A', FG_WHITE);

	ConsoleRender::ScreenFlipping();
}



/********************************************************************************************************/

											// 랜덤 스코어 아이템 

/********************************************************************************************************/

void PLAY::RandomScore()
{
	int Random = rand() % (ScoreItem.SCORE_X * ScoreItem.SCORE_Y);
	map[ScoreItem.SCORE_Y * ScoreItem.SCORE_X + ScoreItem.SCORE_X];

	for (int i = 0; i < Mapsize.MAP_X; ++i)
	{
		for (int j = 0; j < Mapsize.MAP_Y; ++j)
		{
			i = ScoreItem.SCORE_X * Random; 
			j = ScoreItem.SCORE_Y * Random; 

			//맵에 랜덤으로 'SCORE' 가 나타나게 한다. 
			if (map[j * Mapsize.MAP_X + i])
			{
				printf("■"); // 스코어 활성화. 어택 가능하다. 
				isActive = true; 
			}
					
		}
		
	}
}

void PLAY::ScoreActCheck()
{
	if (Time::GetDeltaTime() <= +3 && map[ScoreItem.SCORE_Y * Mapsize.MAP_X + ScoreItem.SCORE_X])
	{
		isActive = true;
		printf("■"); // 스코어 활성화. 어택 가능하다. 
	}
}

// 스코어 점수 체크 
void PLAY::ScoreCheck()
{
	if (ScoreItem.score == 100)
	{
		// 스코어 점수 달성으로 승리. 
		// 엔딩 씬으로 연결? 
		// 

	}
}

// 스코어 점수 증감 
void PLAY::Score()
{
  
	// 증감 조건 : 플레이어가 랜덤으로 나타나는 스코어에 닿았는지 검사한다. 
	for (int score = 0; score <= 100; score++)
	{
		if (g_Player.X == ScoreItem.SCORE_X && g_Player.Y == ScoreItem.SCORE_Y)
		{
			ScoreItem.score++;
		}
	}
	
}


