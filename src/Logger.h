#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
// add #include <library you need>

using namespace std;
// add namespace you need

class Logger
{
	public:
		// constructors
		Logger(const string class_name);
		
		// public functions
		void trace(const string message);
		void debug(const string message);
		void info(const string message);
		void warning(const string message);
		void error(const string message);
		void fatal(const string message);
		
	private:
		// add any functions and variables you need
};

#endif // LOGGER_H_
