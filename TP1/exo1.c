/* TP1 HACHAGE
AMINA FADILI IMAC1
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 51

typedef struct celmot
{
	char *mot; /* adresse de la chaine de caracteres*/
	int nombre; /* nombre d'apparitions */
	struct celmot *suivant;
} CelluleM, *ListeM;

/* la fonction qui alloue une cellule M avec le nombre d'apparitions égal à 1*/

ListeM Allouecellule( char M[])
{
	ListeM tmp;
	tmp = malloc(sizeof(CelluleM));

	if ( tmp == NULL)
	{
		return NULL;
	}
	tmp->nombre = 1;
	tmp->mot=M;
	tmp->suivant = NULL;
	return tmp;
}

/* la fonction qui renvoie le nombre d'apparitions d'un mot */

int recherchermot(ListeM *L, char M[]){
			ListeM tmp=*L;
			int existe=0;
			while(tmp!=NULL){
					if (strcmp(tmp->mot,M)==0)
					{
						existe=1;
						 return existe;
					}

				}

return existe;

}
/* la fonction qui ajoute le mot M à la liste triée */

ListeM AjouteListe(ListeM *L, char M[])
{
	ListeM nv;

	if (recherchermot(L,M)==1){
		((*L)->nombre)++);

	printf("Le nombre de fois qu'il y a le mot : %d \n",(*L)->nombre);
	}

	else{
	nv = Allouecellule(M);
	nv->suivant = *L;
	nv->mot=M;

		}

	return nv;

}


/* la fonction qui affiche une liste */

void afficheliste(ListeM L)
{
	ListeM tmp=L;

	while (tmp != NULL)
	{
		printf("%s\n",tmp->mot );
		tmp = tmp->suivant;
	}
}

/* la fonction main qui teste toutes les fonctions du TP1 */

int main ()

{
	char s[N], t[N];
	ListeM liste;
	printf("Entrer le premier mot :\n");
	scanf("%s",s);
	liste = Allouecellule(s);
	printf("Entrer le deuxième mot :\n");
	scanf("%s",t);
	liste = AjouteListe(&liste, t);
	afficheliste(liste);
}
