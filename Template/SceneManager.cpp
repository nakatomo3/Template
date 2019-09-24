#include "SceneManager.h"
#include "LogWriter.h"

SceneManager::SceneManager() {
	LogWriter::GetInstance().Log("�V�[���}�l�[�W���[������������܂���\n");

}

SceneManager::~SceneManager() {

}

void SceneManager::LoadScene(Scene* scene) {
	scene->Load();
	scene->Start();
	nowScene = scene;
}

void SceneManager::LoadScene(string name) {
	for (int i = 0; i < sceneList.size(); i++) {
		if (sceneList[i]->name == name) {
			sceneList[i]->Load();
			sceneList[i]->Start();
			LogWriter::GetInstance().Log("%s�Ƃ����V�[����ǂݍ��݂܂���", name);
			nowScene = sceneList[i];
			return;
		}
	}
	LogWriter::GetInstance().LogWorning("%s�Ƃ����V�[���͑��݂��܂���ł���",name);
}

void SceneManager::LoadScene(unsigned int num) {
	if (sceneList.size() < num) {
		//�V�[�����X�g�̃T�C�Y�����傫���ꍇ�G���[
		LogWriter::GetInstance().LogWorning("%d�Ԗڂ̃V�[���͑��݂��܂���ł����B�V�[������%d�ł�", num, sceneList.size());
		return;
	}
	sceneList[num]->Load();
	sceneList[num]->Start();
	nowScene = sceneList[num];
}

void SceneManager::BackLoad(Scene * scene) {
	scene->Load();
}

void SceneManager::BackLoad(string name) {
	for (int i = 0; i < sceneList.size(); i++) {
		if (sceneList[i]->name == name) {
			sceneList[i]->Load();
		}
	}
	LogWriter::GetInstance().LogWorning("%s�Ƃ����V�[���͑��݂��܂���ł���", name);
	return;
}

void SceneManager::BackLoad(unsigned int num) {
	if (sceneList.size() < num) {
		LogWriter::GetInstance().LogWorning("%d�Ԗڂ̃V�[���͑��݂��܂���ł����B�V�[������%d�ł�", num, sceneList.size());
		return;
	}
	sceneList[num]->Load();
}

void SceneManager::UnLoad(Scene* scene) {
	scene->UnLoad();
}

Scene* SceneManager::GetScene(unsigned int num) {
	if (sceneList.size() < num) {
		LogWriter::GetInstance().LogWorning("%d�Ԗڂ̃V�[���͑��݂��܂���ł����B�V�[������%d�ł�", num, sceneList.size());
		return nullptr;
	}
	return sceneList[num];
}

Scene* SceneManager::GetScene(string name) {
	for (int i = 0; i < sceneList.size(); i++) {
		if (sceneList[i]->name == name) {
			return sceneList[i];
		}
	}
	LogWriter::GetInstance().LogWorning("%s�Ƃ����V�[���͑��݂��܂���ł���", name);
	return nullptr;
}

string SceneManager::GetSceneName(Scene * scene) {
	return scene->name;
}

string SceneManager::GetSceneName(unsigned int number) {
	return sceneList[number]->name;
}

void SceneManager::AddScene(Scene * scene) {
	sceneList.push_back(scene);
}

string SceneManager::GetNowScene() {
	return nowScene->name;
}

int SceneManager::GetNowSceneNumber() {
	return nowScene->sceneNumber;
}