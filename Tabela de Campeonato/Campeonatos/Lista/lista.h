#ifndef LISTA_H
#define LISTA_H

#include "../AVLTimes/avltimes.h"
#include "../ListaTimes/listaTimes.h"
#include "../Campeonato/campeonato.h"
#include "../Arquivo/arquivo.h"

typedef struct lista_ LISTA;

LISTA *lista_criar();
void lista_inserir(LISTA *lista, CAMPEONATO *campeonato);
void adicionar_na_lista(FILE *arq_campeonato, LISTA *lista, CAMPEONATO *campeonato, char *nomeDeUsuario);
void lista_escrever_arquivo_aux(LISTA *lista, char *nomeDeUsuario);
void adicionar_campeonato(LISTA *lista, TIME *time, char *nomeDeUsuario);
void apagar_campeonato(LISTA *lista, CAMPEONATO *campeonato, char *nomeDeUsuario);
void apagar_lista(LISTA *lista);

#endif //LISTA_H
