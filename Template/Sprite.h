#pragma once
#include "OriginalHeaders.h"
class Sprite : public GameObject {
public:
	Sprite();
	Sprite(Vector2 position);
	Sprite(Vector3 position);
	Sprite(Vector2 position, GameObject parent);
	Sprite(Vector3 position, GameObject parent);


	~Sprite();
};

