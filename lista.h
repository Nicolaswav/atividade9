// lista.h
#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    float valor;
    struct No* proximo;
} No;

No* criar_no(float valor);
void lista_inserir_no_ordenado(No* L, No* no);
void imprimir_lista(No* L);
void liberar_lista(No* L);

#endif

