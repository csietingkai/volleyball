#ifndef GAME_FACTORY_H_
#define GAME_FACTORY_H_

#include <iostream>
#include <vector>

#include "../Game.h"
#include "../../tools/MySQLConnector.h"

namespace voba
{
	class GameFactory
	{
		public:
			
		
		private:
			static MySQLConnector<Game> connector;
	};
}

#endif // GAME_FACTORY_H_
