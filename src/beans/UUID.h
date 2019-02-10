#ifndef UUID_H_
#define UUID_H_

#include <boost/regex.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>

namespace voba
{
	class UUID
	{
		public:
			UUID();
			UUID(const std::string str);
			
			const std::string to_string() const { return this->id; };
			
			const static UUID& random_uuid();
			const static UUID& from_string(const std::string str);
			
			const UUID& operator =(const UUID& other);
			friend std::ostream& operator <<(std::ostream& strm, const UUID& other) { strm << other.to_string(); return strm; };
		
		private:
			std::string id;
			const bool is_valid(const std::string str);
	};
}

#endif // UUID_H_
