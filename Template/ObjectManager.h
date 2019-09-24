#pragma once
using namespace std;
#include "GameObject.h"
#include "Singleton.h"
#include<vector>
class GameObject;
class ObjectManager : public Singleton<ObjectManager> {
public:
	friend class Singleton<ObjectManager>;

	//�I�u�W�F�N�g�}�l�[�W���[�ɓo�^����B�Ǘ��ΏۂłȂ��Ǝ����I��Start��Update���Ă΂�Ȃ��B
	void Instantiate(GameObject* instance);

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

	}
	
	vector<GameObject*> objects;
	
};