#if !defined(REPOSITORY_H)
#define REPOSITORY_H
#include "player.h"

class REPOSITORY
{
private:
    Player **players;
    int n;

public:
    REPOSITORY();
    ~REPOSITORY();
    REPOSITORY(REPOSITORY &other);
    REPOSITORY &operator=(const REPOSITORY &r);
    void add_entity(Player *p);
    Player **get_all();
    int get_size();

    /* 
     * return player with given id if exists, NULL otherwise
     */
    Player *get_by_id(int id);
};

#endif // REPOSITORY_H
