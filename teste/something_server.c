/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "something.h"

game_response *
start_game_1_svc(game *argp, struct svc_req *rqstp)
{
	static game_response  result;

	/*
	 * insert server code here
	 */

	return &result;
}

game_response *
trying_1_svc(game *argp, struct svc_req *rqstp)
{
	static game_response  result;

	printf("%c\n", argp->player_trying);

	/*
	 * insert server code here
	 */

	return &result;
}
