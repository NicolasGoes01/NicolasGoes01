#include <stdio.h>
#include <string.h>
#include "mainscreen.h"

void abrir_campeonato(TIME *time, char *campeonato, char *nomeDeUsuario);

void mainscreen(char *nomeDeUsuario)
{
    FILE *arq_campeonatos = NULL;
    LISTA *lista = NULL;
    TIME *time = NULL;
    CAMPEONATO *campeonato = NULL;
    char campeonatoSTR[30];
    int opcao;

    do
    {
        lista = lista_criar();
        adicionar_na_lista(arq_campeonatos, lista, campeonato, nomeDeUsuario);

        printf("Digite:\n[1] para adicionar campeonato\n[2] para mostrar todos os campeonatos\n"
               "[3] para abrir campeonato\n[4] para apagar campeonato\n[0] para fazer Logout\n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            adicionar_campeonato(lista, time, nomeDeUsuario);
        }

        else if (opcao == 2)
        {

            lista_campeonatos(arq_campeonatos, nomeDeUsuario);
        }

        else if (opcao == 3)
        {
            opcao_campeonato(campeonatoSTR);
            abrir_campeonato(time, campeonatoSTR, nomeDeUsuario);
        }

        else if(opcao == 4)
        {
            apagar_campeonato(lista, campeonato, nomeDeUsuario);
        }

        else if (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4)
        {
            printf("Numero invalido! Tente novamente!!!\n\n");
        }

        lista_escrever_arquivo_aux(lista, nomeDeUsuario);
        apagar_lista(lista);
    } while(opcao != 0);
}

void mainscreenCampeonato(TIME *time, char *campeonato, char *nomeDeUsuario)
{
    LISTATIMES *listatimes = NULL;
    AVLTIMES *avltimes = NULL;
    int opcao;

    do
    {
        avltimes = criar_arvore_avl();
        adicionar_na_arvore_avl(avltimes, time, campeonato, nomeDeUsuario);

        listatimes = lista_criar_times();
        adicionar_times_na_lista(listatimes, time, campeonato, nomeDeUsuario);

        printf("Digite:\n[1] para adicionar o resultado de um jogo\n[2] para mostrar a tabela atualizada\n"
               "[3] para editar a informacao de um time\n[4] para zerar pontuacao do campeonato\n"
                    "[0] para voltar ao menu pricipal\n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            avl_adicionar_resultado(avltimes, time, campeonato, nomeDeUsuario);
        }

        else if (opcao == 2)
        {
            avl_desenha_tabela_em_ordem(avltimes);
        }

        else if (opcao == 3)
        {
            avl_editar_time(avltimes, time, campeonato, nomeDeUsuario);
        }

        else if (opcao == 4)
        {
            zerar_pontuacao(avltimes);
        }

        else if (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4)
        {
            printf("Numero invalido! Tente novamente!!!\n\n");
        }

        reescreve_avl_ordenada(avltimes, time, campeonato, nomeDeUsuario);
        apagar_lista_times(&listatimes);
    } while (opcao != 0);
}

void abrir_campeonato(TIME *time, char *campeonato, char *nomeDeUsuario)
{
    strcat(campeonato, "_");
    strcat(campeonato, nomeDeUsuario);
    strcat(campeonato, ".dat");

    FILE *arq_times;

    if ((arq_times = fopen(campeonato, "r+")) == NULL)
    {
        printf("Campeonato nao encontrado!\n\n");
        return;
    }

    fclose(arq_times);

    remover_strlogin(campeonato);

    if (arq_times != NULL)
    {
        mainscreenCampeonato(time, campeonato, nomeDeUsuario);
    }
}
