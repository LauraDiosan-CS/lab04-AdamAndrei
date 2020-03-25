#include "console.h"
#include "test.h"
#include "repository.h"
#include "service.h"
#include <string.h>

int main()
{
    test_player();
    test_repository();
    test_service();
    test_service_update();
    char *x = new char[8];
    strcpy(x, "Adam Andrei");
    REPOSITORY *player_repository = new REPOSITORY();
    Service player_service(player_repository);
    Console console(player_service);
    player_service.add_player_s(x, 1100, 4);
    console.menu();
    delete player_repository;
    return 0;
}