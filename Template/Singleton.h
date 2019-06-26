#pragma once
#include<string>
#include <map>
class Singleton {
public:
	static Singleton *GetInstance() {
		return s_pInstance;
	}

	static bool Create();
	static bool Destroy();

protected:
	static Singleton *s_pInstance;
	Singleton(); // 隠しコンストラクタ
};