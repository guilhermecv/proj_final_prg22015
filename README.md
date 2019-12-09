# proj_final_prg22105
Projeto final da disciplina de Programação de Computadores 2 (Estrutura de dados)

Algoritmo: Árvore de espalhamento mínimo
Aluno: Guilherme Camargo Valese (guilherme.valese@hotmail.com)



Árvore de espalhamento mínimo é definida como o caminho de menor custo que conecte todas as arestas de um grafo. O custo de cada aresta é seu peso associado, de forma que o custo total de um grafo é o somatório dos pesos das arestas.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d2/Minimum_spanning_tree.svg/300px-Minimum_spanning_tree.svg.png)

Existem diversos algoritmos para MST, sendo os mais comuns



- Kruskal (aplicado a este trabalho)

- Prim

- Sollin

  

### Algoritmos Utilizidados



------

## Instalação

Dependências 

1. **graphviz**

2. **valgrind (opcional)**

   

**Clone o repositório**

**Digite os comandos abaixo**

```bash
$ cd proj_final_prg22105/src
$ make
$ ./main
$ ./makegraph.sh
```

Para teste de acesso à memória, execute os comandos abaixo *(necessário ter o **valgrind** instalado)*

```bash
$ cd proj_final_prg22105/src
$ make
$ ./valgrind_test.sh	# executa o teste de memória (opcional)
```



