#ifndef GAME_H_
#define GAME_H_

#include <iostream>

namespace voba
{
	class Game
	{
		public:
			const static std::string CLASS_NAME;
			
			Game();
			
			const std::string get_id() const { return this->id; };
		
		private:
			std::string id;
	};
}

#endif // GAME_H_
