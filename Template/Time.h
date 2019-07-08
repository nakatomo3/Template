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

	//1フレーム前との時間の差を取得する
	double GetDeltaTime();

	int GetFrameFromStart();


	//時間が流れる速さを変更する
	 void SetTimeSpeed(float speed);
	//時間が流れる速さを取得する
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