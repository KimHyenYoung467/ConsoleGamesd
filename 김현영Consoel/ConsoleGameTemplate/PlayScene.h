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
	
	
	void PlayInit();	// �÷��� �� �ʱ�ȭ �Լ� 
	void PlayUpdate();  // �÷��� �� ������Ʈ �Լ� 
	void PlayRender();  // �÷��� �� ������ �Լ� 

	// �÷��� �� ��� ������Ʈ�Ǿ� �ϴ� �Լ��� 
	void RandomScore(); // ���ھ� �������� �������� ��Ÿ���� �����. 
	void ScoreActCheck(); // ���ھ� Ȱ��ȭ ���� üũ 
	void ScoreCheck();  // ���ھ� ������ üũ �Ѵ�. 
	void Score();		// ���ھ� ������ ����
}