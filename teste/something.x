struct game{
    int players_slots[4];
    int players_in_room;
    char current_word[50];
    char hidden_word[50];
    char tip[100];
    int can_go;
    
    char player_trying;
    int id_player_trying;
};

struct game_response{
    game g;
    int player_id;
};

program TESTE{
    version VERSION {
        game_response start_game(game*)=10;
        game_response trying(game*)=20;
    }=1;
}=15464;