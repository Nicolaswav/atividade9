// lista.c
#include "lista.h"
#include <stdlib.h>

No* criar_no(float valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no != NULL) {
        novo_no->valor = valor;
        novo_no->proximo = NULL;
    }
    return novo_no;
}

void lista_inserir_no_ordenado(No* L, No* no) {
    while (L->proximo != NULL && L->proximo->valor < no->valor) {
        L = L->proximo;
    }
    no->proximo = L->proximo;
    L->proximo = no;
}

void imprimir_lista(No* L) {
    while (L != NULL) {
        printf("%.2f -> ", L->valor);
        L = L->proximo;
    }
    printf("NULL\n");
}

void liberar_lista(No* L) {
    No* aux;
    while (L != NULL) {
        aux = L;
        L = L->proximo;
        free(aux);
    }
}

