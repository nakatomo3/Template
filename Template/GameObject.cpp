#include "GameObject.h"



GameObject::GameObject() {
}

GameObject::~GameObject() {
	int size = components.size();
	for (int i = 0; i < size; i++) {
		Component* deleteComp = components.front();
		components.erase(components.begin());
		delete deleteComp;
	}
}

Component * GameObject::GetComponent(unsigned int num) {
	if (num >= components.size() || num < 0) {
		LogWriter::LogWorning("コンポーネントの取得に失敗しました。\nゲームオブジェクト名：%s\nコンポーネント引数：%d", name, num);
		return nullptr;
	}
	return components[num];
}

unsigned int GameObject::GetComponentCount() {
	return components.size();
}


void GameObject::AddComponent(Component * component) {
	components.emplace_back(component);
}

