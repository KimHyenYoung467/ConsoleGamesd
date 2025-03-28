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
	// 상태 추가 
	void ScenePush(char scenecurrent);

	// 상태 확인 
	char SceneTypeCheck(char scenecurrent);

	// 특정 상태 제거 
	void SceneTypeDelete(char scenecurrent);
	
	// 현재 씬으로 변경 하기 
	void ChangeScene(char scenecurrent);

	void SceneInit(); 
	void SceneUpdate(); 
	void SceneRender(); 
}
