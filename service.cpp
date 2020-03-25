#include "player.h"
#include "repository.h"
#include <iostream>
#include "service.h"

Service::Service(REPOSITORY *repository)
{
    this->repository = repository;
}

Service::Service()
{
    this->repository = nullptr;
}

Service::Service(Service &s)
{
    this->repository = s.repository;
}

Service &Service::operator=(const Service &other)
{
    this->repository = other.repository;
}

Player *Service::add_player_s(char *name, int games_played, int games_won)
{
    int player_id = this->repository->get_size() + 1;
    Player *player = new Player(player_id, name, games_played, games_won);
    repository->add_entity(player);
    return player;
}

int Service::get_size_of_repo()
{
    return this->repository->get_size();
}

Player **Service::get_all_players()
{
    return this->repository->get_all();
}

Player *Service::update_player(int id, char *new_name, int new_games_played, int new_games_won)
{
    Player *player = this->repository->get_by_id(id);
    if (player == nullptr)
    {
        throw "Id doesn't exist!!!";
    }
    player->set_name(new_name);
    player->set_played_games(new_games_played);
    player->set_won_games(new_games_won);
    return player;
}