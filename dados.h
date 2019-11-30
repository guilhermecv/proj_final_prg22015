#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED

/* Criação de tipo abstrato dado_t */
struct dados {
    int year;               /*!< Ano da ocorrência */
    char state[64];         /*!< estado da ocorrência */
    char month[64];         /*!< mês da ocorrência */
    int qtd;                /*!< incêndios no mês */
    char date[64];     
};

typedef struct dados dado_t;

#define DEBUG_ON

/**
  * @brief  Cria um novo dado
  * @retval dado_t: ponteiro para um novo dado
  */
dado_t * criar_dado (int year, char * state, char * month, int qtd, char * date);

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
