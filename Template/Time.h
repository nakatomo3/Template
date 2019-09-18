#pragma once
#include "Singleton.h"
#include <Windows.h>
#include <mmsystem.h>
#include <time.h>

class Time : public Singleton<Time> {
public:
	friend class Singleton<Time>;
	
	//���݂�FPS���擾���܂�
	int GetFPS();
	//�����݃A�b�v�f�[�g�o���邩���擾���܂�(�ݒ�FPS�𒴂��Ȃ��悤�ɂ��Ă��܂�)
	bool IsUpdate();

	//1�t���[���O�Ƃ̎��Ԃ̍����擾���܂�
	double GetDeltaTime();

	//�X�^�[�g���Ă���̃t���[�������擾���܂�
	int GetFrameFromStart();

	//�X�^�[�g���Ă���̎��Ԃ��擾���܂�
	float GetTimeFromStart();

	//���Ԃ�����鑬����ύX���܂�
	 void SetTimeSpeed(float speed);
	//���Ԃ�����鑬�����擾���܂�
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