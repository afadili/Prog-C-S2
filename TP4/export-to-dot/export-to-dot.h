//
//  export-to-dot.h
//  imac_c-prog
//
//  Created by Pierre Gabory on 02/03/2018.
//

#ifndef export_to_dot_h
#define export_to_dot_h

#include <stdio.h>
#include <stdlib.h>

/* definition de la structure de l'arbre ternaire */

typedef struct noeud{
	char valeur;
	struct noeud *frg;
	struct noeud *frd;
	struct noeud *fils;
}Tnoeud, *Tarbre;

Tarbre creerTArbre(char valeur);

int rec_dot_export(Tarbre a, int nodeID, FILE *dot_file);
void dot_export(Tarbre a, FILE *dot_file);
void free_arbre(Tarbre a);
void exportTree(Tarbre t, char outFileName[]);

#endif
