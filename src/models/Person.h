#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

#include "../tools/MySQLConnector.h"

namespace voba
{
	enum class Gender: bool
	{
		male = true,
		female = false
	};

	enum class ActiveStatus: bool
	{
		active = true,
		inactive = false
	};
	
	class Person
	{
		public:
			const static std::string CLASS_NAME;
			
			// constructor
			Person();
		
		private:
			std::string id;
			std::string name;
			unsigned int age;
			Gender gender; // true <= male, false <= female
			std::string phonenumber;
			ActiveStatus status; // true <= active, false <= inactive
			
			MySQLConnector connector;
			Logger logger;
	};
}

#endif // PERSON_H_
