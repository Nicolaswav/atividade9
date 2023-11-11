// main.c
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "1kk_rand_float.csv"

double calcular_tempo_insercao(No* lista, float* valores, int tamanho);

int main() {
    FILE* arquivo = fopen(FILENAME, "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", FILENAME);
        return 1;
    }

    No* lista_nao_ordenada = criar_no(0);  // Cabe�a da lista
    No* lista_ordenada = criar_no(0);      // Cabe�a da lista

    float valor;
    while (fscanf(arquivo, "%f", &valor) == 1) {
        No* novo_no = criar_no(valor);

        // Inser��o na lista n�o ordenada
        lista_inserir_no_ordenado(lista_nao_ordenada, novo_no);

        // Inser��o na lista ordenada
        lista_inserir_no_ordenado(lista_ordenada, novo_no);
    }

    fclose(arquivo);

    // Remover a cabe�a da lista antes de imprimir
    No* lista_nao_ordenada_copia = lista_nao_ordenada->proximo;
    No* lista_ordenada_copia = lista_ordenada->proximo;

    printf("Lista n�o ordenada:\n");
    imprimir_lista(lista_nao_ordenada_copia);

    printf("\nLista ordenada:\n");
    imprimir_lista(lista_ordenada_copia);

    // Liberar a lista
    liberar_lista(lista_nao_ordenada);
    liberar_lista(lista_ordenada);

    return 0;
}

