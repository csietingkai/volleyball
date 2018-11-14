#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/severity_feature.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/serialization/shared_ptr.hpp> // for null_deleter
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>

using namespace std;
// add namespace you need
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;

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
		string class_name;
		void init_logging();
		void init_logfile();
		
};
//BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", severity_level)
//BOOST_LOG_ATTRIBUTE_KEYWORD(tag_attr, "Tag", std::string)
#endif // LOGGER_H_
