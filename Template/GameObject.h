#pragma once
using namespace std;
#include "OriginalHeaders.h"
#include <list>
class GameObject {
public:
	Vector3 position;
	Vector3 localPosition;
	Vector3 scale;
	Vector3 localScale;
	Vector3 rotation;
	Vector3 localRotation;

	GameObject* parent;
	list<GameObject> child;

	GameObject() {
		position = Vector3();
		localPosition = Vector3();
		scale = Vector3(1, 1, 1);
		localScale = Vector3(1, 1, 1);
		rotation = Vector3(0, 0, 0);
		localRotation = Vector3(0, 0, 0);
	}
	~GameObject() {

	}

	void Update() {

	}
};

