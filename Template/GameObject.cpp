#include "GameObject.h"
GameObject::GameObject() {
	position = Vector3(0,0,0);
	localPosition = Vector3(0,0,0);
	scale = Vector3(1, 1, 1);
	localScale = Vector3(1, 1, 1);
	rotation = Vector3(0, 0, 0);
	velocity = Vector3(0,0,0);
	printf("生成されました\n");
}

GameObject::~GameObject() {
	int childSize = child.size();
	printf("子供の数：%d\n", childSize);
	for (int i = 0; i < childSize; i++) {
		delete child[i];
	}
	printf("ゲームオブジェクトを削除しました\n");
}

void GameObject::Awake() {

}

void GameObject::Start() {

}

void GameObject::FirstUpdate() {

}

void GameObject::Update() {

}

void GameObject::LateUpdate() {

}



void GameObject::SetActive(bool _isActive) {
	isActive = _isActive;
}

bool GameObject::GetActive() {
	return isActive;
}

Vector3 GameObject::GetPosition() {
	return position;
}

void GameObject::SetPosition(Vector3 newPos) {
	position = newPos;
}

Vector3 GameObject::GetLocalPosition() {
	return localPosition;
}

void GameObject::SetLocalPosition(Vector3 newPos) {
	localPosition = newPos;
}

Vector3 GameObject::GetScale() {
	return scale;
}

void GameObject::SetScale(Vector3 newScale) {
	scale = newScale;
}

Vector3 GameObject::GetRotation() {
	return rotation;
}

void GameObject::SetRotation(Vector3 newRotation) {
	rotation = newRotation;
}

Vector3 GameObject::GetLocalScale() {
	return localScale;
}

void GameObject::SetLocalScale(Vector3 newScale) {
	localScale = newScale;
}

void GameObject::SetVelocity(Vector3 newVelocity) {
	velocity = newVelocity;
}

Vector3 GameObject::GetVelocity() {
	return velocity;
}

string GameObject::GetName() {
	return name;
}

void GameObject::SetName(string newName) {
	name = newName;
}

string GameObject::GetTag() {
	return tag;
}

void GameObject::SetTag(string newTag) {
	tag = newTag;
}

bool GameObject::CompareTag(string target) {
	return tag == target;
}

GameObject* GameObject::GetParent() {
	return parent;
}

void GameObject::SetParent(GameObject * newParent) {
	parent = newParent;
}

GameObject* GameObject::GetChild(int index) {
	if (index >= GetChildCount()) {
		return nullptr;
	}
	return child[index];
}

int GameObject::GetChildCount() {
	return child.size();
}

void GameObject::AddChild(GameObject * newChild) {
	child.push_back(newChild);
}

void GameObject::Rotate(Vector3 angle) {
	for (int i = 0; i < GetChildCount(); i++) {

	}
}

void GameObject::Move(Vector3 range) {
	for (int i = 0; i < GetChildCount(); i++) {
		GetChild(i)->Move(range);
	}
	SetPosition(position + range);
}