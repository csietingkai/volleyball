#ifndef UTILS_H_
#define UTILS_H_

#include <boost/uuid/sha1.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <climits>
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
			 * return a upper case string
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.27
			 */
			const static std::string to_upper_case(const std::string str);
			
			/**
			 * return a lower case string
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.27
			 */
			const static std::string to_lower_case(const std::string str);
			
			/**
			 * modify parameter 'str' with replace 'from' with 'to', return is success or not
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.27
			 */
			const static bool replace(std::string& str, const std::string& from, const std::string& to);
			
			/**
			 * remove all 'tab', 'next line', and space at start and end, then return
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.27
			 */
			const static std::string trim(const std::string str);
			
			/**
			 * split a string and put into a vector and return
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.27
			 */
			const static std::vector<std::string> split(const std::string str, const char separator);
			
			/**
			 * generate random integer
			 * 
			 * @see Utils #random_integer(int, int)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.19
			 */
			const static int random_integer();
			/**
			 * generate random integer
			 * 
			 * @param min(int)
			 * @param max(int)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.03.19
			 */
			const static int random_integer(const int min, const int max);
			/**
			 * generate random string which length is 6
			 * 
			 * @see Utils #random_string(int)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.27
			 */
			const static std::string random_string();
			/**
			 * generate random string
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.01.27
			 */
			const static std::string random_string(const int length);
	};
}

#endif // UTILS_H_
