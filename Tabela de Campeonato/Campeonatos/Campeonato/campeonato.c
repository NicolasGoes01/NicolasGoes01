#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "campeonato.h"

struct campeonato_
{
    char nome[50];
};

CAMPEONATO *campeonato_criar(char *nome)
{
    CAMPEONATO *campeonato;

    campeonato = (CAMPEONATO *) malloc(sizeof(CAMPEONATO));

    if (campeonato != NULL)
    {
        strcpy(campeonato->nome, nome);
        return campeonato;
    }

    return NULL;
}

CAMPEONATO *receber_dados_campeonato(FILE *arq_campeonato)
{
    CAMPEONATO *campeonato = (CAMPEONATO *) malloc(sizeof(CAMPEONATO));

    fread(campeonato->nome, sizeof(char), 50, arq_campeonato);

    return campeonato;
}

void escrever_no_arquivo_campeonato(FILE *arq_campeonato, CAMPEONATO *campeonato)
{
    if (campeonato != NULL)
    {
        fwrite(campeonato->nome, sizeof(char), 50, arq_campeonato);
    }
}

void opcao_campeonato(char *campeonato)
{
    printf("Digite o nome do campeonato que deseja abrir: ");
    scanf(" %[^(\n|\r)]%*c", campeonato);
}

void lista_campeonatos(FILE *arq_campeonato, char *nomeDeUsuario)
{
    char campeonato[50];
    char championshipList[100];
    strcpy(championshipList, "championship list");
    strcat(championshipList, "_");
    strcat(championshipList, nomeDeUsuario);
    strcat(championshipList, ".dat");

    if ((arq_campeonato = fopen(championshipList, "rb+")) == NULL)
    {
        printf("\nA lista de campeonatos esta vazia!\n\n");
        fclose(arq_campeonato);
        return;
    }

    fread(campeonato, sizeof(char), 50, arq_campeonato);

    if (campeonato[0] == '\0' || campeonato[0] == '\n' || campeonato[0] == '\r')
    {
        printf("\nA lista de campeonatos esta vazia!\n\n");
        fclose(arq_campeonato);
        return;
    }

    fseek(arq_campeonato, 0, SEEK_END);
    int size = ftell(arq_campeonato) / 50;

    printf("Lista de campeonatos:\n\n");

    for (int i = 0; i < size; i++)
    {
        fseek(arq_campeonato, i * 50, SEEK_SET);
        fread(campeonato, sizeof(char), 50, arq_campeonato);
        printf("%s\n", campeonato);
    }

    printf("\n");

    fclose(arq_campeonato);
}

char *get_campeonato(CAMPEONATO *campeonato)
{
    if (campeonato != NULL)
    {
        return campeonato->nome;
    }

    return "ERRO";
}

void apagar_tudo_campeonato(CAMPEONATO **campeonato)
{
    if (*campeonato != NULL)
    {
        free(*campeonato);
        *campeonato = NULL;
    }
}