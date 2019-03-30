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
	/**
	 * id object for model
	 * 
	 * @CreatedBy tingkai
	 * @Date 2019.02.07
	 */
	class UUID
	{
		public:
			/**
			 * constructor generate null UUID
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.02.07
			 */
			UUID();
			/**
			 * constructor generate uuid from string
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.02.07
			 */
			UUID(const std::string str);
			
			/**
			 * return stored string value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.02.07
			 */
			const std::string to_string() const { return this->id; };
			
			/**
			 * generate random uuid object
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.02.07
			 */
			const static UUID& random_uuid();
			/**
			 * generate uuid object from string
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.02.07
			 */
			const static UUID& from_string(const std::string str);
			
			const UUID& operator =(const UUID& other);
			const bool operator ==(const UUID& other) const;
			const bool operator !=(const UUID& other) const;
			friend std::ostream& operator <<(std::ostream& strm, const UUID& other);
		
		private:
			std::string id;
			
			/**
			 * check is a string valid uuid string
			 * 
			 * @CreatedBy tingkai
			 * @Date 2019.02.07
			 */
			const bool is_valid(const std::string str);
	};
}

#endif // UUID_H_
