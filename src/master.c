/*
	Michael Wahlberg

	Main program that moves "slave" program to needed directory and executes the program.
	From there the slave program pulls, tests and pushes. 
	Slave removes itself after execution.

	NOTE: The repo MUST have a /src folder storing the code for the current version.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

FILE * ofp;
FILE * ifp;

int main()
{
	if(DEBUG)
		printf("Beginning master.c\n");

	char * repo = (char *)malloc(256 * sizeof(char));
	char * dest = (char *)malloc(256 * sizeof(char));
	printf("Which repository?\n");
	scanf("%s", repo);

	printf("Which sub-directory?\n");
	scanf("%s", dest);

	char * cmd = (char *)malloc(256 * sizeof(char));

	strcpy(cmd, "cp slave.c ");
	strcat(cmd, repo);
	strcat(cmd, "/");
	strcat(cmd, dest);
	system(cmd);

	strcpy(cmd, "cd ");
	strcat(cmd, repo);
	strcat(cmd, " && git pull");
	system(cmd);

	if(DEBUG)
		printf("Running slave.\n");
	strcpy(cmd, "cd ");
	strcat(cmd, repo);
	strcat(cmd, "/");
	strcat(cmd, dest);
	strcat(cmd, " && git pull && ");
	strcat(cmd, "gcc slave.c -o slave && ");
	strcat(cmd, "./slave");
	system(cmd);

	if(DEBUG)
		printf("Removing slave.\n");
	strcpy(cmd, "cd ");
	strcat(cmd, repo);
	strcat(cmd, "/");
	strcat(cmd, dest);
	strcat(cmd, " && ");
	strcat(cmd, "rm slave.c && rm slave");
	system(cmd);

	return 0;
}