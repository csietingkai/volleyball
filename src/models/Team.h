#ifndef TEAM_H_
#define TEAM_H_

#include <iostream>

namespace voba
{
	class Team
	{
		public:
			const static std::string CLASS_NAME;
			
			Team();
			Team(const std::string id);
			
			const std::string get_id() const { return this->id; };
		
		private:
			std::string id;
	};
}

#endif // TEAM_H_
