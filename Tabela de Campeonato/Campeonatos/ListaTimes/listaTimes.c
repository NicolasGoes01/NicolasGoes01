#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaTimes.h"

typedef struct nodeListaTimes_ NODELISTATIMES;

struct nodeListaTimes_
{
    TIME *time;
    NODELISTATIMES* proximo;
};

struct listaTimes_
{
    NODELISTATIMES* inicio;
    NODELISTATIMES* fim;
    int tamanho;
};

LISTATIMES *lista_criar_times()
{
    LISTATIMES *lista = (LISTATIMES *) malloc(sizeof(LISTATIMES));

    if (lista != NULL)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

    return lista;
}

int lista_vazia_times(const LISTATIMES *lista)
{
    if (lista != NULL)
    {
        return lista->inicio == NULL;
    }

    return -1;
}

void lista_inserir_times(LISTATIMES *lista, TIME *time)
{
    if (lista != NULL)
    {
        NODELISTATIMES *novoNode = (NODELISTATIMES *) malloc(sizeof(NODELISTATIMES));

        if (novoNode != NULL)
        {
            novoNode->time = time;
            novoNode->proximo = NULL;

            if (lista_vazia_times(lista))
            {
                lista->inicio = novoNode;
            }

            else
            {
                lista->fim->proximo = novoNode;
            }

            lista->fim = novoNode;
            lista->tamanho++;
        }
    }
}

TIME *lista_busca_sequencial_time(const LISTATIMES *lista, char *time)
{
    if (lista != NULL)
    {
        NODELISTATIMES *noAtual;
        noAtual = lista->inicio;

        while (noAtual != NULL)
        {
            if (strcmp(time, get_nome(noAtual->time)) == 0)
            {
                return noAtual->time;
            }

            noAtual = noAtual->proximo;
        }
    }

    return NULL;
}

void remove_elemento(LISTATIMES *lista, NODELISTATIMES *noAtual)
{
    NODELISTATIMES *node = lista->inicio;
    NODELISTATIMES *nodeAux = NULL;

    while (node != NULL && node != noAtual)
    {
        nodeAux = node;
        node = node->proximo;
    }

    if (node != NULL)
    {
        if (node == lista->inicio)
        {
            lista->inicio = node->proximo;
            node->proximo = NULL;
        }

        else if (node == lista->fim)
        {
            lista->fim = nodeAux;
        }

        else
        {
            nodeAux->proximo = node->proximo;
            node->proximo = NULL;
        }

        lista->tamanho--;
    }
}

void lista_escrever_arquivo_em_ordem_aux(FILE *arq_times, LISTATIMES *lista)
{
    if (lista != NULL)
    {
        NODELISTATIMES *noAtual = lista->inicio;

        while (noAtual != NULL)
        {
            escrever_no_arquivo(arq_times, noAtual->time);
            noAtual = noAtual->proximo;
        }
    }
}

void lista_escrever_arquivo_em_ordem(LISTATIMES *lista, char *campeonato, char *nomeDeUsuario)
{
    FILE *arq_times = abrir_arquivo_times(campeonato, nomeDeUsuario);
    lista_escrever_arquivo_em_ordem_aux(arq_times, lista);
    fclose(arq_times);
}

void lista_adicionar_pontuacao(TIME *time1, TIME *time2, int placar1, int placar2)
{
    adicionar_pontuacao(time1, time2, placar1, placar2);
    adicionar_gols(time1, time2, placar1, placar2);
}

