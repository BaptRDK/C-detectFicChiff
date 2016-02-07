#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>
#include <string.h>

#include "calcEntFic.h"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		fprintf(stderr, "Usage: %s directory threshold[Mo] sample[Mo]\n", argv[0]);
		return(-1);
	}

	char *cible = argv[1];

	DIR* dir = NULL;

	if((dir = opendir(cible)) == NULL)
	{
		fprintf(stderr, "Unable to open the directory: %s\n", cible);
		return(-2);
	}

	struct dirent* ent = NULL;
//	char *file = NULL;
	char *tmp = NULL;
	tmp = (char*) malloc(strlen(cible)*sizeof(char)+50);
	
	if(tmp == NULL)
	{
		fprintf(stderr, "Failure allocating memory.\n");
		return(-3);
	}

	while((ent = readdir(dir)) != NULL)
	{
		strcpy(tmp, cible);
		printf("%s : %f\n", ent->d_name, calcEntFic(strcat(tmp, ent->d_name), 100));	
	}
	
	free(tmp);
	closedir(dir);


	return(0);
}
