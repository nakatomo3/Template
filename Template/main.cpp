#include "main.h"

int main(void) {

	Init();

	while (true){
		if(Time::GetInstance().IsUpdate()){
			Update();
			Draw();
		}
	}


	getchar();
	return 0;
}

void Init(){
	SaveManager::GetInstance();
	ObjectManager::GetInstance();
	SceneManager::GetInstance();
	LogWriter::GetInstance();
	Time::GetInstance();
}

void Update() {
	
}

void Draw() {

}