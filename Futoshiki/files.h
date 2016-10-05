#ifndef FILES_H
#define FILES_H

#include "table.h"

/* Abrir arquivo */
/* Argumentos *filename (nome do arquivo) */
/* Retorno: *newFile (arquivo aberto) || NULL (erro) */
FILE *openFile(char *filename);

/* Read line */
/* Argumentos: *stream (arquivo de origem) */
/* Retorno: *line (linha lida) || NULL (erro) */
char *readLine(FILE *stream);

/* Ler numero de casos */
/* Argumentos: *stream (arquivo de origem) */
/* Retorno: result (numero de casos) || -1 (erro) */
int readNumberOfCases(FILE *stream);

/* Ler configuracao da tabela */
/* Argumentos: *stream (arquivo de origem) */
/* Retorno: *config ([0]: tamanho da tabela, [1]: numero de inequacoes) || NULL (erro) */
int *readTableConfig(FILE *stream);

/* Ler tabuleiro */
/* Argumentos: size (tamanho do tabuleiro), nInequations (numero de inequacoes), *stream (arquivo de origem) */
/* Retorno: *newGame(jogo lido) || NULL (erro) */
GAME *readGameTable(int size, int nInequations, FILE *stream);

/* Fechar arquivo */
/* Argumentos: *stream (arquivo de origem) */
/* Retorno: nenhum */
void closeFile(FILE *file);

#endif
