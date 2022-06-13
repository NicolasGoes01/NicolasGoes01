#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

struct login_
{
    char nome[50];
    char nomeDeUsuario[50];
    char senha[50];
};

FILE *abrir_arquivo_Login()
{
    FILE *arq_login;

    if ((arq_login = fopen("login.dat", "rb+")) == NULL)
    {
        if ((arq_login = fopen("login.dat", "wb+")) == NULL)
        {
            printf("Erro ao abrir/criar arquivo!\n");
            exit(0);
        }
    }

    return arq_login;
}

int get_login_size(FILE *arq_login)
{
    if (arq_login != NULL)
    {
        fseek(arq_login, 0, SEEK_END);
        return ftell(arq_login) / sizeof(LOGIN);
    }

    return ERRO;
}

int get_login_size_bytes(FILE *arq_login)
{
    if (arq_login != NULL)
    {
        return sizeof(LOGIN);
    }

    return ERRO;
}

LOGIN *read_login(FILE *arq_login)
{
    if (arq_login != NULL)
    {
        LOGIN *login = (LOGIN *) malloc(sizeof(LOGIN));

        fread(login, sizeof(LOGIN), 1, arq_login);

        return login;
    }

    return NULL;
}

LOGIN *item_criar_Login(char *nome, char *nomeDeUsuario, char *senha)
{
    LOGIN *login;

    login = (LOGIN *) malloc(sizeof(LOGIN));

    if (login != NULL)
    {
        strcpy(login->nome, nome);
        strcpy(login->nomeDeUsuario, nomeDeUsuario);
        strcpy(login->senha, senha);

        return login;
    }

    return NULL;
}

void opcoes_programas(char *nomeDeUsuario)
{
    int opcao;

    do
    {
        printf("Qual programa deseja abrir:\n");
        printf("[1] Campeonatos\n[0] Fazer logout\n");
        scanf("%d", &opcao);

        if (opcao != 0 && opcao != 1)
        {
            printf("\nNumero invalido! Tente Novamente\n\n");
        }
    } while(opcao != 0 && opcao != 1);

    if (opcao == 1)
    {
        mainscreen(nomeDeUsuario);
    }

    else if (opcao == 0)
    {
        return;
    }
}

void logado(LOGIN *login)
{
    printf("\n\nOla, %s\n\n", login->nome);
    char *nomeDeUsuario = login->nomeDeUsuario;
    opcoes_programas(nomeDeUsuario);
}

char *get_nome_Login(LOGIN *login)
{
    if (login != NULL)
    {
        return login->nome;
    }

    return "ERRO";
}

char *get_nomeDeUsuario(LOGIN *login)
{
    if (login != NULL)
    {
        return login->nomeDeUsuario;
    }

    return "ERRO";
}

char *get_senha(LOGIN *login)
{
    if (login != NULL)
    {
        return login->senha;
    }

    return "ERRO";
}

void imprimir_Login(LOGIN *login)
{
    if (login != NULL)
    {
        printf("%s\n", login->nome);
    }
}

void item_apagar_Login(LOGIN **login)
{
    if (*login != NULL)
    {
        free (*login);
        *login = NULL;
    }
}
