#ifndef _TAD_H_
#define _TAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------------------------------------------------------------
Estrutura: Labirinto
Função: Armazenar os dados do mapa do labirinto
Variáveis:
  N: Dimensão da matriz do labirinto
  x, y: par de coordenadas da localização da entrada do labirinto
  sx, sy: par de coordenadas da localização da espada
  mapa: matriz que representa o "mapa" do labirinto
---------------------------------------------------------------*/
typedef struct {
  int N;
  int x;
  int y;
  int sx;
  int sy;
  unsigned char **mapa;
} Labirinto;

/*---------------------------------------------------------------
Protótipo: Labirinto* LeLabirinto(const char *entrada)
Função: ler o arquivo de entrada e armazenar seus dados numa estrutura Labirinto
Entrada: um dos argumentos de entrada dados na execução do programa
Saída: um ponteiro para uma estrutura Labirinto com os dados do mapa da labirinto
---------------------------------------------------------------*/
Labirinto* LeLabirinto(const char *entrada);

/*---------------------------------------------------------------
Protótipo: int CaminhaLabirintoRecursivo(Labirinto* lab, int x, int y, int **sol)
Função: encontrar o caminho da entrada até a espada, se possível, utilizando recursividade
Entrada: uma estrutura do tipo Labirinto, duas variáveis inteiras - x e y - que representam a posição atual do caminhamento e a matriz solução do caminho encontrado
Saída: um inteiro 0 ou 1
---------------------------------------------------------------*/
int CaminhaLabirintoRecursivo(Labirinto* lab, int x, int y, int **sol);

#endif
