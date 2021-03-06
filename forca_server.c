/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "forca.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

game *gameServerStart(char words[][50], char tips[][100]){
	srand(time(NULL));
	int index = rand() % 4;

	game *_game = (game*)malloc(sizeof(game));

	// Getting random word
	strcpy(_game->current_word, words[index]);
	// Getting tip
	strcpy(_game->tip, tips[index]);
	//Making hidden word
	for(int i = 0; i < strlen(words[index]); i++)
		strcat(_game->hidden_word, "-");

	// Players manangement
	for(int i = 0; i < 4; i++)
		_game->players_slots[i] = i;
	_game->players_in_room = 0;

	_game->can_go = 1;

	_game->winner = 0;
	_game->winner_id = -1;

	return _game;
}

int check_winner(char *word){
	for(int i = 0; i < strlen(word); i++) if(word[i] == '-') return 0;
	return 1;
}

//Words that appear in game
char words[5][50] = { "professor", "aluno", "universidade", "vida", "morte" };
//Words tips
char tips[5][100] = { "Pessoa que cobra", "Pessoa que se fode", "Inferno", "Nao faz sentido", "Preciso disso" };
//Game global atributes
game *g;
//game started?
int started = 0;

game_response *
start_game_1_svc(game *argp, struct svc_req *rqstp)
{
	static game_response result;

	if(!started){
		printf("Starting game\n");
		g = gameServerStart(words, tips);

		//Getting player id
		int id = g->players_slots[g->players_in_room];
		g->players_in_room++;
		printf("The player id %i started the game\n", id);

		memcpy((void*)(&result.g), g, sizeof(game));
		result.player_id = id;

		// Flag that tell the game has already started
		started = 1;
	}
	else if(started && g->players_in_room < 4){
		//Getting player id
		int id = g->players_slots[g->players_in_room];
		g->players_in_room++;
		printf("The player id %i enters the game\n", id);

		memcpy((void*)(&result.g), g, sizeof(game));
		result.player_id = id;
	}
	else{
		result.player_id = -1;
	}

	return &result;
}

game_response *
trying_1_svc(game *argp, struct svc_req *rqstp)
{
	static game_response  result;

	while(!g->can_go);
	g->can_go = 0;
	printf("Player %i is trying \"%c\"\n", argp->id_player_trying, argp->player_trying);
	for(int i = 0; i < strlen(g->current_word); i++){
		// printf("%c == %c ? %i\n", g->current_word[i], g->player_trying, g->current_word[i] == argp->player_trying);
		if(g->current_word[i] == argp->player_trying){
			g->hidden_word[i] = argp->player_trying;
		}
	}

	// printf("HIDDEN WORD: %s\n", g->hidden_word);
	if(!g->winner){
		if(check_winner(g->hidden_word)){
			printf("Player %i won the game.\n", argp->id_player_trying);
		g->winner = 1;
		g->winner_id = argp->id_player_trying;
	}
	}

	// Game response
	memcpy((void*)(&result.g), g, sizeof(game));
	result.player_id = argp->id_player_trying;

	g->can_go = 1;

	return &result;
}
