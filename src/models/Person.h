#ifndef PERSOM_H_
#define PERSOM_H_

#include <iostream>

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
			Person();
		
		private:
			std::string id;
			std::string name;
			unsigned int age;
			Gender gender; // true <= male, false <= female
			std::string phonenumber;
			ActiveStatus status; // true <= active, false <= inactive
	};
}

#endif // PERSOM_H_
