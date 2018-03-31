#include <stdio.h>
#include <stdlib.h>

/* fonction qui teste si un tableau est un tas ou pas */

int est_tas(int tab[], int taille)
{
	 for (int i=0; i<taille; i++)
	 {
	 	if (tab[(i-1)/2]>tab[i])
	 	{
	 		return 0;
	 	}
	 }
	 return 1;
}

/* fonction récursive qui construit les permutations */

int enum_permutation(int t[], int premier, int n)
{
	int i = 0;
	if (premier <= n)
	{
		while (i<n && t[i] != 0)
		{
			i++;
			t[i] = enum_permutation(t, premier+1, n);
		}
	}
}

int main(int argc, char const *argv[])
{
	return 0;
}