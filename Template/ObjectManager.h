#pragma once
using namespace std;
#include <list>
#include "Singleton.h"
class ObjectManager : public Singleton<ObjectManager> {
public:
	friend class Singleton<ObjectManager>;

private:

	ObjectManager() {
		printf("�I�u�W�F�N�g�}�l�[�W���[������������܂���");
	}
	~ObjectManager() {

	}
};

