/**
 * @file main.c
 *
 * @author Guilherme Camargo Valese
 */

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "dados.h"

#define FILENAME      "rede_optica.csv"   // Nome do arquivo de dados

int main(void)
{
  int n_linhas;
  printf("\nArvore de espalhamento minimo\n");

  dado_t **dados = ler_dados_csv(FILENAME, &n_linhas);
  grafo_t *grafo = cria_grafo(n_linhas);

// CRIA O GRAFO ORIGINAL
  int i;
  for(i = 0; i < n_linhas; i++)
  {
    cria_adjacencia(grafo, dados[i]->origem, dados[i]->destino);
  }
  dot_export("grap.dot", grafo, n_linhas);

  libera_grafo(grafo);
  liberar_dados(dados, n_linhas);

  return EXIT_SUCCESS;
}
