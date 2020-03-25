#if !defined(CONSOLE)
#define CONSOLE
#include <iostream>
#include "service.h"
#include "repository.h"

class Console
{
private:
    Service service;

public:
    Console();
    Console(Service service);
    Console(Console &other);
    void print_menu();
    void menu();
    void add_player();
    void show_players();
};
#endif // CONSOLE
