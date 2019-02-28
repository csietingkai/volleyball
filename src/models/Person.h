#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

#include "IModel.h"
#include "../tools/Logger.h"
#include "../utils/Utils.h"

namespace voba
{
	/**
	 * gender type
	 * 
	 * @CreatedBy tingkai
	 * @Date 2018.12.18
	 */
	enum class Gender: bool
	{
		male = true,
		female = false
	};

	/**
	 * the type represent is the member still active in the team
	 * 
	 * @CreatedBy tingkai
	 * @Date 2018.12.18
	 */
	enum class ActiveStatus: bool
	{
		active = true,
		inactive = false
	};
	
	/**
	 * a person model
	 * 
	 * @Implement Logable
	 * @Implement IModel
	 * 
	 * @CreatedBy tingkai
	 * @Date 2018.12.18
	 */
	class Person : Logable, public IModel
	{
		public:
			const static std::string CLASS_NAME;
			
			/**
			 * empty constuctor of Person class
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			Person();
			/**
			 * constructor of Person class
			 * 
			 * @param name(string)
			 * @param age(int)
			 * @param gender(Gender)
			 * @param phonenumber(string)
			 * @param status(ActiveStatus)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			Person(const std::string name, const unsigned int age, const Gender gender, const std::string phonenumber, const ActiveStatus status);
			/**
			 * copy constructor of Person class
			 * 
			 * @param other(Person)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			Person(const Person& other);
			
			/**
			 * set name value
			 * 
			 * @param name(string)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void set_name(const std::string name);
			/**
			 * set age value
			 * 
			 * @param age(int)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void set_age(const unsigned int age);
			/**
			 * set gender value
			 * 
			 * @param gender(Gender)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void set_gender(const Gender gender);
			/**
			 * set phonenumber value
			 * 
			 * @param phonenumber(string)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void set_phonenumber(const std::string phonenumber);
			/**
			 * set active status value
			 * 
			 * @param status(ActiveStatus)
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void set_active_status(const ActiveStatus status);
			/**
			 * get name value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const std::string get_name() const;
			/**
			 * get age value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const int get_age() const;
			/**
			 * get gender value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const Gender get_gender() const;
			/**
			 * get phonenumber value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const std::string get_phonenumber() const;
			/**
			 * get active status value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const ActiveStatus get_active_status() const;
			/**
			 * return full info of Person
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const std::string to_string() const;
				
			// operators
			const Person& operator =(const Person& other);
			const bool operator ==(const Person& other);
			const bool operator !=(const Person& other);
			friend std::ostream& operator <<(std::ostream& strm, const Person& other);
		
		private:
			std::string name;
			unsigned int age;
			Gender gender; // true <= male, false <= female
			std::string phonenumber;
			ActiveStatus status; // true <= active, false <= inactive
	};
}

#endif // PERSON_H_
