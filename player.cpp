#include <iostream>
#include <string.h>
#include "player.h"
#include "tools.h"

Player::Player(int player_id1, char *name_player, int game_number, int won_games)
{
	this->name = new char[strlen(name_player) + 1];
	strcpy(this->name, name_player);
	this->number_of_games_played = game_number;
	this->number_of_games_won = won_games;
	this->player_id = player_id1;
}

Player::Player()
{
	this->player_id = 0;
	this->name = nullptr;
	this->number_of_games_played = 0;
	this->number_of_games_won = 0;
}

Player::Player(Player &p)
{
	this->player_id = p.player_id;
	this->name = new char[strlen(p.name) + 1];
	strcpy(this->name, p.name);
	this->number_of_games_played = p.number_of_games_played;
	this->number_of_games_won = p.number_of_games_won;
}

Player::~Player()
{
	if (this->name)
	{
		delete[] this->name;
		this->name = nullptr;
	}
}

void Player::set_name(char *name)
{
	if (this->name)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Player::set_played_games(int played_games)
{
	this->number_of_games_played = played_games;
}

void Player::set_won_games(int won_games)
{
	this->number_of_games_won = won_games;
}

char *Player::get_name()
{
	return this->name;
}

char *Player::to_string()
{
	int number_char = 5 + 1 + strlen(this->name) + 1 + 5 + 1 + 5 + 2;
	char *s = new char[number_char];
	char *for_id = new char[5];
	char *for_played_games = new char[5];
	char *for_won_games = new char[5];
	itoa(this->number_of_games_played, for_played_games, 10);
	itoa(this->number_of_games_won, for_won_games, 10);
	itoa(this->player_id, for_id, 10);
	strcpy(s, for_id);
	strcat(s, ";");
	strcat(s, this->name);
	strcat(s, ";");
	strcat(s, for_played_games);
	strcat(s, ";");
	strcat(s, for_won_games);
	if (for_id)
	{
		delete[] for_id;
		for_id = nullptr;
	}
	if (for_played_games)
	{
		delete[] for_played_games;
		for_id = nullptr;
	}
	if (for_won_games)
	{
		delete[] for_won_games;
		for_id = nullptr;
	}
	strcat(s, ";");
	return s;
}

int Player::get_number_of_played_games()
{
	return this->number_of_games_played;
}

int Player::get_number_won_games()
{
	return this->number_of_games_won;
}

int Player::get_player_id() const
{
	return this->player_id;
}

Player &Player::operator=(const Player &p)
{
	this->set_name(p.name);
	this->set_played_games(p.number_of_games_played);
	this->set_won_games(p.number_of_games_won);
	this->player_id = p.player_id;
	return *this;
}

bool Player::operator==(const Player &p)
{
	return strcmp(this->name, p.name) == 0 &&
		   this->number_of_games_played == p.number_of_games_played &&
		   this->number_of_games_won == p.number_of_games_won;
}
