/******************************************
 *
 * Nom du fichier : afn.h
 *
 * Description: header de afn.c
 *
 ******************************************/


#include "ensemble.h"
#include "pile.h"

typedef struct
{
    ensemble transition[TAILLE][TAILLE];
    ensemble initial;
    ensemble final;
} afn;

//Crée et remplis un afn
void afn_initAfn(afn *a);

// Crée un afn vide;
void afn_initAfnVide(afn *a);

void afn_successeurPartie(afn a,ensemble depart,char c,ensemble succ);

// Determinise l'afn a et remplit le tableau des correspondances.
int afn_determiniser(afn *a, afn *b, ensemble *corres);

// Renvoie 1 si le mot est reconnu par l'afn a
int afn_estReconnu(afn *a, char *mot);

// Affiche toutes les transitions de l'afn a
void afn_afficherTrans(afn *a);

// Renvoie l'état q de la transition (p,x,q)
int afn_existeTransition(afn *a,int p,char x);

/*
// Calcul l'ensemble des états accessibles de a
void afn_accessibles(afn a, ensemble accessible);

// Calul l'ensemble des états co-accessibles de a
void afn_coAccessibles(afn a, ensemble coAccessible);

// Emonde l'AFN a
void afn_emonder(afn a);
*/

/*
//Calcule les successeurs d'un état
void afn_successeur(afn a, int etat, ensemble succ);

//Calcule les prédecesseurs d'un état
void afn_predecesseur(afn a, int etat, ensemble pre);
*/


