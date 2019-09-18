#pragma once
using namespace std;
#include "Object.h"
#include "Vector3.h"
#include <vector>
#include <string>

class NonComponentGameObject : public Object {
public:

	//�I�u�W�F�N�g�̍��W���擾���܂�
	Vector3 GetPosition();
	//�I�u�W�F�N�g�̍��W��ݒ肵�܂�
	void SetPosition(Vector3 newPos);

	//�e�Ƃ̑��΍��W���擾���܂�
	Vector3 GetLocalPosition();
	//�e�Ƃ̑��΍��W��ݒ肵�܂�
	void SetLocalPosition(Vector3 newPos);

	//���݂̑傫�����擾���܂�
	Vector3 GetScale();
	//�傫����ݒ肵�܂�
	void SetScale(Vector3 newScale);

	//���݂̉�]���擾���܂�
	Vector3 GetRotation();
	//��]�p�x��ݒ肵�܂�
	void SetRotation(Vector3 newRotation);

	//���̃I�u�W�F�N�g���̂̊g�嗦���擾���܂�
	Vector3 GetLocalScale();
	//���̃I�u�W�F�N�g���̂̊g�嗦��ݒ肵�܂�
	void SetLocalScale(Vector3 newScale);

	//���݂̑��x���擾���܂�
	Vector3 GetVelocity();
	//���x��ݒ肵�܂�
	void SetVelocity(Vector3 newVelocity);

	//���̃I�u�W�F�N�g�̖��O���擾���܂�
	string GetName();
	//���̃I�u�W�F�N�g�̖��O��ݒ肵�܂�
	void SetName(string newName);

	//���̃I�u�W�F�N�g�̃^�O���擾���܂�
	string GetTag();
	//���̃I�u�W�F�N�g�Ƀ^�O��ݒ肵�܂�
	void SetTag(string newTag);
	//�^�O��target����v���Ă��邩��Ԃ��܂�
	bool CompareTag(string target);

	//�e�̃I�u�W�F�N�g���擾���܂�
	NonComponentGameObject* GetParent();
	//�e��ݒ肵�܂�
	void SetParent(NonComponentGameObject* parent);

	//index�Ԗڂ̎q���I�u�W�F�N�g���擾���܂�
	NonComponentGameObject* GetChild(int index);
	//�q���I�u�W�F�N�g�̐����擾���܂�
	int GetChildCount();
	//�q����ǉ����܂�
	void AddChild(NonComponentGameObject* child);

	//�I�u�W�F�N�g����]�����܂�
	void Rotate(Vector3 angle);

	void Move(Vector3 range);

	NonComponentGameObject();
	~NonComponentGameObject();

protected:
	bool isActive;

	Vector3 position;
	Vector3 localPosition;
	Vector3 scale;
	Vector3 localScale;
	Vector3 rotation;
	Vector3 velocity;

	string name;
	string tag;

	NonComponentGameObject* parent;
	vector<NonComponentGameObject*> child{};

};

