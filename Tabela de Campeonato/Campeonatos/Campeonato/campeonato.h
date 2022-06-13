#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include <stdio.h>
#include "../Times/times.h"

typedef struct campeonato_ CAMPEONATO;

CAMPEONATO *campeonato_criar(char *nome);
void opcao_campeonato(char *campeonato);
CAMPEONATO *receber_dados_campeonato(FILE *arq_campeonato);
void escrever_no_arquivo_campeonato(FILE *arq_campeonato, CAMPEONATO *campeonato);
void lista_campeonatos(FILE *arq_campeonato, char *nomeDeUsuario);
char *get_campeonato(CAMPEONATO *campeonato);
void apagar_tudo_campeonato(CAMPEONATO **campeonato);

#endif //CAMPEONATO_H
