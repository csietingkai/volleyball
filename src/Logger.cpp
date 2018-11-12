#include "Logger.h"
namespace logging = boost::log;
namespace keywords = boost::log::keywords;

Logger::Logger(const string class_name)
{
    this->log_message = class_name;
    init_logging();
}
void Logger::init_logging()
{
    logging::add_file_log("sample.log"); 
    logging::add_console_log(std::cout, keywords::format = ">> %Message%");
    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::warning
    );
}

void Logger::trace(const string message)
{
    boost::log::core::get()->remove_all_sinks();
    update_logging_low();
    BOOST_LOG_TRIVIAL(trace) << message;
    
    boost::log::core::get()->remove_all_sinks();
    update_logging_up();
}
void Logger::debug(const string message)
{
    //boost::log::core::get()->remove_all_sinks();
    //update_logging();
    BOOST_LOG_TRIVIAL(debug) << message;

}
void Logger::info(const string message)
{
    BOOST_LOG_TRIVIAL(info) << message;
}
void Logger::warning(const string message)
{
    //logging_file();
   // BOOST_LOG_TRIVIAL(warning) << message;
    //boost::log::core::get()->remove_all_sinks();
    //boost::log::core::get()->remove_all_sinks();
    //update_logging();
    BOOST_LOG_TRIVIAL(warning) << message;
    //boost::log::core::get()->remove_all_sinks();
    //update_logging();
}
void Logger::error(const string message)
{
    //boost::log::core::get()->remove_all_sinks();
    //update_logging();
    BOOST_LOG_TRIVIAL(error) << message;
    //boost::log::core::get()->remove_all_sinks();
    //update_logging();
}
void Logger::fatal(const string message)
{
    //boost::log::core::get()->remove_all_sinks();
    //update_logging();
    BOOST_LOG_TRIVIAL(fatal) << message;
    //boost::log::core::get()->remove_all_sinks();
    //update_logging();
}
void Logger::update_logging_low()
{
    logging::add_file_log("sample.log"); 
    //logging::add_console_log(std::cout, keywords::format = ">> %Message%");
    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::trace
    );
    //printf("security down !!\n");
}
void Logger::update_logging_up()
{
    logging::add_file_log("sample.log"); 
    logging::add_console_log(std::cout, keywords::format = ">> %Message%");
    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::warning
    );
    //printf("security up !!\n");
}