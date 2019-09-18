#include "ObjectManager.h"
#include <list>
#include "LogWriter.h"


void ObjectManager::Instantiate(GameObject* instance) {
	objects.emplace_back(instance);
}

void ObjectManager::Awake() {
	for (unsigned int i = 0; i < objects.size(); i++) {
		for (unsigned int j = 0; j < objects[i]->GetComponentCount(); j++) {
			objects[i]->GetComponent(j)->Awake();
		}
	}
}

void ObjectManager::Start() {
	for (unsigned int i = 0; i < objects.size(); i++) {
		for (unsigned int j = 0; j < objects[i]->GetComponentCount(); j++) {
			objects[i]->GetComponent(j)->Start();
		}
	}
}

void ObjectManager::FirstUpdate() {
	for (unsigned int i = 0; i < objects.size(); i++) {
		for (unsigned int j = 0; j < objects[i]->GetComponentCount(); j++) {
			objects[i]->GetComponent(j)->FirstUpdate();
		}
	}
}

void ObjectManager::Update() {
	for (unsigned int i = 0; i < objects.size(); i++) {
		for (unsigned int j = 0; j < objects[i]->GetComponentCount(); j++) {
			objects[i]->GetComponent(j)->Update();
		}
	}
}

void ObjectManager::LateUpdate() {
	for (unsigned int i = 0; i < objects.size(); i++) {
		for (unsigned int j = 0; j < objects[i]->GetComponentCount(); j++) {
			objects[i]->GetComponent(j)->LateUpdate();
		}
	}
}

ObjectManager::ObjectManager() {
	LogWriter::Log("オブジェクトマネージャーが初期化されました");
}