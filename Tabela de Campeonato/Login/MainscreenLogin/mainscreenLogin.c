#include <stdio.h>
#include <string.h>
#include "mainscreenLogin.h"

void mainscreenLogin()
{
    FILE *arq_login = NULL;
    AVLLOGIN *avl = criar_arvore_avl_Login();
    LOGIN *login = NULL;
    int opcao;

    adicionar_na_arvore_avl_Login(avl, login);

    do
    {
        printf("Digite:\n[1] para fazer cadastro\n[2] para fazer login\n[0] para sair\n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            login = fazer_cadastro(avl);
            avl_inserir_Login(avl, login);
            printf("\nCadastro realizado com sucesso!!!\n\n");
            logado(login);
        }

        else if (opcao == 2)
        {
            login = fazer_login(avl);
            logado(login);
        }

        else if (opcao != 0 && opcao != 1 && opcao != 2)
        {
            printf("Numero invalido! Tente novamente!!!\n\n");
        }

    } while(opcao != 0);

    ab_escrever_arquivo_em_ordem_Login(arq_login, avl);

    avl_apagar_Login(avl);
}
