#pragma once
#include "NonComponentGameObject.h"
#include "Component.h"
#include "LogWriter.h"
#include <vector>
#include <typeinfo.h>

class GameObject : public NonComponentGameObject {
public:
	GameObject();
	~GameObject();

	template<typename T>
	Component* GetComponent(T* t) {
		//��������Component�^�Ȃ̂����`�F�b�N����
		Component* cast_t = dynamic_cast<Component*>(t);
		//�����̓R���|�[�l���g�ł���
		if (cast_t != NULL) {
			for (unsigned int i = 0; i < components.size(); i++) {
				Component* checkComponent = dynamic_cast<T*>(components[i]);
				if (checkComponent != NULL) {
					//����Ɍ�������
					return components[i];
				}
			}
			//�����̓R���|�[�l���g��������������Ȃ�����
			return nullptr;
		} else {
			//�������R���|�[�l���g����Ȃ�����
			return nullptr;
		}
	}

	//[�񐄏�]�@�R���|�[�l���g���擾���܂��Bnum=�ォ�琔�����R���|�[�l���g�̐��B
	Component* GetComponent(unsigned int num);

	//�R���|�[�l���g���ǂꂾ���A�^�b�`����Ă��邩���J�E���g���܂��B
	unsigned int GetComponentCount();

	void AddComponent(Component* component);

	template<typename T>
	void RemoveComponent(T* t) {
		Component* cast_t = dynamic_cast<Component*>(t);
		if (cast_t != NULL) {
			for (unsigned int i = 0; i < components.size(); i++) {
				Component* checkComponent = dynamic_cast<T*>(components[i]);
				if (checkComponent != NULL) {
					//����Ɍ�������
					components.erase(components.begin() + i);
					return;
				}
			}
			//�����̓R���|�[�l���g��������������Ȃ�����
			return;
		} else {
			//�������R���|�[�l���g����Ȃ�����
			return;
		}
	
	}

protected:
	vector<Component*> components;

};
