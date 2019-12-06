
/* leitura de um arquivo CSV conforme o padrão:
  *         Series;Value;Time
  *         <int>;<float>;<string>
  *         <int>;<float>;<string> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"

// #define DEBUG_ON


/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t * criar_dado (int id, int origem, int destino, int peso){

    dado_t * meu_novo_dado = malloc(sizeof(struct dados));

    meu_novo_dado->id = id;
    meu_novo_dado->origem = origem;
    meu_novo_dado->destino = destino;
    meu_novo_dado->peso = peso;


    return meu_novo_dado;
}


/**
 * @brief Lê os dados de um arquivo CSV
 * @param nome_do_arquivo: nome do arquivo CSV
 * @param n_linhas: total de linhas no arquivo
 *
 * @retval dados: vetor de ponteiros de dados
 */
dado_t **ler_dados_csv(char *nome_do_arquivo, int *n_linhas){
    char texto[64];
    int i=0;
    int id, origem, destino, peso;
    int n_linhas_temp = 0;

    dado_t **dados;

    FILE *fp = fopen(nome_do_arquivo,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    /* Ignora primeira linha */
    fgets(texto,64, fp);

    while(fgets(texto,64, fp) != NULL) // fgets retorna NULL!
    {
#ifdef DEBUG_ON
    	printf("\n %s", texto);
#endif
    	n_linhas_temp++;
    }

#ifdef DEBUG_ON
    printf("\nTotal de linhas: %d\n", n_linhas_temp);
#endif


    /* Aloque memória:
     * Agora é um vetor de ponteiros */
    dados = malloc(sizeof(struct dado *) * n_linhas_temp);

    rewind(fp);	// Volta para o início do arquivo

    fgets(texto,64, fp); /* Ignora a primeira linha */

    while (fscanf (fp, "%d;%d;%d;%d", &id, &origem, &destino, &peso) == 4){
        // printf("Lido %d, %d, %d, %d\n", id, origem, destino, peso);

        /* Cria um novo dado abstrato e armazena a sua referência */
        dados[i] = criar_dado(id, origem, destino, peso);
        i++;
    }

    *n_linhas = n_linhas_temp;	// Atualiza a quantidade de linhas

    fclose(fp);

    return dados;
}

/**
 * @brief Libera a memória alocada para os dados
 * @param **vetor: vetor de ponteiros
 * @param *total: ponteiro para a quantidade de dados lidos
 *
 * @retval: nenhum
 */
void liberar_dados(dado_t **vetor, int total)
{
	if(vetor == NULL)
	{
		fprintf(stderr, "\nliberar_dados: vetor nulo");
		exit(-1);
	}

    int i;

    for(i = 0; i < total; i++)
    {
        free(vetor[i]);
    }
    free(vetor);
}
