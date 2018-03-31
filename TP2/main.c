#include <stdio.h>
#include <stdlib.h>
#include "export-to-dot/export-to-dot.h"

/* TP2 Les arbres binaires  
 AMINA FADILI IMAC 1
 */



/* la fonction qui retourne le maximun de deux entiers */

int max(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

/* la fonction qui renvoie la hauteur d'un arbre */

int hauteurArbre(arbre arbre)
{
	if (arbre == NULL)
		return -1;
	else
	{
		return 1 + max(hauteurArbre(arbre->fg),hauteurArbre(arbre->fd));

	}

}

/* la fonction qui retourne le nombre de noeuds de l'arbre */

int NbNoeuds(arbre arbre)
{
	if (arbre == NULL)
		return 0;
	else
	{
		return 1 + NbNoeuds(arbre->fg) + NbNoeuds(arbre->fd);
	}
}
 /* la fonction qui retourne le nombre de noeuds internes */

int NbNoeudsInternes(arbre arbre)
{
	if (arbre == NULL)
		return 0;
	else if (arbre->fg == NULL && arbre->fd == NULL)
		return 0;
	else
	{
		return 1 + NbNoeudsInternes(arbre->fg) + NbNoeudsInternes(arbre->fd);
	}

}

/* la fonction qui retourne le nombre de feuilles */

int NbFeuilles(arbre arbre)
{
	if (arbre == NULL)
		return 0;
	else if (arbre->fg == NULL && arbre->fd == NULL)
		return 1;
	else
	{
		return NbFeuilles(arbre->fg) + NbFeuilles(arbre->fd);
	}
}

/* la fonction qui retourne le nombre de noeuds possédant 2 fils */

int DeuxFils(arbre arbre)
{
	if (arbre == NULL)
		return 0;
	else if (arbre->fg != NULL && arbre->fd != NULL)
		return 1 + DeuxFils(arbre->fg) + DeuxFils(arbre->fd);
	else
		return DeuxFils(arbre->fg) + DeuxFils(arbre->fd);
}

/* la fonction qui affiche l'arbre en parcours préfixe */

void LirePreffixe(arbre a)
{
	if (a == NULL)
	{
		return;
	}
	printf("%c,",a->valeur );
	LirePreffixe(a->fg);
	LirePreffixe(a->fd);
}

/* la fonction qui affiche l'arbre en parcours Suffixe */

void LireSuffixe(arbre a)
{
	if (a == NULL)
	{
		return;
	}
	LireSuffixe(a->fg);
	LireSuffixe(a->fd);
	printf("%c,",a->valeur );
}

/* la fonction qui affiche l'arbre en parcours Infixe */

void LireInfixe(arbre a)
{
	if (a == NULL)
	{
		return;
	}
	LireInfixe(a->fg);
	printf("%c,",a->valeur );
	LireInfixe(a->fd);

}

/* la fonction qui affiche la suite des entiers décrivant l'arbre */

void afficheArbPositif(arbre a)
{
	if (a == NULL)
	{
		printf("0,");
		return;
	}
	printf("%d,",a->valeur );
	afficheArbPositif(a->fg);
	afficheArbPositif(a->fd);
}

/* la fonction qui construit un arbre binaire à partir d'une suite d'entiers valide */

void construitArbPositif(arbre *a)
{
	int in;
	scanf("%d ",&in);
	if (in == 0)
	{
		*a = NULL;
		return ;
	}
	*a = creeArbre(in);
	if(*a == NULL) printf("oh no\n");
	construitArbPositif(&((*a)->fg));
	construitArbPositif(&((*a)->fd));
}

/* la fonction qui vérifie si un arbre est héréditairement gauche*/

int estHG(arbre a)
{
	if (a == NULL)
		return 1;
	if (a->fg==NULL && a->fd !=NULL)
		return 0;
	return estHG(a->fg) && estHG(a->fd);
}

/* TP3 Codage d'un arbre strictement binaire et arbre binaire de recherche
 AMINA FADILI IMAC 1
 */

/* la fonction qui construit un arbre à partir d'un fichier contenant une suite d'entiers décrivant l'arbre*/


void construitArbreQuelconque(arbre *a, FILE *in)
{
	int action, valeur;
	if (fscanf(in,"%d %d",&action,&valeur) == EOF)
		return;
	*a = creeArbre(valeur);
	switch (action)
	{
		case 1:
		construitArbreQuelconque(&((*a)->fd),in);
		break;
		case 2:
		construitArbreQuelconque(&((*a)->fg),in);
		break;
		case 3:
		construitArbreQuelconque(&((*a)->fg),in);
		construitArbreQuelconque(&((*a)->fd),in);
		break;
	}
}

/* la fonction qui écrit dans un fichier la suite d'entiers décrivant un arbre */


void ecritArbreQuelconque(arbre a,FILE *out)
{
	int  action =0;
	if (a == NULL)
	{
		return;
	}
	if (a->fd != NULL)
	{
		action+= 1;
	}
	if (a->fg != NULL)
	{
		action+= 2;
	}
	fprintf(out,"%d %d ",action,a->valeur);
	ecritArbreQuelconque(a->fg,out);
	ecritArbreQuelconque(a->fd,out);
}

/* la fonction qui recherche un élément dans un arbre */

arbre Recherche(arbre a, int n)
{
	while (a != NULL)
	{
		if (n == a->valeur)
		{
			return a;
		}
		if (n < a->valeur )
		{
			a = a->fd;
		}
		else
		{
			a = a->fg;
		}
	}
	return NULL;
}

/* la fonction qui ajoute un élément dans un arbre binaire de recherche*/

void ajout(arbre *a, int n)
{
	// parcours de l'arbre jusqu'à une place vide
	while ((*a) != NULL)
	{
		if (n == (*a)->valeur)
		{
			return;
		}
		if (n < (*a)->valeur )
		{
			a = &((*a)->fd);
		}
		else
		{
			a = &((*a)->fg);
		}
	}
	*a = creeArbre(n);
	return;
}

/* la fonction qui effectue l'extraction du noeud contenant la plus petite étiquette de l'arbre binaire de recherche */

arbre extraitMin(arbre *a)
{
	arbre tmp2;
	arbre *tmp = NULL;
	while ( (*a) != NULL)
	{
		tmp = a;
		tmp2 = *a;
		a = &((*a)->fg);

	}

	printf("La valeur minimale extraite est : %d\n",(*tmp)->valeur );
	(*tmp) = (*tmp)->fd;
	return tmp2;
}

/* la fonction qui effectue l'extraction du noeud contenant la plus grande étiquette de l'arbre binaire de recherche */

arbre extraitMax(arbre *a)
{
	arbre tmp2;
	arbre *tmp = NULL;
	while ( (*a) != NULL)
	{
		tmp = a;
		tmp2 = *a;
		a = &((*a)->fd);

	}

	printf("La valeur maximale extraite est : %d\n",(*tmp)->valeur );
	(*tmp) = (*tmp)->fg;
	return tmp2;
}

/* la fonction qui effectue l'extraction du noeud contenant une étiquette donnée d'un arbre binaire de recherche */

arbre extrait(arbre *a,int n)
{
	arbre ret, tmp2;
	while ((*a) != NULL)
	{
		printf("%d\n",(*a)->valeur );
		if (n == (*a)->valeur)

			{

				ret = *a;
				if ((*a)->fg == NULL && (*a)->fd == NULL)

				{

					(*a) = NULL;
				}
				else if ((*a)->fg != NULL && (*a)->fd != NULL)
				{

					tmp2 = extraitMax(&((*a)->fg));
					tmp2->fg = (*a)->fg;
					tmp2->fd = (*a)->fd;
					(*a) = tmp2;
				}
				else if ((*a)->fg != NULL)
				{

					(*a) = (*a)->fg;
				}
				else if ((*a)->fd != NULL)
				{

					(*a) = (*a)->fd;
				}
				return ret;
			}
		if (n >= (*a)->valeur )
			{

				a = &((*a)->fd);
			}
		else
			{

				a = &((*a)->fg);
			}
	}
	printf("Pas trouvé !\n");
	return NULL;
}

/* la fonction qui détermine si un arbre est un arbre binaire de recherche */

int estABR(arbre a)
{
	if (a == NULL)
	{
		return 1;
	}
	if (a->fd != NULL)
		if (a->fd->valeur < a->valeur)
		{
			return 0;
		}
	if (a->fg != NULL)
		if (a->fg->valeur > a->valeur)
		{
			return 0;
		}
	return estABR(a->fg) && estABR(a->fd);
}

/* la fonction main avec le test de toutes les fonctions précédentes du TP3 et TP2 */

int main ()
{
	arbre a;
	a = creeArbre('a');
	a->fg = creeArbre('z');
	a->fd = creeArbre('c');
	a->fg->fg = creeArbre('x');
	a->fg->fd = creeArbre('e');
	a->fg->fg->fg = creeArbre('h');
	a->fg->fg->fd = creeArbre('n');
	a->fg->fd->fg = creeArbre('j');
	a->fg->fd->fg->fd = creeArbre('i');
	a->fd->fd = creeArbre('g');
	a->fd->fd->fg = creeArbre('e');
	a->fd->fd->fd = creeArbre('d');

	printf("La hauteur de l'arbre est %d \n",hauteurArbre(a) );
	printf("Le nombre de noeuds de l'arbre est %d \n",NbNoeuds(a) );
	printf("Le nombre de noeuds internes de l'arbre est %d \n",NbNoeudsInternes(a) );
	printf("Le nombre de feuilles de l'arbre est %d \n",NbFeuilles(a) );
	printf("Le nombre de noeuds possédant deux fils de l'arbre est %d \n",DeuxFils(a) );
	printf("Parcours Préfixe : \n");
	LirePreffixe(a);
	printf("\n");
	printf("Parcours Suffixe : \n");
	LireSuffixe(a);
	printf("\n");
	printf("Parcours Infixe : \n");
	LireInfixe(a);
	printf("\n");
	printf("Parcours Préfixe afficheArbPositif : \n");
	afficheArbPositif(a);
	printf("\n");
	arbre a1= NULL;
	construitArbPositif(&a1);
	afficheArbPositif(a1);
	printf("\n");
	printf(" code de est HG de a1 : %d\n", estHG(a1));
	arbre a2;
	FILE* input = NULL;
	printf("------------Lecture du fichier------------ \n");
	input = fopen("Source.txt","r");
	if (input != NULL ) printf("Lecture du fichier réussie !!! \n");
	construitArbreQuelconque(&a2,input);
	printf("------------fonction construitArbreQuelconque ------------\n");
	afficheArbPositif(a2);
	printf("\n");
	printf("--------ecritArbreQuelconque--------\n");
	FILE* output = NULL;
	output = fopen("output.txt","w");
	if (output != NULL )printf("Ecriture du fichier réussie !!!!\n");
	ecritArbreQuelconque(a2,output);
	arbre a3;
	printf("------------Recherche arbre !!!!!!\n");
	construitArbreQuelconque(&a2,input);
	afficheArbPositif(a2);
	a3 = Recherche(a2,25);
	printf("%p\n",a3 );
	printf("----------extraitMin------------\n");
	a3 = extraitMin(&a2);
	afficheArbPositif(a3);
	printf("\n");
	printf("----------extraitMax------------\n");
	a3 = extraitMax(&a2);
	afficheArbPositif(a3);
	printf("\n");

	/* affichage en dot */
	exportTree(a2,"arbre1.dot");
	system("dot -Tpdf arbre1.dot -o arbre1.pdf");
	system("evince arbre1.pdf");
	arbre ax;
	ax = extrait(&a2,20);
	exportTree(a2,"arbre.dot");
	system("dot -Tpdf arbre.dot -o arbre.pdf");
	system("evince arbre.pdf");
	printf("Test si a2 est ABR : %d\n",estABR(a2) );
	return 1;
}
