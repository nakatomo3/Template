#pragma once
using namespace std;
#include "OriginalHeaders.h"
#include <vector>
#include <string>
class GameObject {
public:

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

	//[�񐄏�]������g�킸��ObjectManager��Instantiate���g���ď��������Ă�������
	GameObject();
	//[�񐄏�]������g�킸��ObjectManager��Destroy���g���ď��������Ă�������
	~GameObject();

	//�I�u�W�F�N�g�̃A�N�e�B�u��؂�ւ��܂�
	void SetActive(bool);
	//�I�u�W�F�N�g�̃A�N�e�B�u���擾���܂�
	bool GetActive();

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
	GameObject* GetParent();
	//�e��ݒ肵�܂�
	void SetParent(GameObject* parent);

	//index�Ԗڂ̎q���I�u�W�F�N�g���擾���܂�
	GameObject* GetChild(int index);
	//�q���I�u�W�F�N�g�̐����擾���܂�
	int GetChildCount();
	//�q����ǉ����܂�
	void AddChild(GameObject* child);


	//�I�u�W�F�N�g����]�����܂�
	void Rotate(Vector3 angle);

	void Move(Vector3 range);

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

	GameObject* parent;
	vector<GameObject*> child;
};

