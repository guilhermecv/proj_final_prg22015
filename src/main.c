/**
 * @file main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"

#define FILENAME      "150x150.txt"

void dot_export(grafo_t *g, int n_linhas);

int main(void)
{
  grafo_t *g;

  int n_linhas = 0;
  int id_fonte, id_destino;
  float data;

  FILE *fp;
  fp = fopen(FILENAME, "r");
  if(!fp)
  {
    perror("open_file()");
    exit(-1);
  }

  while(!feof(fp))
  {
    fscanf(fp, "%d %d %f", &id_fonte, &id_destino, &data);
    n_linhas++;
  }

  printf("\ncriando grafo com %d vertices\n", n_linhas);
  g = cria_grafo(n_linhas);
  rewind(fp);

  while(!feof(fp))
  {
    fscanf(fp, "%d %d %f", &id_fonte, &id_destino, &data);

    cria_adjacencia(g, id_fonte, id_destino);

#ifdef DEBUG_ON
    printf("%d, %d, %.2f\n", id_fonte, id_destino, data);
#endif
  }


  printf("\nTotal de linhas lidas: %d\n", n_linhas);

  dot_export(g, n_linhas);

  
	libera_grafo(g);

  return EXIT_SUCCESS;
}

/**
 * @brief Exporta os dados em formato DOT
 * @param g: grafo a ser exportado
 */
void dot_export(grafo_t *g, int n_linhas)
{
	int i,j;
	FILE *fp;
	fp = fopen("graph.dot", "w");

	if(fp == NULL)
	{
		perror("dot_export");
		exit(EXIT_FAILURE);
	}

	fprintf(fp, "graph {\n");	// Cria o cabeçalho do arquivo

	for (i=0; i < n_linhas; i++){
		for (j=i; j < n_linhas; j++)
		if(adjacente(g, i, j))
			fprintf(fp, "\t%d -- %d\n", i, j);
	}

	fprintf(fp, "}");
	fclose(fp);
}
