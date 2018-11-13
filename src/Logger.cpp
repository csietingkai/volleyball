#include "Logger.h"
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;

/*using namespace logging::trivial;
src::severity_logger< severity_level > lg;
enum severity_level
{
    trace,
    debug,
    info,
    warning,
    error,
    fatal
};
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", severity_level)*/

Logger::Logger(const string class_name)
{
    this->log_message = class_name;
    init_logfile();
    init_logging();
    
}
void Logger::init_logging()
{    
    /*
    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::warning
    );*/
    
    // Construct the sink
    boost::shared_ptr< logging::core > core = logging::core::get();

    // Create a backend and attach a couple of streams to it
    boost::shared_ptr< sinks::text_ostream_backend > backend =
        boost::make_shared< sinks::text_ostream_backend >();
    backend->add_stream(
        boost::shared_ptr< std::ostream >(&std::clog, boost::null_deleter()));

    // Enable auto-flushing after each log record written
    backend->auto_flush(true);
    
    // Wrap it into the frontend and register in the core.
    // The backend requires synchronization in the frontend.
    typedef sinks::synchronous_sink< sinks::text_ostream_backend > sink_t;
    boost::shared_ptr< sink_t > sink(new sink_t(backend));
    
    //sink->set_filter(severity >= warning);
    core->add_sink(sink);
    
}
void Logger::init_logfile()
{
    // Construct the sink
    boost::shared_ptr< logging::core > core = logging::core::get();

    // Create a backend and attach a couple of streams to it
    boost::shared_ptr< sinks::text_ostream_backend > backend =
        boost::make_shared< sinks::text_ostream_backend >();
    backend->add_stream(
        boost::shared_ptr< std::ostream >(new std::ofstream("sample.log")));

    // Enable auto-flushing after each log record written
    backend->auto_flush(true);

    // Wrap it into the frontend and register in the core.
    // The backend requires synchronization in the frontend.
    typedef sinks::synchronous_sink< sinks::text_ostream_backend > sink_t;
    boost::shared_ptr< sink_t > sink(new sink_t(backend));
    
    core->add_sink(sink);
}
void Logger::trace(const string message)
{
    //src::severity_logger< severity_level > lg;
    //BOOST_LOG_SEV(lg, trace) << message;
    BOOST_LOG_TRIVIAL(trace) << "This is a trace severity message";
}
void Logger::debug(const string message)
{
    //src::severity_logger< severity_level > lg;
    //BOOST_LOG_SEV(lg, debug) << message;
    BOOST_LOG_TRIVIAL(debug) << "This is a debug severity message";
}
void Logger::info(const string message)
{
    //src::severity_logger< severity_level > lg;
    //BOOST_LOG_SEV(lg, info) << message;
    BOOST_LOG_TRIVIAL(info) << "This is an informational severity message";
}
void Logger::warning(const string message)
{
    //BOOST_LOG_SEV(lg, warning) << message;
    BOOST_LOG_TRIVIAL(warning) << "This is a warning severity message";
}
void Logger::error(const string message)
{
    //BOOST_LOG_SEV(lg, error) << message;
    BOOST_LOG_TRIVIAL(error) << "This is an error severity message";
}
void Logger::fatal(const string message)
{
    //BOOST_LOG_SEV(lg, fatal) << message;
    BOOST_LOG_TRIVIAL(fatal) << "This is a fatal severity message";
}