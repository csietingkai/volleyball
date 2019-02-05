#include "Game.h"

const std::string voba::Game::CLASS_NAME = "Game";

// constructor
voba::Game::Game(const Team team1, const Team team2)
	: voba::Logable(voba::Game::CLASS_NAME)
	, team1(team1)
	, team2(team2)
{
	
}
