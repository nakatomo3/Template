#pragma once
#include "GameObject.h"
#include "Component.h"
class ScriptBase : public Component{
public:
	ScriptBase();
	ScriptBase(GameObject* gameObject);
	~ScriptBase();

	//�������ꂽ�Ƃ��Ɉ�ԍŏ��ɌĂяo����܂��BStart�֐�������ɌĂяo����܂�
	virtual void Awake();
	//�������ꂽ�Ƃ��ɌĂяo����܂��BAwake�֐�������ɌĂяo����܂��B
	virtual void Start();
	//�ŏ��ɌĂяo�����Update�ł��B
	virtual void FirstUpdate();
	//�ʏ�Ăяo�����Update�ł��B
	virtual void Update();
	//�Ō�ɌĂяo�����Update�ł��B
	virtual void LateUpdate();

protected:

private:

};