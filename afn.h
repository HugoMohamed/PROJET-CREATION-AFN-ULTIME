#include "ensemble.h"

#define TAILLE 1000
typedef char* alphabet[TAILLE];

typedef struct
{
  ensemble transition[TAILLE][TAILLE];
  ensemble i;
  ensemble f;
} afn;
