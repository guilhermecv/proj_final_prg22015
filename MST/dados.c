/**
 * @file dados.c
 *
 * @author Guilherme Camargo Valese
 */
#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

/**
 * @brief Le a quantidade de linhas de um arquivo de texto
 * @param *filename: nome do arquivo a ser lido
 *
 * @return int: linhas lidas
 */
int read_n_lines(const char *filename)
{
  FILE *fp;
  fp = fopen(filename, "r");

  if(!fp)
  {
    perror("\nread_n_lines()");
    exit(EXIT_FAILURE);
  }

  int n_linhas = 0;
  int id_fonte, id_destino;
  float data;

  while(!feof(fp))
  {
    fscanf(fp, "%d %d %f", &id_fonte, &id_destino, &data);
    n_linhas++;
  }

#ifdef DEBUG_ON
  printf("\n[DEBUG] %d linhas lidas no arquivo\n", n_linhas);
#endif

  return n_linhas;
}

/**
 * @brief
 */
void constroi_grafo(grafo_t *grafo, const char *filename)
{
  FILE *fp;
  fp = fopen(filename, "r");

  if(!fp || grafo == NULL)
  {
    perror("\nconstroi_grafo()");
    exit(EXIT_FAILURE);
  }

  int id_fonte, id_destino;
  float data;

  while(!feof(fp))
  {
    fscanf(fp, "%d %d %f", &id_fonte, &id_destino, &data);

    cria_adjacencia(grafo, id_fonte, id_destino);
    vertice_set_peso(grafo, id_fonte, data);

#ifdef DEBUG_ON
    printf("[DEBUG] %d, %d, %.2f\n", id_fonte, id_destino, data);
#endif
  }

}
