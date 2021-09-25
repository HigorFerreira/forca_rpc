/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "forca.h"


void
game_forca_1(char *host)
{
	CLIENT *clnt;
	int  *player_id;
	game  start_game_1_arg;

	clnt = clnt_create (host, GAME_FORCA, VERSION, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

	player_id = start_game_1(&start_game_1_arg, clnt);
	if (player_id == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	if(*player_id == -1){
		clnt_perror (clnt, "Room fully crowded");
		exit(1);
	}
	printf("Seu id e: %i\n", *player_id);

	do{

	}while(1);
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	game_forca_1 (host);
	exit (0);
}
