#include "Time.h"
#include <timeapi.h>
#include "LogWriter.h"
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
	LogWriter::GetInstance().Log("Time������������܂���");
}


Time::~Time() {

}

int Time::GetFPS() {
	return (int)FPS;
}

double Time::GetDeltaTime() {
	return deltaTime;
}

int Time::GetFrameFromStart() {
	return frameCount;
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

	frameCount++;

	return true;
}

void Time::SetTimeSpeed(float speed) {
	if (speed < 0) {
		LogWriter::GetInstance().LogError("ChangeTimeSpeed��%f��ݒ肵�܂����B�}�C�i�X�̐����͓��͂��Ȃ��ł�������",speed);
		return;
	}
	timeSpeed = speed;
}

float Time::GetTimeSpeed() {
	return timeSpeed;
}
