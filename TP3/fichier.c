#include<stdio.h>
#include<stdlib.h>


int main()
{
	FILE* fichier = NULL;
	char chaine[128];
	fichier = fopen("Source.txt","r");
	while (fscanf(fichier,"%s",&chaine) != EOF)
	printf("%s\n",chaine);
	return 0;

}