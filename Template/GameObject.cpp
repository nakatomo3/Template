#include "GameObject.h"



GameObject::GameObject() {
}


GameObject::~GameObject() {
}

Component * GameObject::GetComponent(unsigned int num) {
	if (num >= components.size() || num < 0) {
		LogWriter::LogWorning("�R���|�[�l���g�̎擾�Ɏ��s���܂����B\n�Q�[���I�u�W�F�N�g���F%s\n�R���|�[�l���g�����F%d", name, num);
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
