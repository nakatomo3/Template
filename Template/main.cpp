#include "main.h"

#include <stdio.h>
#include"Vector3.h"
#include"Vector2.h"
#include"ObjectManager.h"
#include"SceneManager.h"
#include"Singleton.h"
#include"SaveManager.h"
#include"LogWriter.h"
#include"Time.h"
#include"Color.h"
#include"Object.h"
#include"Component.h"
#include"ScriptBase.h"
#include"GameObject.h"

int main(void) {
	Init();

	while (true){
		if(Time::GetInstance().IsUpdate()){
			Update();
			Draw();
		}
	}

	return 0;
}

void Init(){
	SaveManager::GetInstance();
	ObjectManager::GetInstance();
	SceneManager::GetInstance();
	LogWriter::GetInstance();
	
	GameObject* obj = new GameObject();
	ObjectManager::GetInstance().Instantiate(obj);

	sampleComponent* samp = new sampleComponent();
	obj->AddComponent(samp);
	
	//ーーーーーー初期化はここまでに入力ーーーーーーーーー

	ObjectManager::GetInstance().Awake();
	ObjectManager::GetInstance().Start();
}

void Uninit() {

}

void Update() {
	ObjectManager::GetInstance().FirstUpdate();
	ObjectManager::GetInstance().Update();
	ObjectManager::GetInstance().LateUpdate();
}

void Draw() {

}