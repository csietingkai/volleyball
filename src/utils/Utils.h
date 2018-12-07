#ifndef UTILS_H_
#define UTILS_H_

#include <boost/uuid/sha1.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <random>

namespace voba
{
	class Utils
	{
		public:
			const static std::string generate_uuid();
			const static std::string generate_sha1(const std::string str);
			const static bool replace(std::string& str, const std::string& from, const std::string& to);
			const static std::string trim(const std::string str);
			const static std::string random_string();
			const static std::string random_string(const int length);
	};
}

#endif // UTILS_H_
