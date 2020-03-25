#include "player.h"
#include "repository.h"
#include "service.h"
#include <assert.h>
#include <string.h>
#include <iostream>

void test_player()
{
    char *name1;
    char *name2;
    name1 = new char[7];
    name2 = new char[8];
    strcpy(name1, "Andrei");
    strcpy(name2, "Gabriel");
    Player p1(1, name1, 10, 5);
    Player p2(2, name2, 7, 7);
    assert(!strcmp(p1.get_name(), "Andrei"));
    assert(!strcmp(p2.get_name(), "Gabriel"));
    assert(p1.get_number_of_played_games() == 10);
    assert(p2.get_number_of_played_games() == 7);
    assert(p2.get_number_won_games() == 7);
    assert(p1.get_number_won_games() == 5);
    assert(p1.get_player_id() == 1);
    assert(p2.get_player_id() == 2);
    char *name3;
    name3 = new char[4];
    strcpy(name3, "Ana");
    p1.set_name(name3);
    assert(!strcmp(p1.get_name(), "Ana"));
    p2.set_played_games(12);
    assert(p2.get_number_of_played_games() == 12);
    p1.set_won_games(6);
    assert(p1.get_number_won_games() == 6);
    delete[] name1;
    name1 = nullptr;
    delete[] name2;
    name2 = nullptr;
    delete[] name3;
    name3 = nullptr;
    std::cout << "TESTS FOR PLAYER PASSED !!!" << std::endl;
}

void test_repository()
{
    char *name1 = new char[10];
    char *name2 = new char[10];
    strcpy(name1, "Andrei");
    strcpy(name2, "Gabriel");
    Player *p1 = new Player(1, name1, 10, 5);
    Player *p2 = new Player(2, name2, 7, 7);
    REPOSITORY repository;
    repository.add_entity(p1);
    assert(repository.get_size() == 1);
    repository.add_entity(p2);
    assert(repository.get_size() == 2);
    assert(*repository.get_all()[0] == *p1);
    assert(*repository.get_all()[1] == *p2);
    delete[] name1;
    name1 = nullptr;
    delete[] name2;
    name2 = nullptr;
    std::cout << "TESTS FOR REPOSITORY PASSED !!!" << std::endl;
}

void test_service()
{
    char *x = new char[8];
    strcpy(x, "Adam Andrei");
    REPOSITORY *player_repository = new REPOSITORY();
    Service player_service(player_repository);
    player_service.add_player_s(x, 10, 4);
    assert(player_service.get_size_of_repo() == 1);
    delete player_repository;
    std::cout << "TESTS FOR SERVICE PASSED !!!" << std::endl;
}

void test_service_update()
{
    char *x = new char[8];
    char *new_name = new char[8];
    strcpy(x, "Adam Andrei");
    REPOSITORY *player_repository = new REPOSITORY();
    Service player_service(player_repository);
    Player *player = player_service.add_player_s(x, 10, 4);
    strcpy(new_name, "Boss");
    Player *updated_player = player_service.update_player(player->get_player_id(), new_name, 12, 7);
    assert(strcmp(updated_player->get_name(), "Boss") == 0);
    assert(updated_player->get_number_of_played_games() == 12);
    assert(updated_player->get_number_won_games() == 7);
    std::cout << "test_service_update PASSED !!!" << std::endl;
}