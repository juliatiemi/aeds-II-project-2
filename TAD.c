#include "TAD.h"

Labirinto* LeLabirinto(const char *entrada) {
  Labirinto *labirinto;
  int i, j;
  FILE *arq;
  arq = fopen(entrada, "r");
  if(arq == NULL) {
      printf("Erro ao abrir arquivo.\n");
      exit(1);
  }
  labirinto = malloc(1 * sizeof (Labirinto));
  fscanf(arq, "%d%d%d%d%d", &labirinto->N, &labirinto->x, &labirinto->y, &labirinto->sx, &labirinto->sy);
  labirinto->mapa = malloc(labirinto->N * sizeof(unsigned char*));
  for(i = 0; i < labirinto->N; i++) {
    labirinto->mapa[i] = malloc(labirinto->N * sizeof(unsigned char));
  }
  for(i = 0; i < labirinto->N; i++) {
    for(j = 0; j < labirinto->N; j++) {
      fscanf(arq, "%hhu", &labirinto->mapa[i][j]);
    }
  }
  fclose(arq);
  return labirinto;
}

int CaminhaLabirintoRecursivo(Labirinto *lab, int x, int y, int **sol) {
  if(x == lab->sx && y == lab->sy) {
    sol[x][y] = 1;
    return 1;
  }
  else {
    if(lab->mapa[x][y] == 0 && sol[x][y] == 0) {
      sol[x][y] = 1;
      if(CaminhaLabirintoRecursivo(lab, x+1, y, sol) == 1) {
        return 1;
      }
      if(CaminhaLabirintoRecursivo(lab, x, y+1, sol) == 1) {
        return 1;
      }
      if(CaminhaLabirintoRecursivo(lab, x-1, y, sol) == 1) {
        return 1;
      }
      if(CaminhaLabirintoRecursivo(lab, x, y-1, sol) == 1) {
        return 1;
      }
      sol[x][y] = 0;
    }
  }
  return 0;
}
