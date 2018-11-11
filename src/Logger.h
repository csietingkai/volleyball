#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <string>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

using namespace std;
// add namespace you need

class Logger
{
	public:
		// constructors
		Logger(const string class_name);
		
		// public functions
		void init_logging();
		void trace(const string message);
		void debug(const string message);
		void info(const string message);
		void warning(const string message);
		void error(const string message);
		void fatal(const string message);
		

	private:
		// add any functions and variables you need
		string log_message;
};

#endif // LOGGER_H_
