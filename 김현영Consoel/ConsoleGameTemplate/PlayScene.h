#pragma once
#include "SceneManager.h"
#include "ConsoleRenderer.h"
#include "Time.h"
#include "Input.h"

struct Score
{
	int score;
	const int SCORE_X;
	const int SCORE_Y;

};

struct MapSize
{
	const int MAP_X; 
	const int MAP_Y; 
};


namespace PLAY
{	
	
	
	void PlayInit();	// 플레이 씬 초기화 함수 
	void PlayUpdate();  // 플레이 씬 업데이트 함수 
	void PlayRender();  // 플레이 씬 렌더링 함수 

	// 플레이 중 계속 업데이트되야 하는 함수들 
	void RandomScore(); // 스코어 아이템을 렌덤으로 나타나게 만든다. 
	void ScoreActCheck(); // 스코어 활성화 여부 체크 
	void ScoreCheck();  // 스코어 점수를 체크 한다. 
	void Score();		// 스코어 점수의 증감
}