#ifndef AVLTIMES_H
#define AVLTIMES_H

#include "../ListaTimes/listaTimes.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define MAIOR 1
#define MENOR 0

typedef struct avltimes_ AVLTIMES;

AVLTIMES *criar_arvore_avl();
int avl_inserir(AVLTIMES *avl, TIME *time);
void avl_adicionar_resultado(AVLTIMES *avl, TIME *time, char *campeonato, char *nomeDeUsuario);
void avl_editar_time(AVLTIMES *avl, TIME *time, char *campeonato, char *nomeDeUsuario);
void zerar_pontuacao(AVLTIMES *avl);
void adicionar_na_arvore_avl(AVLTIMES *avl, TIME *time, char *campeonato, char *nomeDeUsuario);
void reescreve_avl_ordenada(AVLTIMES *avl, TIME *time, char *campeonato, char *nomeDeUsuario);
void avl_desenha_tabela_em_ordem(AVLTIMES *avl);

#endif //AVLTIMES_H
