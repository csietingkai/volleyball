#ifndef COMMON_H_
#define COMMON_H_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/uuid/sha1.hpp>
#include <iostream>

using namespace std;
namespace pt = boost::property_tree;

void error(const string error_message);	// error with message
const string generate_sha1(const string str);
enum class SQL
{
	select = 0,
	insert = 1,
	update = 2,
	remove = 3
};
const string sql_to_string[] = 
{"select", "insert", "update", "delete"};
const string parse_xml(const SQL sql);
const bool replace(string& str, const string& from, const string& to);
const string trim(const string& str);

#endif //COMMON_H_
