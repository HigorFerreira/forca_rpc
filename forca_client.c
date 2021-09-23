/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "forca.h"


void math_100(char *host)
{
	CLIENT *clnt;
	float  *result_1;
	values  sum_100_arg;

	printf("Digite o numero 1: ");
	scanf("%f", &sum_100_arg.n1);
	printf("Digite o numero 2: ");
	scanf("%f", &sum_100_arg.n2);

	clnt = clnt_create (host, MATH, VERSION, "udp");
	if (clnt == (CLIENT *)NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

	result_1 = sum_100(&sum_100_arg, clnt);
	if (result_1 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	
	// clnt_destroy (clnt);

	printf("result_1: %f\n", *result_1);
}


int main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	math_100 (host);
	exit (0);
}
