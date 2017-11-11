/******************************************
 *
 * Nom du fichier : afn.h
 *
 * Description: header de afn.c
 *
 ******************************************/


#include "ensemble.h"

#define TAILLE 1000
typedef char* alphabet[TAILLE];

typedef struct
{
    ensemble transition[TAILLE][TAILLE];
    ensemble i;
    ensemble f;
} afn;

// Renvoie 1 si l'état en paramètre est puit et 0 sinon
int afn_estPuit(afn a, int etat);

// Emonde l'AFN a
void afn_emonder(afn a);

// Determinise l'AFN a
void afn_determiniser(afn a);
