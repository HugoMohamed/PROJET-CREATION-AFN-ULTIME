#include "ensemble.h"

typedef int pile[TAILLE];

// Initialise la pile en mettant toutes ses valeurs a 0
void pile_initVide(pile p);

// Empile l'élément "element" sur la pile p
void pile_empiler(pile p, int element);

// Depile la pile p (enleve l'élément sur le haut de la pile)
void pile_depiler(pile p);

// Affiche tout les éléments de la pile p
void pile_afficher(pile p);

// Retourne l'élément en sommet de pile
int pile_hautPile(pile p);
