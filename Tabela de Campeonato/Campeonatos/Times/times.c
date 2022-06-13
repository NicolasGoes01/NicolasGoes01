#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "times.h"

struct times_
{
    char nome[30];
    int pontos;
    int jogados;
    int vitorias;
    int empates;
    int derrotas;
    int golsPro;
    int golsContra;
    int saldo;
};

TIME *item_criar(char *nome, int pontos, int jogados, int vitorias, int empates, int derrotas, int golsPro, int golsContra, int saldo)
{
    TIME *time;

    time = (TIME *) malloc(sizeof(TIME));

    if (time != NULL)
    {
        strcpy(time->nome, nome);
        time->pontos = pontos;
        time->jogados = jogados;
        time->vitorias = vitorias;
        time->empates = empates;
        time->derrotas = derrotas;
        time->golsPro = golsPro;
        time->golsContra = golsContra;
        time->saldo = saldo;

        return time;
    }

    return NULL;
}

TIME *adiciona_times()
{
    TIME time;

    scanf(" %[^(\n|\r)]%*c", time.nome);
    time.pontos = 0;
    time.jogados = 0;
    time.vitorias = 0;
    time.empates = 0;
    time.derrotas = 0;
    time.golsPro = 0;
    time.golsContra = 0;
    time.saldo = 0;

    return item_criar(time.nome, time.pontos, time.jogados, time.vitorias, time.empates,
                       time.derrotas, time.golsPro, time.golsContra,
                            time.saldo);
}

TIME *read_teams(FILE *arq_times)
{
    if (arq_times != NULL)
    {
        TIME *time = (TIME *) malloc(sizeof(TIME));

        fread(time, sizeof(TIME), 1, arq_times);

        return time;
    }

    return NULL;
}

int get_times_size(FILE *arq_times)
{
    if (arq_times != NULL)
    {
        fseek(arq_times, 0, SEEK_END);
        return ftell(arq_times) / sizeof(TIME);
    }

    return ERRO;
}

int get_times_size_bytes(FILE *arq_times)
{
    if (arq_times != NULL)
    {
        return sizeof(TIME);
    }

    return ERRO;
}

void adicionar_pontuacao(TIME *time1, TIME *time2, int placar1, int placar2)
{
    if (placar1 > placar2)
    {
        time1->pontos += 3;

        (time1->vitorias)++;
        (time2->derrotas)++;

        (time1->jogados)++;
        (time2->jogados)++;
    }

    else if (placar1 < placar2)
    {
        time2->pontos += 3;

        (time2->vitorias)++;
        (time1->derrotas)++;

        (time1->jogados)++;
        (time2->jogados)++;
    }

    else
    {
        (time1->pontos)++;
        (time2->pontos)++;

        (time1->empates)++;
        (time2->empates)++;

        (time1->jogados)++;
        (time2->jogados)++;
    }
}

void adicionar_gols(TIME *time1, TIME *time2, int placar1, int placar2)
{
    time1->golsPro += placar1;
    time1->golsContra += placar2;
    time1->saldo = time1->golsPro - time1->golsContra;

    time2->golsPro += placar2;
    time2->golsContra += placar1;
    time2->saldo = time2->golsPro - time2->golsContra;
}

void editar_time(TIME *time, char *novo_nome)
{
    if (time != NULL)
    {
        strcpy(time->nome, novo_nome);
    }
}

void zera_tudo(TIME *time)
{
    if (time != NULL)
    {
        time->pontos = 0;
        time->jogados = 0;
        time->vitorias = 0;
        time->empates = 0;
        time->derrotas = 0;
        time->golsPro = 0;
        time->golsContra = 0;
        time->saldo = 0;
    }
}

void escrever_no_arquivo(FILE *arq_times, TIME *time)
{
    if (time != NULL)
    {
        fwrite(time, sizeof(TIME), 1, arq_times);
    }
}

char *get_nome(TIME *time)
{
    if (time != NULL)
    {
        return time->nome;
    }

    return "ERRO";
}

int get_pontos(TIME *time)
{
    if (time != NULL)
    {
        return time->pontos;
    }

    return 0;
}

int get_vitorias(TIME *time)
{
    if (time != NULL)
    {
        return time->vitorias;
    }

    return 0;
}

int get_golsPro(TIME *time)
{
    if (time != NULL)
    {
        return time->golsPro;
    }

    return 0;
}

int get_saldo(TIME *time)
{
    if (time != NULL)
    {
        return time->saldo;
    }

    return 0;
}

void desenha_tabela_aux(TIME *time, int *posicao)
{
    (*posicao)++;

    if (time->saldo >= 0)
    {
        printf("| %.2d | %-15s |  %.2d  |  %.2d  |  %.2d  |  %.2d  |  %.2d  |  %.2d  "
               "|  %.2d  |  %.2d  |\n", *posicao, time->nome, time->jogados, time->vitorias,
                    time->empates, time->derrotas, time->golsPro, time->golsContra, time->saldo,
                        time->pontos);
    }
    else
    {
        printf("| %.2d | %-15s |  %.2d  |  %.2d  |  %.2d  |  %.2d  |  %.2d  |  %.2d  "
               "| %.2d  |  %.2d  |\n", *posicao, time->nome, time->jogados, time->vitorias,
                    time->empates, time->derrotas, time->golsPro, time->golsContra, time->saldo,
                        time->pontos);
    }
}

void item_apagar(TIME **time)
{
    if (*time != NULL)
    {
        free (*time);
        *time = NULL;
    }
}