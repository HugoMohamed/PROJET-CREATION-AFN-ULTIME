/******************************************
 *
 * Nom du fichier : afn.h
 *
 * Description: header de afn.c
 *
 ******************************************/


#include "ensemble.h"

//#define TAILLE 1000
typedef char* alphabet[TAILLE];

typedef struct
{
    char transition[TAILLE][TAILLE];
    ensemble initial;
    ensemble final;
} afn;

//Crée et remplis un afn
afn afn_initAfn();

// Calcul l'ensemble des états accessibles de a
void afn_accessibles(afn a, ensemble accessible);

// Calul l'ensemble des états co-accessibles de a
void afn_coAccessibles(afn a, ensemble coAccessible);

// Emonde l'AFN a
void afn_emonder(afn a);

// Determinise l'AFN a
void afn_determiniser(afn a);

//Calcule les successeurs d'un état
void afn_successeur(afn a, int etat, ensemble succ);

//Calcule les prédecesseurs d'un état
void afn_predecesseur(afn a, int etat, ensemble pre);

// Renvoie 1 si le mot est reconnu par l'afn a
int afn_estReconnu(afn a, char * mot);

// Affiche toutes les transitions de l'afn a
void afn_afficherTrans(afn a);
