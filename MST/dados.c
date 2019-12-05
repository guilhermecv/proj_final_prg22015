/**
 * @file dados.c
 *
 * @author Guilherme Camargo Valese
 */
#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

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
