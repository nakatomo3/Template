#include "Singleton.h"
#include<stdio.h>

Singleton *Singleton::s_pInstance = NULL;

// Create
bool Singleton::Create() {
	bool isSuccess = false;
	if (!s_pInstance) {
		s_pInstance = new Singleton;
		isSuccess = true;
	} else {
		printf("���̃N���X�̓V���O���g���ł��B��ȏ�쐬���Ȃ��ł�������");
		isSuccess = false;
	}
	return isSuccess;
}

// Destroy
bool Singleton::Destroy() {
	delete s_pInstance;
	s_pInstance = NULL;
	return true;
}
Singleton::Singleton() {

}
