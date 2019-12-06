#ifndef DADOS_H
#define DADOS_H

#define DEBUG_ON    /* Mensagens de debug */

#include "grafo.h"

int read_n_lines(const char *filename);
void constroi_grafo(grafo_t *grafo, const char *filename);

#endif /* DADOS_H */
