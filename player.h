#if !defined(PLAYER_H)
#define PLAYER_H

class Player
{
private:
    char *name;
    int player_id;
    int number_of_games_played;
    int number_of_games_won;

public:
    Player(int player_id, char *n, int number_of_total_games, int number_of_won_games);
    Player();
    ~Player();
    Player(Player &p);
    char *get_name();
    char *to_string();
    int get_number_of_played_games();
    int get_number_won_games();
    void set_name(char *name);
    void set_played_games(int played_games);
    void set_won_games(int won_games);
    int get_player_id() const;
    Player &operator=(const Player &p);
    bool operator==(const Player &p);
};

#endif // PLAYER_H
