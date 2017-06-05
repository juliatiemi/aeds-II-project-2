#ifndef _PILHA_H_
#define _PILHA_H_

#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------------------------
Estrutura: Item
Função: Definir o tipo item de uma pilha e armazenar seus componentes, nesse caso, duas coordenadas
Variáveis:
  x, y: par de coordenadas
---------------------------------------------------------------*/
typedef struct {
  int x;
  int y;
} Item;

typedef struct TipoCelula *Apontador;

/*---------------------------------------------------------------
Estrutura: Celula
Função: Definir o tipo celula de uma pilha, ou seja, cada "prato" dela
Variáveis:
  item: variável do tipo Item com as informações dos componentes
  prox: apontador para um tipo Celula
---------------------------------------------------------------*/
typedef struct TipoCelula {
  Item item;
  Apontador prox;
} Celula;

/*---------------------------------------------------------------
Estrutura: Pilha
Função: Definir uma estrutura do tipo pilha
Variáveis:
  topo, fundo: apontadores para a primeira e última células dessa pilha
  tamanho: quantidade de células presentes na pilha em um momento
---------------------------------------------------------------*/
typedef struct {
  Apontador topo;
  Apontador fundo;
  int tamanho;
} Pilha;

/*---------------------------------------------------------------
Protótipo: FazPilha(Pilha *pilha)
Função: inicializar uma nova pilha com os atributos de uma pilha vazia
Entrada: um ponteiro para uma estrutura do tipo Pilha
Saída: N/A
---------------------------------------------------------------*/
void FazPilha(Pilha *pilha);

/*---------------------------------------------------------------
Protótipo: Vazia(Pilha pilha)
Função: verificar se a pilha está vazia
Entrada: uma estrutura do tipo Pilha
Saída: um inteiro, 0 ou 1, definindo se ela está vazia (true) ou não (false)
---------------------------------------------------------------*/
int Vazia(Pilha pilha);

/*---------------------------------------------------------------
Protótipo: Empilha(Item x, Pilha *pilha)
Função: criar e adicionar uma nova célula no topo da pilha para adicionar um novo item
Entrada: uma estrutura do tipo Item e um ponteiro para uma estrutura do tipo Pilha
Saída: N/A
---------------------------------------------------------------*/
void Empilha(Item x, Pilha *pilha);

/*---------------------------------------------------------------
Protótipo: Desempilha(Pilha *pilha, Item *x)
Função: remover e liberar uma célula no topo da pilha, savando o item dessa célula
Entrada: um ponteiro para uma estrutura do tipo Item e um ponteiro para uma estrutura do tipo Pilha
Saída: um inteiro, 0 ou 1, sendo 0 caso a pilha estiver vazia e não puder desempilhar e 1 caso o desempilhamento tenha sido bem sucedido
---------------------------------------------------------------*/
int Desempilha(Pilha *pilha, Item *x);

/*---------------------------------------------------------------
Protótipo: Tamanho(Pilha pilha)
Função: retornar quantas células existem na pilha
Entrada: uma estrutura do tipo Pilha
Saída: um inteiro que representa a quantidade de células
---------------------------------------------------------------*/
int Tamanho(Pilha pilha);

#endif
