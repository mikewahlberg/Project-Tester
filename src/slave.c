/*
	Issues to resolve:
	-	Slave takes considerable amount of time to compile
	-	Maybe only move compiled program?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1
#define TESTOFP "latesttest.md"

void detLang();
void cExec(char * file);
void jExec(char * file);
void cppExec(char * file);
void csExec(char * file);
void erlExec(char * file);
void haskExec(char * file);

FILE * ofp;
char * mainFile;
int lang;

int main()
{
	ofp = fopen(TESTOFP, "w");
	fclose(ofp);
	mainFile = (char *)malloc(256 * sizeof(char));
	if(DEBUG)
		printf("Slave is in execution.\nPlease note this is not the most advanced execution but is a working prototype.\n");

	printf("Please enter the main file of your project.\n");
	scanf("%s", mainFile);

	detLang(mainFile);

	return 0;
}

//Determine what kind of program we're compiling.
void detLang(char * fileName)
{
	int i = 0;
	while(fileName[i] != '.')
		i++;
	if(fileName[i+1] == 'c' && fileName[i+2] == '\0')
	{
		if(DEBUG)
			printf("Determined to be a C file.\nCompiling.\n");
		cExec(fileName);
	}
	else if(fileName[i+1] == 'j')
	{
		if(DEBUG)
			printf("Determined to be a java file.\nCompiling.\n");
		jExec(fileName);
	}
	else if(fileName[i+1] == 'c' && fileName[i+2] == 'p')
	{
		if(DEBUG)
			printf("Determined to be a C++ file.\nCompiling.\n");
		cppExec(fileName);
	}
	else if(fileName[i+1] == 'e')
	{
		if(DEBUG)
			printf("Determined to be an Erlang file.\nCompiling.\n");
		erlExec(fileName);
	}
	else if(fileName[i+1] == 'h')
	{
		if(DEBUG)
			printf("Determined to be a Haskell file.\nCompiling.\n");
		haskExec(fileName);
	}
}

//Program compilation functions
void cExec(char * file)
{
	char * exec = (char *)malloc(256 * sizeof(char));
	strcpy(exec, "gcc ");
	strcat(exec, file);
	strcat(exec, " -o program && ./program > latesttest.txt");
	printf("%s\n", exec);
	system(exec);

}

void jExec(char * file)
{

}

void cppExec(char * file)
{

}

void csExec(char * file)
{

}

void erlExec(char * file)
{
	char * exec = (char *)malloc(256 * sizeof(char));
	strcpy(exec, "erlc ");
	strcat(exec, file);
	//strcat(exec, "")
	system(exec);

}

void haskExec(char * file)
{
	char * exec = (char *)malloc(256 * sizeof(char));
	strcpy(exec, "ghc -o");
	strcpy(exec, file);
	strcpy(exec, " program && ./program > latesttest.txt");
}