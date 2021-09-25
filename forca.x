struct game{
    int players_slots[4];
    int players_in_room;
    char current_word[50];
    char hidden_word[50];
    char tip[100];
    int can_go;
    int turn;
};

struct player{
    int id;
};

program GAME_FORCA{
    version VERSION {
        int start_game(game*)=10;
    }=1;
}=1344357464;