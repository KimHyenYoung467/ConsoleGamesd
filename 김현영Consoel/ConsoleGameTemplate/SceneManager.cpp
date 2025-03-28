#include "SceneManager.h"



char SceneMemory = 0; // 0���� ���� ���·� �ʱ�ȭ 

static char SceneCurrent = 0;
static char NextScene = 0;

char GetSceneCurrent(char scenecurrent) { return SceneCurrent = scenecurrent; };
char GetNextScene(char nextscene) { return NextScene = nextscene; };

bool g_bQuit;

// ���� �߰� 
void SceneManager::ScenePush(char scenecurrent)
{
	// ����ִ� ������ �� ��ȯ. 
	if (SceneCurrent & NULLScene) return; 

	// �Ķ���ͷ� ���� �� ���� ������ ���� �� ���� ���� �� �����Ѵ�.  
	if (scenecurrent == GetSceneCurrent(SceneCurrent))
	{
		SceneMemory |= scenecurrent;
	}
}

// �� ���� ���� Ȯ��
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
		cout << "�÷��̾� �Դϴ�." << endl;
		return scenecurrent;
	}
	if (scenecurrent == (SceneMemory & EndScene))
	{
		cout << "������ �Դϴ�." << endl;
		return scenecurrent;
	}
	
}

// Ư�� ���� ���� 
void SceneManager::SceneTypeDelete(char scenecurrent)	
{
	// �Ķ���ͷ� ���� �� ���� ������ ���� �� ���� ���� �� �����Ѵ�. 
	if (scenecurrent == (SceneMemory & MenuScene) || 
						(SceneMemory & NULLScene) ||
						(SceneMemory & PlayScene) ||
						(SceneMemory & EndScene))
	{
		SceneMemory &= ~scenecurrent; 
	}
}

// ���� ���� �޾ƿͼ� ��������� ������ ��� �ϱ� 
void SceneManager::ChangeScene(char scenecurrent)
{

	// ���࿡ ���� ���� �ƴ϶��, 
	if (!scenecurrent == SceneTypeCheck(SceneCurrent))
		return; 

	// ���� �´� ���� �Լ� ����� ���� ���� ���� ���� 
	if (scenecurrent == SceneTypeCheck(SceneCurrent))
	{
		SceneCurrent = scenecurrent; 
	}
}

// ���� �� �� ���� �� ���� �� ���� (�ʱ�ȭ) 
void SceneManager::SceneInit()
{
	// �� �ʱ� ���� �� ���� �޴� ������ �ʱ�ȭ 
	// �ܼ�â ���� �ÿ� �޴� ������ �ٷ� �����ϱ� ����.
	char SceneCurrent = MenuScene;
	// ���� ���� �޴��̴�, ���� ���� �÷��� ������ �ʱ�ȭ 
	char NextScene = PlayScene;

	// �� ���°��� �����ϴ� �޸� ������ SceneMemory �� ���� 
	ScenePush(SceneCurrent); 

	// ����, ���� ���� ���� �˻��Ͽ� ��� �� ��ȭ�� ������Ʈ �����ش�. 
}

// ���� ���¿� ���� ���� ���� ���� ���� ������Ʈ �Ѵ�. 
void SceneManager::SceneUpdate()
{
	void ProcessInput();
	
	// ������� �ƴϰ� �� ������ �ݺ��ؼ� ������Ʈ �Ѵ�. 
	while (!SceneCurrent)
	{
		// ���� ���� ���¸� üũ�Ѵ�. 
		SceneTypeCheck(SceneCurrent);
		// ���� ���� �� ���� �� ���� 
		if (SceneCurrent == (SceneMemory & NULLScene))
		{
			SceneTypeDelete(SceneCurrent);
		}
		// ���޸� �ȿ� ���� ������ �˻� �ϰ�, �����Ⱑ Ȱ��ȭ�Ǿ��ٸ� ,
		if ((SceneMemory & SceneCurrent) && g_bQuit == true)
		{
			// �������� �����ϰ�, �����Ѵ�. 
			ScenePush(GetSceneCurrent(EndScene));
		}
	}
	
	
	
	// ���� ���� ��,
	g_bQuit = false;
}

// ������Ʈ �Ǵ� ������ ��Ƽ� ����Ѵ�. 
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
		cout << "�÷��̾� �Դϴ�." << endl;
		PLAY::PlayRender();
	}
	if (SceneCurrent == (SceneMemory & EndScene))
	{
		cout << "������ �Դϴ�." << endl;
	}
}
