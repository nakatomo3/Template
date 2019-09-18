#pragma once
using namespace std;
#include <string>
#include "Singleton.h"
class LogWriter : public Singleton<LogWriter> {
public:
	friend class Singleton<LogWriter>;

	static void Log(const char*, ...);
	static void LogWorning(const char* format, ...);
	static void LogError(const char * format, ...);

private:
	LogWriter();
	~LogWriter();
};