#ifndef COMMON_H_
#define COMMON_H_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <iostream>
#include <set>
#include <uuid/uuid.h>

using namespace std;
namespace pt = boost::property_tree;

void error(const string error_message);	// error with message
const string uuid();
void parse_xml(const string filename);

#endif //COMMON_H_
