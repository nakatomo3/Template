#include "SaveManager.h"

static const int NAME_LEN_MAX;

map<string, int>    intSaves;
map<int, string>    intKeys;

map<string, float>  floatSaves;
map<int,string>     floatKeys;

map<string, string> stringSaves;
map<int,string>     stringKeys;

enum CLASS_ID {
	INT = 0,
	FLOAT = 1,
	STRING = 2,
	LAST
};

SaveManager::SaveManager() {
	printf("�Z�[�u�}�l�[�W���[������������܂���\n");
}

SaveManager::~SaveManager() {

}

//�Z�[�u�������������ǂ���
bool SaveManager::SaveAll(const char* fileName) {
	bool isSuccess = true;
	FILE* file = fopen(fileName, "wb");
	if (file == NULL) {
		printf("�t�@�C����������܂���ł����̂ŁA�V�K�쐬���܂���\n");
		file = fopen(fileName, "w");
		file = fopen(fileName, "wb");
	}

	int saveCount;
	saveCount = intKeys.size() + floatKeys.size() + stringKeys.size();
	fwrite(&saveCount, sizeof(int), 1, file);

	for (unsigned int i = 0; i < intKeys.size(); i++) {
		const int classID = INT;
		const int size = intKeys[i].length();
		fwrite(&classID, sizeof(int), 1, file);
		fwrite(&size, sizeof(int), 1, file);
		for (unsigned int j = 0; j < intKeys[i].length(); j++) {
			fwrite(&intKeys[i][j],sizeof(char),1,file);
		}
		fwrite(&intSaves[intKeys[i]], sizeof(int), 1, file);
	}

	for (unsigned int i = 0; i < floatKeys.size(); i++) {
		const int classID = FLOAT;
		const int size = floatKeys[i].length();
		fwrite(&classID, sizeof(float), 1, file);
		fwrite(&size, sizeof(float), 1, file);
		for (unsigned int j = 0; j < floatKeys[i].length(); j++) {
			fwrite(&floatKeys[i][j], sizeof(char), 1, file);
		}
		fwrite(&floatSaves[floatKeys[i]], sizeof(float), 1, file);
	}

	

	if (isSuccess == true) {
		printf("�Z�[�u������Ɋ������܂���\n");
	}

	fclose(file);
	return isSuccess;
}

bool SaveManager::LoadAll(const char* fileName) {
	bool isSuccess = true;

	FILE* file = fopen(fileName, "rb");
	if (file == NULL) {
		printf("�t�@�C����������܂���ł����̂ŁA�V�K�쐬���܂���\n");
		file = fopen(fileName, "w");
		file = fopen(fileName, "rb");
		return false;
	}

	int saveCount;
	fread(&saveCount, sizeof(int), 1, file);
	for (int i = 0; i < saveCount; i++) {
		int classID;
		int size;
		fread(&classID, sizeof(int), 1, file);
		string name;
		switch (classID) {
			default:
				printf("CLASS_ID��o�^���Ă�������\n");
				isSuccess = false;
				break;
			case INT:
				fread(&size, sizeof(int), 1, file);
				for (int j = 0; j < size; j++) {
					char oneChar;
					fread(&oneChar, sizeof(char), 1, file);
					name += oneChar;
				}
				int intValue;
				fread(&intValue, sizeof(int), 1, file);
				intKeys[i] = name;
				intSaves[name] = intValue;
				break;
			case FLOAT:
				fread(&size, sizeof(int), 1, file);
				for (int j = 0; j < size; j++) {
					char oneChar;
					fread(&oneChar, sizeof(char), 1, file);
					name += oneChar;
				}
				float floatValue;
				fread(&floatValue, sizeof(float), 1, file);
				break;
			case STRING :
				
				break;
		}
	}


	if (isSuccess == true) {
		printf("���[�h������Ɋ������܂���\n");
	} else {
		printf("���[�h������Ɋ������܂���ł���\n");
	}
	fclose(file);
	return isSuccess;
}

template <class T>
void SaveManager::Save(char* fileName, T instance, string key) {

}


void SaveManager::AddInt(string key, int value) {
	if (intSaves[key] == NULL) {
		intKeys[intKeys.size()] = key;
	}
	intSaves[key] = value;
}

void SaveManager::AddFloat(string key, float value) {
	floatKeys[intKeys.size()] = key;
	if (floatSaves[key] == NULL) {
		floatKeys[floatSaves.size()] = key;
	}
	floatSaves[key] = value;
}

int SaveManager::GetInt(string key) {
	return intSaves[key];
}

int SaveManager::GetInt(string key, int defaultValue) {
	if (intSaves[key] == NULL) {
		return defaultValue;
	}
	return intSaves[key];
}

float SaveManager::GetFloat(string key) {
	return floatSaves[key];
}

float SaveManager::GetFloat(string key, float defaultValue) {
	if (floatSaves[key] == NULL) {
		return defaultValue;
	}
	return floatSaves[key];
}

//saveCount(int) {classID(int) saveNameSize(int) saveName(const char*) object<T>} {classID(int) saveNameSize(int) saveName(const char*) object}