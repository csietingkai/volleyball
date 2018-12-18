#ifndef TEAM_H_
#define TEAM_H_

#include <iostream>

#include "Person.h"

namespace voba
{
	class Team : Logable, IModel
	{
		public:
			const static std::string CLASS_NAME;
			
			Team(const std::string name);
			//Team(const std::string id);
			
			const std::string get_id() const override { return IModel::get_id(); };
			const std::string to_string() const { return ""; };
			
			void update_id() override { this->id = Utils::generate_sha1(this->to_string()); };
		
		private:
			std::string name;
	};
}

#endif // TEAM_H_
