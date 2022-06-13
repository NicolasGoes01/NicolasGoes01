#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

FILE *abrir_arquivo_times(char *campeonato, char *nomeDeUsuario)
{
    strcat(campeonato, "_");
    strcat(campeonato, nomeDeUsuario);
    strcat(campeonato, ".dat");

    FILE *arq_times;

    if ((arq_times = fopen(campeonato, "rb+")) == NULL)
    {
        if ((arq_times = fopen(campeonato, "wb+")) == NULL)
        {
            printf("Erro ao abrir/criar arquivo!\n");
            exit(0);
        }
    }

    remover_strlogin(campeonato);

    return arq_times;
}

FILE *abrir_arquivo_campeonatos(char *nomeDeUsuario)
{
    char championshipList[100];
    strcpy(championshipList, "championship list");
    strcat(championshipList, "_");
    strcat(championshipList, nomeDeUsuario);
    strcat(championshipList, ".dat");

    FILE *arq_campeonato;

    if ((arq_campeonato = fopen(championshipList, "rb+")) == NULL)
    {
        if ((arq_campeonato = fopen(championshipList, "wb+")) == NULL)
        {
            printf("Erro ao abrir/criar arquivo!\n");
            exit(0);
        }
    }

    return arq_campeonato;
}

void remover_strlogin(char *campeonato)
{
    char aux[50];

    for (int i = 0; campeonato[i] != '_'; i++)
    {
        aux[i] = campeonato[i];
        aux[i + 1] = '\0';
    }

    strcpy(campeonato, aux);
}
