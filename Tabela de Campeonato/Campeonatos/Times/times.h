#ifndef TIMES_H
#define TIMES_H

#define ERRO (-32000)

typedef struct times_ TIME;

TIME *adiciona_times();
TIME *read_teams(FILE *arq_times);
int get_times_size(FILE *arq_times);
int get_times_size_bytes(FILE *arq_times);
void adicionar_pontuacao(TIME *time1, TIME *time2, int placar1, int placar2);
void adicionar_gols(TIME *time1, TIME *time2, int placar1, int placar2);
void editar_time(TIME *time, char *novo_nome);
void zera_tudo(TIME *time);
void escrever_no_arquivo(FILE *arq_times, TIME *time);
char *get_nome(TIME *time);
int get_pontos(TIME *time);
int get_vitorias(TIME *time);
int get_golsPro(TIME *time);
int get_saldo(TIME *time);
void desenha_tabela_aux(TIME *time, int *posicao);
void item_apagar(TIME **time);

#endif //TIMES_H
