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
		printf("このクラスはシングルトンです。二つ以上作成しないでください");
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
