#pragma once
#include "Singleton.h"
#include <Windows.h>
#include <mmsystem.h>
#include <time.h>

class Time : public Singleton<Time> {
public:
	friend class Singleton<Time>;
	
	int GetFPS();
	bool IsUpdate();

	//1�t���[���O�Ƃ̎��Ԃ̍����擾����
	double GetDeltaTime();

	int GetFrameFromStart();


	//���Ԃ�����鑬����ύX����
	 void SetTimeSpeed(float speed);
	//���Ԃ�����鑬�����擾����
	float GetTimeSpeed();

private :
	float FPS;
	float timeSpeed;
	
	double deltaTime;

	int frameCount;
	
	LARGE_INTEGER m_Counter;
	LONGLONG beforeFrameClock;
	double clocksPerSecond;

	double interval;


	Time();
	~Time();

};