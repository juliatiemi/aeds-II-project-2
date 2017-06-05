#include "TAD.h"
#include "PILHA.h"

int main(int argc, char const *argv[]) {
  Labirinto *lab;
  int i, j;
  int **resultado;
  FILE *arq;
  arq = fopen(argv[2], "w");
  lab = LeLabirinto(argv[1]);
  resultado = calloc(lab->N , sizeof(int*));
  for (i = 0; i < lab->N; i++) {
    resultado[i] = calloc(lab->N , sizeof(int));
  }
  if(strcmp(argv[3], "0") == 0) {
    CaminhaLabirintoRecursivo(lab, lab->x, lab->y, resultado);
    for(i = 0; i < lab->N; i++) {
      for(j = 0; j < lab->N; j++) {
        fprintf(arq, "%d ", resultado[i][j]);
      }
      fprintf(arq, "\n");
    }
  }
  if(strcmp(argv[3], "0") == 1) {
    printf("Infelizmente nao foi possivel completar o trabalho pratico.\n");
  }
  for(i = 0; i < lab->N; i++) {
    free(lab->mapa[i]);
  }
  free(lab->mapa);
  for(i = 0; i < lab->N; i++) {
    free(resultado[i]);
  }
  free(resultado);
  free(lab);
  return 0;
}
