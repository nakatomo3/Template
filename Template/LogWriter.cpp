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
	printf("ログライターが初期化されました\n");
	
	if (IS_CREATE_FILE) {
		time_t timer = time(NULL); //時刻を取得する
		struct tm *local = localtime(&timer); //現在地時刻に変換する

		_mkdir("Logs"); //Logフォルダを作成する
		char folder[FOLDER_NAME_LENGTH];
		sprintf(folder, "Logs/%04d%02d%02d", local->tm_year + 1900, local->tm_mon+1, local->tm_mday); //作成するフォルダの名前を年月日で決定する
		_mkdir(folder); //年月日フォルダを作成する
		char path[PATH_LENGTH];
		sprintf(path, "Logs/%04d%02d%02d/%02d_%02d_%02d.txt", local->tm_year + 1900, local->tm_mon+1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec); //パス込みのファイル名を設定する
		file = fopen(path, "w");
		/*if (file != NULL) {
			printf("生成しました");
		} else {
			printf("生成できませんでした");
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