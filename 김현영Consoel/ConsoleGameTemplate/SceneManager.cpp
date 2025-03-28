#include "SceneManager.h"



char SceneMemory = 0; // 0으로 꺼짐 상태로 초기화 

static char SceneCurrent = 0;
static char NextScene = 0;

char GetSceneCurrent(char scenecurrent) { return SceneCurrent = scenecurrent; };
char GetNextScene(char nextscene) { return NextScene = nextscene; };

bool g_bQuit;

// 상태 추가 
void SceneManager::ScenePush(char scenecurrent)
{
	// 비어있는 상태일 때 반환. 
	if (SceneCurrent & NULLScene) return; 

	// 파라메터로 받은 씬 값이 가져온 현재 씬 값과 같을 때 저장한다.  
	if (scenecurrent == GetSceneCurrent(SceneCurrent))
	{
		SceneMemory |= scenecurrent;
	}
}

// 씬 현재 상태 확인
char SceneManager::SceneTypeCheck(char scenecurrent)
{
	if (scenecurrent == (SceneMemory & NULLScene))
	{
		cout << "SceneNULL" << endl; 
		SceneTypeDelete(scenecurrent);
		return 0; 
	}
	if (scenecurrent == (SceneMemory & MenuScene))
	{
		return scenecurrent; 

	}
	if (scenecurrent == (SceneMemory & PlayScene))
	{
		cout << "플레이씬 입니다." << endl;
		return scenecurrent;
	}
	if (scenecurrent == (SceneMemory & EndScene))
	{
		cout << "엔딩씬 입니다." << endl;
		return scenecurrent;
	}
	
}

// 특정 상태 제거 
void SceneManager::SceneTypeDelete(char scenecurrent)	
{
	// 파라메터로 받은 씬 값이 가져온 현재 씬 값과 같을 때 삭제한다. 
	if (scenecurrent == (SceneMemory & MenuScene) || 
						(SceneMemory & NULLScene) ||
						(SceneMemory & PlayScene) ||
						(SceneMemory & EndScene))
	{
		SceneMemory &= ~scenecurrent; 
	}
}

// 현재 씬을 받아와서 현재씬으로 변경해 출력 하기 
void SceneManager::ChangeScene(char scenecurrent)
{

	// 만약에 현재 씬이 아니라면, 
	if (!scenecurrent == SceneTypeCheck(SceneCurrent))
		return; 

	// 씬에 맞는 렌더 함수 출력을 위해 현재 씬을 변경 
	if (scenecurrent == SceneTypeCheck(SceneCurrent))
	{
		SceneCurrent = scenecurrent; 
	}
}

// 현재 씬 및 다음 씬 생성 및 지정 (초기화) 
void SceneManager::SceneInit()
{
	// 맨 초기 현재 씬 값을 메뉴 씬으로 초기화 
	// 콘솔창 진입 시에 메뉴 씬으로 바로 접속하기 위함.
	char SceneCurrent = MenuScene;
	// 현재 씬이 메뉴이니, 다음 씬은 플레이 씬으로 초기화 
	char NextScene = PlayScene;

	// 씬 상태값을 저장하는 메모리 역할인 SceneMemory 에 저장 
	ScenePush(SceneCurrent); 

	// 이후, 현재 상태 값을 검사하여 계속 씬 변화를 업데이트 시켜준다. 
}

// 현재 상태에 따라서 현재 씬과 다음 씬을 업데이트 한다. 
void SceneManager::SceneUpdate()
{
	void ProcessInput();
	
	// 현재씬이 아니게 될 때까지 반복해서 업데이트 한다. 
	while (!SceneCurrent)
	{
		// 현재 씬의 상태를 체크한다. 
		SceneTypeCheck(SceneCurrent);
		// 현재 씬이 널 씬일 때 삭제 
		if (SceneCurrent == (SceneMemory & NULLScene))
		{
			SceneTypeDelete(SceneCurrent);
		}
		// 씬메모리 안에 현재 씬인지 검사 하고, 나가기가 활성화되었다면 ,
		if ((SceneMemory & SceneCurrent) && g_bQuit == true)
		{
			// 엔딩씬을 저장하고, 변경한다. 
			ScenePush(GetSceneCurrent(EndScene));
		}
	}
	
	
	
	// 현재 씬일 때,
	g_bQuit = false;
}

// 업데이트 되는 씬들을 모아서 출력한다. 
void SceneManager::SceneRender()
{
	ConsoleRender::ScreenClear();

	if (SceneCurrent == (SceneMemory & NULLScene))
	{
		cout << "SceneNULL" << endl;
		SceneTypeDelete(SceneCurrent);
		return;
	}
	if (SceneCurrent == (SceneMemory & MenuScene))
	{

	}
	if (SceneCurrent == (SceneMemory & PlayScene))
	{
		cout << "플레이씬 입니다." << endl;
		PLAY::PlayRender();
	}
	if (SceneCurrent == (SceneMemory & EndScene))
	{
		cout << "엔딩씬 입니다." << endl;
	}
}
