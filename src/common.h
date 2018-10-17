#ifndef COMMON_H_
#define COMMON_H_

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/uuid/sha1.hpp>
#include <iostream>

using namespace std;
namespace pt = boost::property_tree;

void error(const string error_message);	// error with message

const string generate_sha1(const string str);

enum class SQL
{ select = 0, insert = 1, update = 2, remove = 3 };

const string sql_to_string[] = 
{ "select", "insert", "update", "delete" };

const string get_sql_command(const SQL sql);

enum class Connect_info
{ server = 0, account = 1, pwd = 2, schema = 3 };

const string connect_info_to_string[] = 
{ "server", "account", "pwd", "schema" };

const string get_connect_info(const Connect_info info);

const string parse_xml(const string filename, const string node_name);

const bool replace(string& str, const string& from, const string& to);

const string trim(const string str);

void trace_log(const string msg);

void debug_log(const string msg);

void info_log(const string msg);

void warning_log(const string msg);

void error_log(const string msg);

void fatal_log(const string msg);

#endif //COMMON_H_
