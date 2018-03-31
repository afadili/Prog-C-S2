//
//  export-to-dot.c
//  imac_c-prog
//
//  Created by Pierre Gabory on 02/03/2018.
//

#include "export-to-dot.h"

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

int rec_dot_export(arbre a, int nodeID, FILE *dot_file) {
    int val, res_left=0, res_right=0;
    if (a != NULL) {
        val = a->valeur;
        fprintf(dot_file, "\tn%d [label=\"<left> | <value> %d | <right>\"];\n", nodeID, val);
        
        if (a->fg != NULL) {
            fprintf(dot_file, "\tn%d:left:c -> n%d:value;\n", nodeID, nodeID+1);
            res_left = rec_dot_export(a->fg, nodeID+1, dot_file);
        }
        
        if (a->fd != NULL) {
            fprintf(dot_file, "\tn%d:right:c -> n%d:value;\n", nodeID, nodeID+res_left+1);
            res_right = rec_dot_export(a->fd, nodeID+res_left+1, dot_file);
        }
        
        return res_left+res_right+1;
    }
}

void dot_export(arbre a, FILE *dot_file) {
    fprintf(dot_file, "digraph arbre {\n");
    fprintf(dot_file, "\tnode [shape=record,height=.1]\n");
    fprintf(dot_file, "\tedge [tailclip=false,arrowtail=dot,dir=both]\n");
    rec_dot_export(a, 0, dot_file);
    fprintf(dot_file, "}\n");
}

void exportTree(arbre t, char outFileName[]) {
    FILE *out;
    
    if((out=fopen(outFileName,"w"))==NULL){
        fprintf(stderr,"problem opening %s\n",outFileName);
        exit(1);
    }
    
    dot_export(t, out);
    fclose(out);
}

