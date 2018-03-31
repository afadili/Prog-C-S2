#include <stdio.h>
#include <stdlib.h>

typedef struct noeud{
	int valeur;
	struct noeud *fg;
	struct noeud *fd;
}noeud, *arbre;

/* la fonction qui cree un arbre */

arbre creeArbre(char valeur)
{
	arbre tmp;
	tmp = (noeud*)malloc(sizeof(noeud));
	if (tmp != NULL)
	{
		tmp->valeur = valeur;
		tmp->fg = NULL;
		tmp->fd = NULL;
	}
	return tmp;
}

/* fonction max */

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
 /* fonction qui retourne le nombre de noeuds internes */

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

/* fonction qui retourne le nombre de feuilles */

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

/* fonction qui retourne le nombre de noeuds possédant 2 fils */

int DeuxFils(arbre arbre)
{
	if (arbre == NULL)
		return 0;
	else if (arbre->fg != NULL && arbre->fd != NULL)
		return 1 + DeuxFils(arbre->fg) + DeuxFils(arbre->fd);
	else 
		return DeuxFils(arbre->fg) + DeuxFils(arbre->fd);
}

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

int estHG(arbre a)
{
	if (a == NULL)
		return 1;
	if (a->fg==NULL && a->fd !=NULL)
		return 0;
	return estHG(a->fg) && estHG(a->fd);
}

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

arbre extraitMin(arbre *a)
{
	arbre tmp2 = *a;
	arbre *tmp = NULL;
	while ( (*a) != NULL)
	{
		tmp = a;
		a = &((*a)->fg);
	}
	
	printf("La valeur minimale extraite est : %d\n",(*tmp)->valeur );
	(*tmp) = (*tmp)->fd;
	return tmp2;
}

arbre extraitMax(arbre *a)
{
	arbre tmp2 = *a;
	arbre *tmp = NULL;
	while ( (*a) != NULL)
	{
		tmp = a;
		a = &((*a)->fd);
	}
	
	printf("La valeur maximale extraite est : %d\n",(*tmp)->valeur );
	(*tmp) = (*tmp)->fg;
	return tmp2;
}

/*arbre extrait(arbre *a,int n)
{

}*/

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
	//construitArbPositif(&a1);
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
	/*printf("--------ecritArbreQuelconque--------\n");
	FILE* output = NULL;
	output = fopen("output.txt","w");
	if (output != NULL )printf("Ecriture du fichier réussie !!!!\n");
	ecritArbreQuelconque(a2,output);*/
	arbre a3;
	//printf("------------Recherche arbre !!!!!!\n");
	//construitArbreQuelconque(&a2,input);
	//afficheArbPositif(a2);
	//a3 = Recherche(a2,25);
	//printf("%p\n",a3 );
	/*printf("----------extraitMin------------\n");
	a3 = extraitMin(&a2);
	afficheArbPositif(a3);
	printf("\n");*/
	printf("----------extraitMax------------\n");
	a3 = extraitMax(&a2);
	afficheArbPositif(a3);
	printf("\n");
	return 1;
}