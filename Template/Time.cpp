#include "Time.h"
#include <timeapi.h>
#pragma comment(lib, "winmm.lib")
#define DEFAULT_FPS (30.0)
double clockPerSecond;

Time::Time() {
	FPS = DEFAULT_FPS;
	frameCount = 0;
	LARGE_INTEGER Freq;
	clockPerSecond = QueryPerformanceFrequency(&Freq);
	clocksPerSecond = (double)Freq.QuadPart;
	QueryPerformanceCounter(&m_Counter);
	beforeFrameClock = m_Counter.QuadPart;
	printf("Time������������܂���");
}


Time::~Time() {

}

int Time::GetFPS() {
	return (int)FPS;
}

double Time::GetDeltaTime() {
	return deltaTime;
}

bool Time::IsUpdate() {
	QueryPerformanceCounter(&m_Counter);                     // ���݂̎������擾���A
	LONGLONG LongDef = m_Counter.QuadPart - beforeFrameClock;    // �����J�E���g�����Z�o����B
	double dDef = (double)LongDef;                             // �{���x���������_�ɕϊ�
	beforeFrameClock = m_Counter.QuadPart;                       // ���݂̎�����ێ�

	interval += dDef / clocksPerSecond;

	if (interval < 1.0 / FPS) {
		return false;
	}
	deltaTime = interval;
	interval = 0;
	return true;
}

void Time::ChangeTimeSpeed(float speed) {

}

