#include "Game.h"

// constructors
Game::Game(const Team team1, const Team team2)
	: Connectable(get_table_name(Game::CLASS_NAME))
	, logger(Game::CLASS_NAME)
	, team1(team1)
	, team2(team2)
{
}
/*
Game::Game(const Game& other)
	: Connectable(get_table_name(Game::CLASS_NAME))
	, logger(Game::CLASS_NAME)
{
}*/

// setters
void Game::set_team1(const Team team1)
{
}

void Game::set_team2(const Team team2)
{
}

void Game::set_datetime(const DateeTime DateeTime)
{
}


// getters
const Team Game::get_team1() const
{
}

const Team Game::get_team2() const
{
}

const DateeTime Game::get_datetime() const
{
}

const string Game::to_string() const
{
}

// operators
const Game& Game::operator =(const Game& other)
{
}

const bool Game::operator ==(const Game& other) const
{
}

const bool Game::operator !=(const Game& other) const
{
}

const bool Game::operator <(const Game& other) const
{
}

const bool Game::operator >(const Game& other) const
{
}

const bool Game::operator <=(const Game& other) const
{
}

const bool Game::operator >=(const Game& other) const
{
}

ostream& operator <<(ostream& strm, const Game& other)
{
}


// Connectable implement (protected)
void Game::select()
{
}

void Game::insert()
{
}

void Game::update(const string column_name, const string column_value) 
{
}

// private 
const string Game::CLASS_NAME = "Game";
