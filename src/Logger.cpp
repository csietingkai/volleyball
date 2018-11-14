#include "Logger.h"
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;

using namespace logging::trivial;
/*src::severity_logger< severity_level > lg;*/


Logger::Logger(const string class_name)
{

    this->class_name = class_name;
    logging::add_common_attributes();
    init_logfile();
    init_logging();
    
}
void Logger::init_logging()
{    
    boost::log::core::get()->remove_all_sinks();
    // Construct the sink
    boost::shared_ptr< logging::core > core = logging::core::get();

    // Create a backend and attach a couple of streams to it
    boost::shared_ptr< sinks::text_ostream_backend > backend =
        boost::make_shared< sinks::text_ostream_backend >();
    backend->add_stream(
        boost::shared_ptr< std::ostream >(&std::clog, boost::serialization::null_deleter()));

    // Enable auto-flushing after each log record written
    backend->auto_flush(true);
    
    // Wrap it into the frontend and register in the core.
    // The backend requires synchronization in the frontend.
    typedef sinks::synchronous_sink< sinks::text_ostream_backend > sink_t;
    boost::shared_ptr< sink_t > sink(new sink_t(backend));
    sink->set_formatter(
    expr::format("[%1%][%2%] (%3%): %4%") % expr::format_date_time < boost::posix_time::ptime
                > ("TimeStamp", "%m-%d %H:%M:%S") % logging::trivial::severity % this->class_name % expr::smessage 
    );
    sink->set_filter(logging::trivial::severity >= logging::trivial::info);
    core->add_sink(sink);
    
}
void Logger::init_logfile()
{
    boost::shared_ptr< logging::core > core = logging::core::get();
    //boost::log::register_simple_formatter_factory< boost::log::trivial::severity_level, char >("Severity");
    boost::shared_ptr< sinks::text_file_backend > backend =
        boost::make_shared< sinks::text_file_backend >(
            keywords::file_name = "logs/%Y-%m-%d_%5N.log",                                          
            keywords::rotation_size = 5 * 1024 * 1024,                                     
            keywords::time_based_rotation = sinks::file::rotation_at_time_point(12, 0, 0)
        );

    // Wrap it into the frontend and register in the core.
    // The backend requires synchronization in the frontend.
    typedef sinks::synchronous_sink< sinks::text_file_backend > sink_t;
    boost::shared_ptr< sink_t > sink(new sink_t(backend));
    //sink->set_formatter(&formatter);
    sink->set_formatter(
    expr::format("[%1%][%2%] (%3%): %4%") % expr::format_date_time < boost::posix_time::ptime
                > ("TimeStamp", "%Y-%m-%d %H:%M:%S") % logging::trivial::severity % this->class_name % expr::smessage
    
    );
    core->add_sink(sink);
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
