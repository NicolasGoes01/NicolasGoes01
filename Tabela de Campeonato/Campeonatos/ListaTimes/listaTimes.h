#ifndef AVL_H
#define AVL_H

#include "../Times/times.h"
#include "../Arquivo/arquivo.h"

typedef struct listaTimes_ LISTATIMES;

LISTATIMES *lista_criar_times();
void lista_inserir_times(LISTATIMES *lista, TIME *time);
TIME *lista_busca_sequencial_time(const LISTATIMES *lista, char *time);
void adicionar_resultado(TIME *time, char *campeonato, char *nomeDeUsuario);
void lista_editar_time(TIME *time_, char *campeonato, char *nomeDeUsuario);
void adicionar_times_na_lista(LISTATIMES *lista, TIME *time, char *campeonato, char *nomeDeUsuario);
void apagar_lista_times(LISTATIMES **lista);

#endif //AVL_H
