#pragma once
#include "Singleton.h"
class SceneManager : public Singleton<SceneManager>{
public :
	friend class Singleton<SceneManager>;
private:
	SceneManager();
	~SceneManager();
};