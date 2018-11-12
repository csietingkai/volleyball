#include "Logger.h"
namespace logging = boost::log;

Logger::Logger(const string class_name)
{
    this->log_message = class_name;
}
void Logger::init_logging()
{
    logging::add_file_log("sample.log");

    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::trace
    );
}
void Logger::trace(const string message)
{
    BOOST_LOG_TRIVIAL(trace) << message;
}
void Logger::debug(const string message)
{
    BOOST_LOG_TRIVIAL(debug) << message;
}
void Logger::info(const string message)
{
    BOOST_LOG_TRIVIAL(info) << message;
}
void Logger::warning(const string message)
{
    BOOST_LOG_TRIVIAL(warning) << message;
}
void Logger::error(const string message)
{
    BOOST_LOG_TRIVIAL(error) << message;
}
void Logger::fatal(const string message)
{
    BOOST_LOG_TRIVIAL(fatal) << message;
}
