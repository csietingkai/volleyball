#include "common.h"

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

const string get_sql_command(const SQL sql)
{
	string filename = "resources/crud.xml";
	string node_name = "commands."+sql_to_string[static_cast<int>(sql)];
	return parse_xml(filename, node_name);
}

const string get_connect_info(const Connect_info info)
{
	string filename = "resources/connect_info.xml";
	string node_name = "connection."+connect_info_to_string[static_cast<int>(info)];
	return parse_xml(filename, node_name);
}

const string parse_xml(const string filename, const string node_name)
{
	// www.boost.org/doc/libs/1_61_0/doc/html/property_tree/tutorial.html
	pt::ptree tree;
    pt::read_xml(filename, tree);
	string str = tree.get<string>(node_name);
	return trim(str);
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
	string ret = str;
	ret.erase(remove(ret.begin(), ret.end(), '\t'), ret.end());
	ret.erase(remove(ret.begin(), ret.end(), '\n'), ret.end());
	size_t first = ret.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = ret.find_last_not_of(' ');
    return ret.substr(first, (last - first + 1));
}
