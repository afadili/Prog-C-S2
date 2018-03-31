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

typedef struct noeud{
	int valeur;
	struct noeud *fg;
	struct noeud *fd;
}noeud, *arbre;

arbre creeArbre(char valeur);

int rec_dot_export(arbre a, int nodeID, FILE *dot_file);
void dot_export(arbre a, FILE *dot_file);
void free_arbre(arbre a);
void exportTree(arbre t, char outFileName[]);

#endif
