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
			/**
			 * use boost library to generate a uuid string
			 * 
			 * @auther tingkai
			 * @date 2019.01.27
			 */
			const static std::string generate_uuid();
			
			/**
			 * return a upper case string
			 * 
			 * @auther tingkai
			 * @date 2019.01.27
			 */
			const static std::string to_upper_case(const std::string str);
			
			/**
			 * return a lower case string
			 * 
			 * @auther tingkai
			 * @date 2019.01.27
			 */
			const static std::string to_lower_case(const std::string str);
			
			/**
			 * modify parameter 'str' with replace 'from' with 'to', return is success or not
			 * 
			 * @auther tingkai
			 * @date 2019.01.27
			 */
			const static bool replace(std::string& str, const std::string& from, const std::string& to);
			
			/**
			 * remove all 'tab', 'next line', and space at start and end, then return
			 * 
			 * @auther tingkai
			 * @date 2019.01.27
			 */
			const static std::string trim(const std::string str);
			
			/**
			 * split a string and put into a vector and return
			 * 
			 * @auther tingkai
			 * @date 2019.01.27
			 */
			const static std::vector<std::string> split(const std::string str, const char separator);
			
			/**
			 * generate random string which length is 6
			 * 
			 * @see Utils.h: random_string(int)
			 * 
			 * @auther tingkai
			 * @date 2019.01.27
			 */
			const static std::string random_string();
			/**
			 * generate random string
			 * 
			 * @auther tingkai
			 * @date 2019.01.27
			 */
			const static std::string random_string(const int length);
	};
}

#endif // UTILS_H_
