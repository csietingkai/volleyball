#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

#include "../tools/Logger.h"
#include "../utils/Utils.h"

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
	
	class Person : Logable
	{
		public:
			const static std::string CLASS_NAME;
			
			// constructor
			Person(const std::string name, const unsigned int age, const Gender gender, const std::string phonenumber, const ActiveStatus status);
			Person(const std::string id);
			Person(const Person& other);
			
			// setters
			void set_name(const std::string name) { this->name = name; this->update_id(); };
			void set_age(const unsigned int age) { this->age = age; this->update_id(); };
			void set_gender(const Gender gender) { this->gender = gender; this->update_id(); };
			void set_phonenumber(const std::string phonenumber) { this->phonenumber = phonenumber; this->update_id(); };
			void set_active_status(const ActiveStatus status) { this->status = status; this->update_id(); };
			
			// getters
			const std::string get_id() const { return this->id; };
			const std::string get_name() const { return this->name; };
			const int get_age() const { return this->age; };
			const Gender get_gender() const { return this->gender; };
			const std::string get_phonenumber() const { return this->phonenumber; };
			const ActiveStatus get_active_status() const { return this->status; };
			const std::string to_string() const;
				
			// operators
			const Person& operator =(const Person& other);
			const bool operator ==(const Person& other) const;
			const bool operator !=(const Person& other) const { return !this->operator==(other); };
			friend std::ostream& operator <<(std::ostream& strm, const Person& other) { strm << other.to_string(); return strm; };
		
		private:
			std::string id;
			std::string name;
			unsigned int age;
			Gender gender; // true <= male, false <= female
			std::string phonenumber;
			ActiveStatus status; // true <= active, false <= inactive
			
			void update_id() { this->id = Utils::generate_sha1(this->to_string()); };
	};
}

#endif // PERSON_H_
