#pragma once
#include "NonComponentGameObject.h"
#include "Object.h"

class Component : public Object {
public:
	Component();
	~Component();

	//GameObject��e�ɂ��������A���ꂾ�ƕςɂȂ��Ă��܂��̂ŁA����������̊��N���X���Q�ƁBWIP
	NonComponentGameObject* gameObject;


	//�������̈�ԍŏ��Ɏg�p�B
	virtual void Awake() {

	}


	//��ʓI�ȏ������Ɏg�p�B
	virtual void Start() {
		
	}

	//��ԍŏ��̖��t���[�����Ƃ̍X�V�Ɏg�p�B
	virtual void FirstUpdate() {

	}

	//��ʓI�Ȗ��t���[�����Ƃ̍X�V�Ɏg�p�B
	virtual void Update() {

	}

	//��ԍŌ�̖��t���[�����Ƃ̍X�V�Ɏg�p�B
	virtual void LateUpdate() {

	}

};

class sampleComponent : public Component {
public :
	sampleComponent() {};
	~sampleComponent() {};

	void Awake() {

	}

	void Start() {

	}

	void FirstUpdate() {

	}

	void Update() {

	}

	void LateUpdate() {

	}
};