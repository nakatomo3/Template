#include "SceneManager.h"
#include "LogWriter.h"

SceneManager::SceneManager() {
	LogWriter::GetInstance().Log("シーンマネージャーが初期化されました\n");
}

SceneManager::~SceneManager() {

}