#pragma once
#include "Singleton.h"
#include <Windows.h>
#include <mmsystem.h>
#include <time.h>

class Time : public Singleton<Time> {
public:
	friend class Singleton<Time>;

	Time();
	~Time();
	
	int GetFPS();
	bool IsUpdate();
	double GetDeltaTime();

	//時間が流れる速さを変更する
	void ChangeTimeSpeed(float speed);
private :
	float FPS;
	float timeSpeed;
	
	double deltaTime;

	int frameCount;
	
	LARGE_INTEGER m_Counter;
	LONGLONG beforeFrameClock;
	double clocksPerSecond;

	double interval;

};

