#if !defined(SERVICE_H)
#define SERVICE_H
#include "repository.h"
#include "player.h"

class Service
{
private:
    REPOSITORY *repository;

public:
    Service();
    Service(REPOSITORY *repository);
    Service(Service &s);
    Service &operator=(const Service &other);
    Player *add_player_s(char *name, int games_played, int games_won);
    int get_size_of_repo();
    Player *update_player(int id, char *new_name, int new_games_played, int new_games_won);
    Player **get_all_players();
};

#endif // SERVICE_H
