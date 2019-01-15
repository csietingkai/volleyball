#ifndef UTILS_H_
#define UTILS_H_

#include <boost/uuid/sha1.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

namespace voba
{
	class Utils
	{
		public:
			// use boost library to generate a uuid string
			const static std::string generate_uuid();
			
			// use boost library to generate a sha1 string
			const static std::string generate_sha1(const std::string str);
			
			// return a upper case string
			const static std::string to_upper_case(const std::string str);
			
			// return a lower case string
			const static std::string to_lower_case(const std::string str);
			
			// modify parameter 'str' with replace 'from' with 'to',
			// return is success or not
			const static bool replace(std::string& str, const std::string& from, const std::string& to);
			
			// remove all 'tab', 'next line', and space at start and end, then return
			const static std::string trim(const std::string str);
			
			// split a string and put into a vector and return
			const static std::vector<std::string> split(const std::string str, const char separator);
			
			// generate random string
			const static std::string random_string();
			const static std::string random_string(const int length);
	};
}

#endif // UTILS_H_
