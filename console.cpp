#include "console.h"
#include "player.h"
#include "repository.h"
#include "service.h"
#include <iostream>

Console::Console(Service service)
{
    this->service = service;
}

Console::Console(Console &other)
{
    this->service = other.service;
}

Console::Console()
{
    Service player_service;
    this->service = player_service;
}

void Console::print_menu()
{
    std::cout << "1. Show players" << std::endl;
    std::cout << "2. Add player" << std::endl;
    std::cout << "3. Update player" << std::endl;
}

void Console::add_player()
{
    char x[20];
    int number_of_games_played = 0;
    int number_of_games_won = 0;
    std::cout << "Player name: ";
    std::cin >> x;
    std::cout << "Player name is " << x << std::endl;
    std::cout << "Number of games played by this player: ";
    std::cin >> number_of_games_played;
    std::cout << "Number of games won by this player: ";
    std::cin >> number_of_games_won;
    this->service.add_player_s(x, number_of_games_played, number_of_games_won);
    std::cout << "Player added! " << std::endl;
}

void Console::show_players()
{
    int size = this->service.get_size_of_repo();
    Player **list_of_players = this->service.get_all_players();
    for (int i = 0; i < size; i++)
    {
        std::cout << list_of_players[i]->to_string() << std::endl;
    }
}

void Console::menu()
{
    std::cout << std::endl;
    while (1 > 0)
    {
        print_menu();
        int p = 0;
        std::cout << " " << std::endl;
        std::cout << "Option: ";
        std::cin >> p;
        if (p == 1)
        {
            this->show_players();
        }
        else if (p == 2)
        {
            this->add_player();
        }
        else if (p != 1 && p != 2)
        {
            break;
        }
    }
}