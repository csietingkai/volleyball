#include "Utils.h"

// public function
const std::string voba::Utils::generate_uuid()
{
	boost::uuids::random_generator generator;
	boost::uuids::uuid uuid = generator();
	return boost::uuids::to_string(uuid);
}

const std::string voba::Utils::generate_sha1(const std::string str)
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

	std::string ret(buf);
	return ret;
}

const bool voba::Utils::replace(std::string& str, const std::string& from, const std::string& to)
{
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
	std::string ret = str;
	// also remove add 'tab' & 'new line' in the string
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

const std::string voba::Utils::random_string()
{
	return voba::Utils::random_string(6);
}

const std::string voba::Utils::random_string(const int length)
{
	std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	
	std::random_device rd;
	std::mt19937 generator(rd());

	std::shuffle(str.begin(), str.end(), generator);

	return str.substr(0, length);
}

