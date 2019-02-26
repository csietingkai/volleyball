#include "Utils.h"

// public function
const std::string voba::Utils::to_upper_case(const std::string str)
{
	// use for loop run through string and transform uppercase to lowercase
	std::string ret = "";
	
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str.at(i) >= 'a' && str.at(i) <= 'z')
		{
			ret += (char)(str.at(i)) - 'a' + 'A';
		}
		else
		{
			ret += str.at(i);
		}
	}
	
	return ret;
}

const std::string voba::Utils::to_lower_case(const std::string str)
{
	// use for loop run through string and transform lowercase to uppercase
	std::string ret = "";
	
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str.at(i) >= 'A' && str.at(i) <= 'Z')
		{
			ret += (char)(str.at(i)) - 'A' + 'a';
		}
		else
		{
			ret += str.at(i);
		}
	}
	return ret;
}

const bool voba::Utils::replace(std::string& str, const std::string& from, const std::string& to)
{
	// find the position of 'str', replace 'from' to 'to'
	size_t start_pos = str.find(from);
	if(start_pos == std::string::npos)
	{
		return false;
	}
	str.replace(start_pos, from.length(), to);
	return true;
}

const std::string voba::Utils::trim(const std::string str)
{
	// remove space from start of string and end of string
	// also remove add 'tab' & 'new line' in the string
	std::string ret = str;
	ret.erase(std::remove(ret.begin(), ret.end(), '\t'), ret.end());
	ret.erase(std::remove(ret.begin(), ret.end(), '\n'), ret.end());
	size_t first = ret.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return str;
    }
    size_t last = ret.find_last_not_of(' ');
    return ret.substr(first, (last - first + 1));
}

const std::vector<std::string> voba::Utils::split(const std::string str, const char separator)
{
	// split a string into vector
	std::stringstream ss(str);
	std::vector<std::string> result;

	while(ss.good())
	{
		std::string substr;
		getline(ss, substr, separator);
		result.push_back(substr);
	}
	
	return result;
}

const std::string voba::Utils::random_string()
{
	// call random_string
	return voba::Utils::random_string(6);
}

const std::string voba::Utils::random_string(const int length)
{
	// shuffle the sorted string and get first 'length' length string
	std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	
	std::random_device rd;
	std::mt19937 generator(rd());

	std::shuffle(str.begin(), str.end(), generator);

	return str.substr(0, length);
}

