struct game{
    int players_slots[4];
    int players_in_room;
    char current_word[50];
    char hidden_word[50];
    char tip[100];
    int can_go;
    int turn;
};

struct start_game_response{
    game g;
    int player_id;
};

program GAME_FORCA{
    version VERSION {
        start_game_response start_game(game*)=10;
    }=1;
}=1344357464;