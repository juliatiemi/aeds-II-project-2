#include "PILHA.h"

void FazPilha(Pilha *pilha) {
  pilha->topo = (Apontador) malloc(sizeof(Celula));
  pilha->fundo = pilha->topo;
  pilha->topo->prox = NULL;
  pilha->tamanho = 0;
}

int Vazia(Pilha pilha) {
  return (pilha.topo == pilha.fundo);
}

void Empilha(Item x, Pilha *pilha) {
  Apontador novacabeca;
  novacabeca = (Apontador) malloc(sizeof(Celula));
  pilha->topo->item = x;
  novacabeca->prox = pilha->topo;
  pilha->topo = novacabeca;
  pilha->tamanho++;
}

int Desempilha(Pilha *pilha, Item *x) {
  Apontador removido;
  if (Vazia(*pilha)) {
    return  0;
  }
  removido = pilha->topo;
  pilha->topo = removido->prox;
  *x = removido->prox->item;
  free(removido);
  pilha->tamanho--;
  return 1;
}

int Tamanho(Pilha pilha) {
  return (pilha.tamanho);
}
