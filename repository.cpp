#include "repository.h"
#include "player.h"
#include <iostream>

REPOSITORY::REPOSITORY()
{
    this->n = 0;
    this->players = new Player *[20];
}

REPOSITORY::REPOSITORY(REPOSITORY &other)
{
    this->n = other.n;
    for (int i = 0; i < other.n; i++)
    {
        this->players[i] = other.players[i];
    }
}
REPOSITORY::~REPOSITORY()
{
    for (int i = 0; i < this->n; i++)
    {
        delete this->players[i];
    }
    this->n = 0;
    delete this->players;
}

void REPOSITORY::add_entity(Player *p)
{
    this->players[this->n++] = p;
}

Player **REPOSITORY::get_all()
{
    return this->players;
}

int REPOSITORY::get_size()
{
    return this->n;
}

REPOSITORY &REPOSITORY::operator=(const REPOSITORY &other)
{
    this->n = other.n;
    for (int i = 0; i < n; i++)
    {
        this->players[i] = other.players[i];
    }
}

Player *REPOSITORY::get_by_id(int id)
{
    for (int i = 0; i < this->n; i++)
    {
        if (this->players[i]->get_player_id() == id)
        {
            return this->players[i];
        }
    }
    return nullptr;
}