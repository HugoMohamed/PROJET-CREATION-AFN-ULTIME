#include "afn.h"

int main(int argc, char *argv[])
{
    int i,n;
    ensemble corres[TAILLE];
    afn a,b;
    char mot[TAILLE];
    
    if(argc < 2)
    {
	fprintf(stderr,"Usage :\n%s 1 : determinisation\n%s 2 : reconnaissance d'un mot\n",argv[0],argv[0]);
	exit(-1);
    }
    n = afn_determiniser(&a,&b,corres);

    if(atoi(argv[1]) == 1)
    {
	// affiche les transitions
	fprintf(stdout,"Liste des transitions :\n");
	afn_afficherTrans(&b);
	// correspondances
	fprintf(stdout,"Avec les correspondances :\n");
	for(i=1;i<n;i++)
	{
	    fprintf(stdout,"%d = ",i);
	    ens_afficher(corres[i]);
	}
    }
    else if(atoi(argv[1]) == 2)
    {
	fprintf(stdout,"Entrez le mot à reconnaitre :\n");
	fscanf(stdin,"%s",mot);

	if(afn_estReconnu(&b,mot))
	    fprintf(stdout,"Le mot %s est reconnu par l'afn.\n",mot);
	else
	    fprintf(stdout,"Le mot %s n'est pas reconnu par l'afn.\n",mot);
    }
    exit(0);
} 
