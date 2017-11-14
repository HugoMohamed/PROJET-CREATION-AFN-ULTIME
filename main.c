#include "afn.h"

int main(int argc, char *argv[])
{
    int tab[TAILLE]={5,6,8};
    int tabA[TAILLE] = {4,5,6,89};
    int tabB[TAILLE] = {6,7,8,9,12,89};

    afn a;

    a = afn_initAfn();
    afn_afficherTrans(a);
    afn_emonder(a);
    printf("TRANS EMONDER\n");
    afn_afficherTrans(a);
    
    
    exit(0);
} 
