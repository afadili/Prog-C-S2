#include <stdio.h>
#include <stdlib.h>
#include "export-to-dot/export-to-dot.h"

/* TP4 Arbres binaires de Recherche
			 Chemins dans un arbre
			 Arbres ternaires lexicographiques
	AMINA FADILI IMAC1*/

/* la fonction recherche d'un mot dans l'arbre ternaire */

int recherche(Tarbre a, char *m)
{
	while (*m != '\0') /* je parcoure l'arbre tant que j'ai pas trouvé le mot */
	{
		if (a == NULL)
		{
			return 0;
		}

		if (a->valeur == *m ) /* si la lettre du mot cherché est trouvé je passe à la suivante*/
			{
				m++;
				a = a->fils;
			}
		if (a->valeur != *m)/* si la lettre n'est pas celle qu'on cherche */
		{
			if (a->valeur < *m)/* si la lettre est inférieur on va à gauche */
			{
				a = a->frg;
			}
			else
			{
				a = a->frd;/* si la lettre est supérieur on va à droite*/
			}
		}

	}
	return 1;/* quand on ne cherche plus le mot c'est qu'on la trouvé ! ah yes !*/
}

/* la fonction qui calcule le nombre de mot dans un arbre ternaire */

int nombreMot (Tarbre a)
{
	int cpt=0 ;
	if (a == NULL)
	{
		return 0;
	}
	if (a->valeur == '\0')
	{
		cpt = 1;
	}
	return cpt+nombreMot(a->frg)+nombreMot(a->fils)+nombreMot(a->frd);
}

/* la fonction qui ajoute un mot dans un arbre ternaire */

int ajouteMot(Tarbre *a, char *m)
{
	while (*m != '\0') /* je parcoure l'arbre tant que j'ai pas rajouté tout le mot */
	{

		if ((*a) == NULL)
		{
			(*a) = creerTArbre(*m);
			a = &((*a)->fils);
			m++;
		}

		else if ((*a)->valeur == *m ) /* si la lettre du mot rajouté est trouvée je passe à la suivante*/
			{
				m++;
				a = &((*a)->fils);
			}
		else if ((*a)->valeur != *m)/* si la lettre n'est pas celle qu'on veut rajouter */
		{
			if (*m < (*a)->valeur)/* si la lettre est inférieur on va à gauche */
			{
				a = &((*a)->frg);
			}
			else
			{
				a = &((*a)->frd);/* si la lettre est supérieur on va à droite*/
			}
		}

	}
	if ((*a) == NULL)
	{
		(*a) = creerTArbre('\0');
		printf("sors du while et execute le dernier if ----------\n");
	}
	return 0;/* quand on ne cherche plus la fin du mot c'est qu'on la rajouté ! ah yes !*/

}

/* la fonction qui affiche en ordre alphabétique les mots d'un arbre ternaire */

void affiche (Tarbre a)
{
	if (a == NULL)
	{
		return;
	}
		printf("%c",a->valeur );
		affiche(a->frg);
		affiche(a->fils);
		affiche(a->frd);
	if (a->valeur == '\0')
	{
		printf("\n");
	}
}

/* la fonction main qui effectue le test de toutes les fonctions du TP4*/

int main()
{
	Tarbre a;
	a = creerTArbre('l');
	a->fils = creerTArbre('e');
	a->fils->fils = creerTArbre('\0');
	a->fils->fils->frd = creerTArbre('s');
	a->fils->fils->frd->fils = creerTArbre('\0');
	a->fils->frg = creerTArbre('a');
	a->fils->frg->fils = creerTArbre('\0');
	exportTree(a,"arbreT.dot");
	system("dot -Tpdf arbreT.dot -o arbreT.pdf");
	system("evince arbreT.pdf");
	printf("La valeur de recherche du mot lea est : %d\n",recherche(a,"lea") );
	printf("La valeur de recherche du mot le est : %d\n",recherche(a,"le") );
	printf("Le nombre de mot de l'arbe ternaire est : %d\n",nombreMot(a) );
	printf("le code d'erreur de la fonction ajoute d'un mot est : %d\n",ajouteMot(&a,"lea"));
	printf("le code d'erreur de la fonction ajoute d'un mot est : %d\n",ajouteMot(&a,"exemple"));
	printf("le code d'erreur de la fonction ajoute d'un mot est : %d\n",ajouteMot(&a,"exemplaire"));
	printf("le code d'erreur de la fonction ajoute d'un mot est : %d\n",ajouteMot(&a,"truc"));
	printf("le code d'erreur de la fonction ajoute d'un mot est : %d\n",ajouteMot(&a,"amina"));
	printf("le code d'erreur de la fonction ajoute d'un mot est : %d\n",ajouteMot(&a,"Marie"));
	printf("le code d'erreur de la fonction ajoute d'un mot est : %d\n",ajouteMot(&a,"pierre"));
	exportTree(a,"arbreT.dot");
	system("dot -Tpdf arbreT.dot -o arbreT.pdf");
	system("evince arbreT.pdf");
	affiche(a);
}
