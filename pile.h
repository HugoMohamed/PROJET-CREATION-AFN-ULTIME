#include "afn.h"

typedef int pile[TAILLE];


void pile_initVide(pile p);

void pile_empiler(pile p, int element);

void pile_depiler(pile p);

void pile_afficher(pile p);

int pile_hautPile(pile p);