void adicionar_resultado(TIME *time, char *campeonato, char *nomeDeUsuario)
{
    LISTATIMES *lista = lista_criar_times();
    adicionar_times_na_lista(lista, time, campeonato, nomeDeUsuario);

    TIME *time_1;
    TIME *time_2;
    char time1[30];
    char time2[30];
    int placar1;
    int placar2;
    int confirma;

    printf("Digite os times para adicionar o resultado:\n");
    do
    {
        printf("Time 1: ");
        scanf(" %[^(\n|\r)]%*c", time1);

        time_1 = lista_busca_sequencial_time(lista, time1);

        if (time_1 == NULL)
        {
            printf("Time nao encontrado! Digite novamente!\n\n");
        }
        else
        {
            printf("\nTime escolhido: %s\n\n", get_nome(time_1));
        }
    } while(time_1 == NULL);

    do
    {
        printf("Time 2: ");
        scanf(" %[^(\n|\r)]%*c", time2);

        time_2 = lista_busca_sequencial_time(lista, time2);

        if (time_2 == NULL)
        {
            printf("Time nao encontrado! Digite novamente!\n\n");
        }
        else
        {
            printf("\nTime escolhido: %s\n\n", get_nome(time_2));
        }
    } while(time_2 == NULL);

    do
    {
        printf("\nAgora, digite o placar do jogo:\n");
        printf("%s: ", time1);
        scanf("%d", &placar1);
        printf("%s: ", time2);
        scanf("%d", &placar2);

        printf("\n%s %d x %d %s\n", time1, placar1, placar2, time2);
        do
        {
            printf("Deseja confirmar o placar?\n[1] Sim\n[0] Nao\n");
            scanf("%d", &confirma);
            if (confirma != 1 && confirma != 0)
            {
                printf("Digite um numero valido!\n");
            }
        } while(confirma != 1 && confirma != 0);

        if (confirma == 1)
        {
            printf("\nPlacar adicionado com sucesso!\n\n");
        }
    } while(confirma != 1);

    lista_adicionar_pontuacao(time_1, time_2, placar1, placar2);
    lista_escrever_arquivo_em_ordem(lista, campeonato, nomeDeUsuario);
}

void lista_editar_time(TIME *time_, char *campeonato, char *nomeDeUsuario)
{
    LISTATIMES *lista = lista_criar_times();
    adicionar_times_na_lista(lista, time_, campeonato, nomeDeUsuario);

    int verificador;
    char time[30];
    char novo_nome[30];

    do
    {
        printf("\nDigite o nome do time que deseja editar: ");
        scanf(" %[^(\n|\r)]%*c", time);

        time_ = lista_busca_sequencial_time(lista, time);

        if (time_ == NULL)
        {
            printf("Time nao encontrado! Tente novamente!\n\n");
        }

        else
        {
            printf("\nTime escolhido: %s\n\n", get_nome(time_));
        }
    } while(time_ == NULL);

    do
    {
        printf("Digite o novo nome do time: ");
        scanf(" %[^(\n|\r)]%*c", novo_nome);

        printf("Tem certeza que deseja mudar o nome do clube de '%s' para '%s'?\n[1] SIM\n"
               "[0] NAO\n\n", time, novo_nome);
        scanf("%d", &verificador);

        if (verificador != 1 && verificador != 0)
        {
            printf("Digite um numero valido!\n");
        }
    } while(verificador != 0 && verificador != 1);

    if (verificador == 1)
    {
        editar_time(time_, novo_nome);
        lista_escrever_arquivo_em_ordem(lista, campeonato, nomeDeUsuario);
        printf("Nome alterado com sucesso!\n\n");
    }
}

void adicionar_times_na_lista(LISTATIMES *lista, TIME *time, char *campeonato, char *nomeDeUsuario)
{
    FILE *arq_times = abrir_arquivo_times(campeonato, nomeDeUsuario);

    int time_size = get_times_size(arq_times);

    for (int i = 0; i < time_size; i++)
    {
        fseek(arq_times, i * get_times_size_bytes(arq_times), SEEK_SET);
        time = read_teams(arq_times);
        lista_inserir_times(lista, time);
    }

    fclose(arq_times);
}

void esvaziar_lista(NODELISTATIMES *noAtual, LISTATIMES *lista)
{
    if (noAtual != NULL)
    {
        if (noAtual->proximo != NULL && noAtual != lista->fim->proximo)
        {
            esvaziar_lista(noAtual->proximo, lista);
        }

        free(noAtual);
        noAtual = NULL;
    }
}


void apagar_lista_times(LISTATIMES **lista)
{
    if (*lista == NULL)
    {
        return;
    }

    esvaziar_lista((*lista)->inicio, *lista);

    free(*lista);
    *lista = NULL;
}
