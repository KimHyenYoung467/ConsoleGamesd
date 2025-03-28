#pragma once
#include "ConsoleRenderer.h"
#include "PlayScene.h"
#include "Input.h"
#include <iostream>
using namespace std; 

#define		NULLScene   (1 << 0)
#define 	MenuScene	(1 << 2)
#define		PlayScene	(1 << 1)
#define 	EndScene	(1 << 3) 

namespace SceneManager
{
	// ���� �߰� 
	void ScenePush(char scenecurrent);

	// ���� Ȯ�� 
	char SceneTypeCheck(char scenecurrent);

	// Ư�� ���� ���� 
	void SceneTypeDelete(char scenecurrent);
	
	// ���� ������ ���� �ϱ� 
	void ChangeScene(char scenecurrent);

	void SceneInit(); 
	void SceneUpdate(); 
	void SceneRender(); 
}
