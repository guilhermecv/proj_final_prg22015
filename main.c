/**
 * @file main.c
 *
 * @author Guilherme Camargo Valese
 *
 * @description Árvore de espalhamento mínimo
 */
#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

#define FILENAME    "forest_fire_in_brazil.csv"

int main()
{
    int n_linhas;
    dado_t **dados = ler_dados_csv(FILENAME, &n_linhas);
    
    
    liberar_dados(dados, n_linhas);
    
    return EXIT_SUCCESS;
}