#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void listDir(char *cible, char **list)
{
	DIR *dir = NULL;
	struct dirent *ent = NULL;

	if((dir = opendir(cible)) == NULL)
	{
		fprintf (stderr, "Unable to open directory : %s\n", cible);
		return(-1);
	}

	char* tmp = NULL;
	struct stat sb;

	while((ent = readdir(dir)) != NULL)
	{
		tmp = (char *) malloc(sizeof(char) * (strlen(cible) + strlen(ent->d_name)));
		strcpy(tmp, cible);
		strcat(tmp, ent->d_name);

		if(stat(tmp, &sb) == 0 && S_DIR(sb.st_mod))
		{
			listDir(tmp, );
		}

	}

	
}
