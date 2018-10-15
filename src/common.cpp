#include "common.h"

void error(const string error_message)
{
	// throw an exception
	// which output error message and shut whole program down
	throw invalid_argument(error_message);
}

const string generate_sha1(const string str)
{
	// generate sha1 from <boost/uuid/sha1.hpp> library
	// stackoverflow.com/questions/28489153/how-to-portably-compute-a-sha1-hash-in-c
	boost::uuids::detail::sha1 sha1;
	sha1.process_bytes(str.data(), str.size());
	unsigned hash[5] = {0};
	sha1.get_digest(hash);
	char buf[41] = {0};
	for (int i = 0; i < 5; i++)
	{
		std::sprintf(buf + (i << 3), "%08x", hash[i]);
	}

	string ret(buf);
	return ret;
}

const string parse_xml(const SQL sql)
{
	// www.boost.org/doc/libs/1_61_0/doc/html/property_tree/tutorial.html
	pt::ptree tree;
    pt::read_xml("resources/crud.xml", tree);
	string command = "commands."+sql_to_string[static_cast<int>(sql)];
	string str = tree.get<string>(command);
	return str;
}

const bool replace(string& str, const string& from, const string& to)
{
	size_t start_pos = str.find(from);
	if(start_pos == std::string::npos)
	{
		return false;
	}
	str.replace(start_pos, from.length(), to);
	return true;
}

const string trim(const string str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void trace_log(const string msg)
{
	//BOOST_LOG_TRIVIAL(trace) << msg;
}

/*void debug_log(const string msg)
{
	BOOST_LOG_TRIVIAL(debug) << msg;
}

void info_log(const string msg)
{
	BOOST_LOG_TRIVIAL(info) << msg;
}

void warning_log(const string msg)
{
	BOOST_LOG_TRIVIAL(warning) << msg;
}

void error_log(const string msg)
{
	BOOST_LOG_TRIVIAL(error) << msg;
}

void fatal_log(const string msg)
{
	BOOST_LOG_TRIVIAL(fatal) << msg;
}*/
