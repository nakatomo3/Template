#pragma once
using namespace std;
#include <list>
#include "Singleton.h"
class ObjectManager : public Singleton<ObjectManager> {
public:
	friend class Singleton<ObjectManager>;

private:

	ObjectManager() {
		printf("オブジェクトマネージャーが初期化されました");
	}
	~ObjectManager() {

	}
};

