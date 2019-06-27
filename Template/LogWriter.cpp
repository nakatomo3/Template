#define _CRT_SECURE_NO_WARNINGS
#include "LogWriter.h"
#include <stdio.h>
#include <time.h>
#include <direct.h>
#include<Windows.h>

#define FOLDER_NAME_LENGTH (15)
#define FILE_NAME_LENGTH (13)
#define PATH_LENGTH (FOLDER_NAME_LENGTH + FILE_NAME_LENGTH)

#define IS_CREATE_FILE true

FILE* file;
LogWriter::LogWriter() {
	printf("���O���C�^�[������������܂���\n");
	
	if (IS_CREATE_FILE) {
		time_t timer = time(NULL); //�������擾����
		struct tm *local = localtime(&timer); //���ݒn�����ɕϊ�����

		_mkdir("Logs"); //Log�t�H���_���쐬����
		char folder[FOLDER_NAME_LENGTH];
		sprintf(folder, "Logs/%04d%02d%02d", local->tm_year + 1900, local->tm_mon+1, local->tm_mday); //�쐬����t�H���_�̖��O��N�����Ō��肷��
		_mkdir(folder); //�N�����t�H���_���쐬����
		char path[PATH_LENGTH];
		sprintf(path, "Logs/%04d%02d%02d/%02d_%02d_%02d.txt", local->tm_year + 1900, local->tm_mon+1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec); //�p�X���݂̃t�@�C������ݒ肷��
		file = fopen(path, "w");
		/*if (file != NULL) {
			printf("�������܂���");
		} else {
			printf("�����ł��܂���ł���");
		}*/
	}
}


LogWriter::~LogWriter() {
	if (IS_CREATE_FILE) {
		fclose(file);
	}
}

void LogWriter::Log(const char* format, ...) {
	if (IS_CREATE_FILE) {
		fprintf(file, "[ ] ");
		va_list argp;
		va_start(argp, format);
		vfprintf(file, format, argp);
		va_end(argp);
		fprintf(file, "\n");
	}
}

void LogWriter::LogWorning(const char* format, ...) {
	if (IS_CREATE_FILE) {
		fprintf(file, "[-] ");
		va_list argp;
		va_start(argp, format);
		vfprintf(file, format, argp);
		va_end(argp);
		fprintf(file, "\n");
	}
}

void LogWriter::LogError(const char* format, ...) {
	if (IS_CREATE_FILE) {
		fprintf(file, "[!] ");
		va_list argp;
		va_start(argp, format);
		vfprintf(file,format,argp);
		va_end(argp);
		fprintf(file, "\n");
	}
}