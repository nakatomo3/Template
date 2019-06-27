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
	printf("Timeが初期化されました");
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
	QueryPerformanceCounter(&m_Counter);                     // 現在の時刻を取得し、
	LONGLONG LongDef = m_Counter.QuadPart - beforeFrameClock;    // 差分カウント数を算出する。
	double dDef = (double)LongDef;                             // 倍精度浮動小数点に変換
	beforeFrameClock = m_Counter.QuadPart;                       // 現在の時刻を保持

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

