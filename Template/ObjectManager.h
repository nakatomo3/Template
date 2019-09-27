#pragma once
using namespace std;
#include "GameObject.h"
#include "Singleton.h"
#include<vector>
class GameObject;
class ObjectManager : public Singleton<ObjectManager> {
public:
	friend class Singleton<ObjectManager>;

	//オブジェクトマネージャーに登録する。管理対象でないと自動的にStartもUpdateも呼ばれない。
	void Instantiate(GameObject* instance);

	//管理対象から外し、オブジェクトを削除する
	void Destroy(GameObject* instance);

	void Awake();
	void Start();
	void FirstUpdate();
	void Update();
	void LateUpdate();

	void Draw();
	void LateDraw();

private:

	ObjectManager();
	~ObjectManager() {
		int size = objects.size();
		for (unsigned int i = 0; i < size; i++) {
			GameObject* deleteObj = objects.front();
			objects.erase(objects.begin());
			delete deleteObj;
		}
	}
	
	vector<GameObject*> objects;
	
};