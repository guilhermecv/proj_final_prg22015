/**
 * @file main.c
 *
 * @author Guilherme Camargo Valese
 *
 * Árvore de espalhamento mínimo utilizando algoritmo de Kruskal
 */

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "dados.h"
#include "selection_sort.h"

#define FILENAME      "rede_optica.csv"   // Nome do arquivo de dados
#define DEBUG_ON

int main(void)
{
  int n_linhas;

  dado_t **dados = ler_dados_csv(FILENAME, &n_linhas);
  grafo_t *grafo = cria_grafo(n_linhas);

  selection_sort(dados, n_linhas);


  // CRIA O GRAFO ORIGINAL
  int i;
  for(i = 0; i < n_linhas; i++)
  {
#ifdef DEBUG_ON
    printf("%d, %d, %d, %d\n", dados[i]->id, dados[i]->origem, dados[i]->destino, dados[i]->peso);
#endif
    cria_adjacencia(grafo, dados[i]->origem, dados[i]->destino);
  }
  dot_export("graph.dot", grafo, n_linhas);

  libera_grafo(grafo);
  liberar_dados(dados, n_linhas);

  return EXIT_SUCCESS;
}
