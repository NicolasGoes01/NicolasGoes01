#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct nodeLista_ NODELISTA;

struct nodeLista_
{
    CAMPEONATO *campeonato;
    NODELISTA* proximo;
};

struct lista_
{
    NODELISTA* inicio;
    NODELISTA* fim;
    int tamanho;
};

LISTA *lista_criar()
{
    LISTA *lista = (LISTA *) malloc(sizeof(LISTA));

    if (lista != NULL)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

    return lista;
}

int lista_vazia(const LISTA *lista)
{
    if (lista != NULL)
    {
        return lista->inicio == NULL;
    }

    return -1;
}

void lista_inserir(LISTA *lista, CAMPEONATO *campeonato)
{
    if (lista != NULL)
    {
        NODELISTA *novoNode = (NODELISTA *) malloc(sizeof(NODELISTA));

        if (novoNode != NULL)
        {
            novoNode->campeonato = campeonato;
            novoNode->proximo = NULL;

            if (lista_vazia(lista))
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

CAMPEONATO *lista_busca_sequencial(const LISTA *lista, char *campeonatoSTR)
{
    if (lista != NULL)
    {
        NODELISTA *noAtual;
        noAtual = lista->inicio;

        while (noAtual != NULL)
        {
            if (strcmp(campeonatoSTR, get_campeonato(noAtual->campeonato)) == 0)
            {
                return noAtual->campeonato;
            }

            noAtual = noAtual->proximo;
        }
    }

    return NULL;
}

LISTA *lista_remover_item(LISTA *lista, const char *campeonato)
{
    if (lista != NULL)
    {
        NODELISTA *noAtual = lista->inicio;
        NODELISTA *noAnterior = NULL;

        while (noAtual != NULL && (strcmp(get_campeonato(noAtual->campeonato), campeonato)) != 0)
        {
            noAnterior = noAtual;
            noAtual = noAtual->proximo;
        }

        if (noAtual != NULL)
        {
            if (noAtual == lista->inicio)
            {
                lista->inicio = noAtual->proximo;
                noAtual->proximo = NULL;
            }

            else
            {
                noAnterior->proximo = noAtual->proximo;
                noAtual->proximo = NULL;
            }

            if (lista->fim == noAtual)
            {
                lista->fim = noAnterior;
            }
        }

        return lista;
    }

    return NULL;
}

void adicionar_na_lista(FILE *arq_campeonato, LISTA *lista, CAMPEONATO *campeonato, char *nomeDeUsuario)
{
    arq_campeonato = abrir_arquivo_campeonatos(nomeDeUsuario);

    fseek(arq_campeonato, 0, SEEK_END);
    int size = ftell(arq_campeonato) / 50;

    for (int i = 0; i < size; i++)
    {
        fseek(arq_campeonato, i * 50, SEEK_SET);
        campeonato = receber_dados_campeonato(arq_campeonato);
        lista_inserir(lista, campeonato);
    }

    fclose(arq_campeonato);
}

void lista_escrever_arquivo(FILE *arq_campeonato, LISTA *lista)
{
    if (lista != NULL)
    {
        NODELISTA *noAtual;
        noAtual = lista->inicio;

        while (noAtual != NULL)
        {
            escrever_no_arquivo_campeonato(arq_campeonato, noAtual->campeonato);
            noAtual = noAtual->proximo;
        }
    }
}

void lista_escrever_arquivo_aux(LISTA *lista, char *nomeDeUsuario)
{
    char championshipList[100];
    strcpy(championshipList, "championship list");
    strcat(championshipList, "_");
    strcat(championshipList, nomeDeUsuario);
    strcat(championshipList, ".txt");

    remove(championshipList);
    FILE *arq_campeonato = abrir_arquivo_campeonatos(nomeDeUsuario);
    lista_escrever_arquivo(arq_campeonato, lista);
    fclose(arq_campeonato);
}

void adicionar_campeonato(LISTA *lista, TIME *time, char *nomeDeUsuario)
{
    FILE *arq_campeonato = abrir_arquivo_campeonatos(nomeDeUsuario);
    AVLTIMES *avl = criar_arvore_avl();
    CAMPEONATO *campeonato;
    char campeonatoSTR[50];
    int qtd_times;

    do
    {
        printf("Digite o nome do campeonato que deseja adicionar: ");
        scanf(" %[^(\n|\r)]%*c", campeonatoSTR);

        campeonato = lista_busca_sequencial(lista, campeonatoSTR);

        if (campeonato != NULL)
        {
            printf("Nome ja existente! Digite novamente!\n\n");
        }
    } while(campeonato != NULL);

    campeonato = campeonato_criar(campeonatoSTR);
    lista_inserir(lista, campeonato);

    printf("Digite a quantidade de times que o campeonato terá: ");
    scanf("%d", &qtd_times);

    printf("Escreva o nome dos times participantes:\n\n");

    for (int i = 0; i < qtd_times; i++)
    {
        printf("Time %d: ", i + 1);
        time = adiciona_times();
        avl_inserir(avl, time);
    }

    reescreve_avl_ordenada(avl, time, campeonatoSTR, nomeDeUsuario);

    printf("\nCampeonato adicionado com sucesso!\n\n");

    fclose(arq_campeonato);
}

void apagar_campeonato(LISTA *lista, CAMPEONATO *campeonato, char *nomeDeUsuario)
{
    char campeonatoSTR[50];
    int opcao;

    do
    {
        printf("Digite o nome do campeonato que deseja apagar: ");
        scanf(" %[^(\n|\r)]%*c", campeonatoSTR);

        campeonato = lista_busca_sequencial(lista, campeonatoSTR);

        if (campeonato == NULL)
        {
            printf("\nCampeonato nao encontrado! Tente Novamente\n\n");
        }
    } while(campeonato == NULL);

    do
    {
        printf("TEM CERTEZA QUE DESEJA APAGAR O CAMPEONATO '%s'?\n[1] SIM\n[0] NAO\n", campeonatoSTR);
        scanf("%d", &opcao);

        if (opcao != 0 && opcao != 1)
        {
            printf("\nNumero invalido! Tente Novamente\n\n");
        }
    } while(opcao != 0 && opcao != 1);

    if (opcao == 1)
    {
        lista = lista_remover_item(lista, campeonatoSTR);
        lista_escrever_arquivo_aux(lista, nomeDeUsuario);
        strcat(campeonatoSTR, "_");
        strcat(campeonatoSTR, nomeDeUsuario);
        strcat(campeonatoSTR, ".dat");
        remove(campeonatoSTR);
        printf("\nCampeonato apagado com sucesso!\n\n");
    }
}

void apagar_lista(LISTA *lista)
{
    NODELISTA *noAtual = lista->inicio;
    NODELISTA *noAux;

    while (noAtual != NULL)
    {
        noAux = noAtual->proximo;
        apagar_tudo_campeonato(&noAtual->campeonato);
        free(noAtual);
        noAtual = noAux;
    }
}
