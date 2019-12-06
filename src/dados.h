#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED

/* Criação de tipo abstrato dado_t */
struct dados {
    int id;
    int origem;
    int destino;
    int peso;
};

typedef struct dados dado_t;


/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t * criar_dado (int id, int origem, int destino, int peso);

/**
 * @brief Lê os dados de um arquivo CSV
 * @param nome_do_arquivo: nome do arquivo CSV
 * @param n_linhas: total de linhas no arquivo
 *
 * @retval dados: vetor de ponteiros de dados
 */
dado_t **ler_dados_csv(char *nome_do_arquivo, int *n_linhas);

/**
 * @brief Libera a memória alocada para os dados
 * @param **vetor: vetor de ponteiros
 *
 * @retval: nenhum
 */
void liberar_dados(dado_t **vetor, int total);


#endif
