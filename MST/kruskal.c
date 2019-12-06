/**
 * @file kruskal.c
 *
 * @author Guilherme Camargo Valese
 */
#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

/**
 * @brief
 * @param *grafo: ponteiro para o grafo
 * @return nenhum
 */
void kruskal_mst(grafo_t *grafo)
{
  if(grafo == NULL)
  {
    perror("kruskal_mst()");
    exit(EXIT_FAILURE);
  }


}
