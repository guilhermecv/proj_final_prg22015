/**
 * @file main.c
 *
 * @author Guilherme Camargo Valese
 *
 * Árvore de espalhamento mínimo, utilizando algoritmo de Kruskal
 */
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "dados.h"

//#include "kruskal.h"

#define V     5     // Vertices
#define E     5     // Arestas
#define FILENAME  "dados.txt"
#define GRAFO_ORIGINAL  "graph.dot"
#define GRAFO_ORDENADO  "graph2.dot"

/**
  TODO
  [ ] Gerar grafo
  [ ] Exportar grafo
  [ ] algoritmo MST
*/

int main(void)
{
  printf("\nArvore de espalhamento minimo");

  int n_linhas = read_n_lines(FILENAME);
  grafo_t *grafo;
  grafo = cria_grafo(n_linhas);


  dot_export(GRAFO_ORIGINAL, grafo, n_linhas);

  // kruskal_mst(grafo);  // Realiza a ordenacao

  libera_grafo(grafo);

  return EXIT_SUCCESS;
}
