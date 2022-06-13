#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltimes.h"

typedef struct nodeTimes_ NODETIMES;

struct nodeTimes_
{
    TIME *time;
    NODETIMES *direita;
    NODETIMES *esquerda;
    int altura;
};

struct avltimes_
{
    NODETIMES *raiz;
};

static NODETIMES *avl_inserir_no_e_rotacionar(NODETIMES *raiz, TIME *time);
NODETIMES *rodar_direita(NODETIMES *node);
NODETIMES *rodar_esquerda(NODETIMES *node);
NODETIMES *rodar_esquerda_direita(NODETIMES *node);
NODETIMES *rodar_direita_esquerda(NODETIMES *node);
static int DesbalanceamentoEhPositivo(NODETIMES *raiz);
static int DesbalanceamentoEhNegativo(NODETIMES *raiz);
int avl_altura_no(NODETIMES *raiz);
int maior_menor(NODETIMES *raiz, TIME *time);
void avl_escrever_arquivo_em_ordem(AVLTIMES *avl, char *campeonato, char *nomeDeUsuario);
void avl_apagar(AVLTIMES *avl);

AVLTIMES *criar_arvore_avl()
{
    AVLTIMES *avl = (AVLTIMES *) malloc(sizeof(AVLTIMES));

    if (avl != NULL)
    {
        avl->raiz = NULL;
    }

    return avl;
}

NODETIMES *avl_cria_no(TIME *time)
{
    NODETIMES *node = (NODETIMES *) malloc(sizeof(NODETIMES));

    if (node != NULL)
    {
        node->altura = 0;
        node->direita = NULL;
        node->esquerda = NULL;
        node->time = time;
    }

    return node;
}

static NODETIMES *inserir_no(NODETIMES *raiz, TIME *time)
{
    if (raiz == NULL)
    {
        raiz = avl_cria_no(time);
    }

    else
    {
        if (maior_menor(raiz, time) == MAIOR)
        {
            raiz->direita = avl_inserir_no_e_rotacionar(raiz->direita, time);
        }

        else
        {
            raiz->esquerda = avl_inserir_no_e_rotacionar(raiz->esquerda, time);
        }
    }

    return raiz;
}

static NODETIMES *selecionar_e_executar_rotacao(NODETIMES *raiz, TIME *time)
{
    if (DesbalanceamentoEhNegativo(raiz))
    {
        if (maior_menor(raiz, time) == MAIOR)
        {
            raiz = rodar_esquerda(raiz);
        }

        else
        {
            raiz = rodar_direita_esquerda(raiz);
        }
    }

    if (DesbalanceamentoEhPositivo(raiz))
    {
        if (maior_menor(raiz, time) == MENOR)
        {
            raiz = rodar_direita(raiz);
        }

        else
        {
            raiz = rodar_esquerda_direita(raiz);
        }
    }

    return raiz;
}

static NODETIMES *avl_inserir_no_e_rotacionar(NODETIMES *raiz, TIME *time)
{
    raiz = inserir_no(raiz, time);

    raiz->altura = max(avl_altura_no(raiz->esquerda), avl_altura_no(raiz->direita)) + 1;

    raiz = selecionar_e_executar_rotacao(raiz, time);

    return raiz;
}

NODETIMES *rodar_direita(NODETIMES *node)
{
    NODETIMES *node_aux = node->esquerda;

    node->esquerda = node_aux->direita;
    node_aux->direita = node;

    node->altura = max(avl_altura_no(node->esquerda), avl_altura_no(node->direita)) + 1;
    node_aux->altura = max(avl_altura_no(node_aux->esquerda), node->altura) + 1;

    return node_aux;
}

NODETIMES *rodar_esquerda(NODETIMES *node)
{
    NODETIMES *node_aux = node->direita;

    node->direita = node_aux->esquerda;
    node_aux->esquerda = node;

    node->altura = max(avl_altura_no(node->esquerda), avl_altura_no(node->direita)) + 1;
    node_aux->altura = max(avl_altura_no(node_aux->direita), node->altura) + 1;

    return node_aux;
}

NODETIMES *rodar_esquerda_direita(NODETIMES *node)
{
    node->esquerda = rodar_esquerda(node->esquerda);
    return rodar_direita(node);
}

NODETIMES *rodar_direita_esquerda(NODETIMES *node)
{
    node->direita = rodar_direita(node->direita);
    return rodar_esquerda(node);
}

int avl_inserir(AVLTIMES *avl, TIME *time)
{
    avl->raiz = avl_inserir_no_e_rotacionar(avl->raiz, time);
    return avl->raiz != NULL;
}

static int DesbalanceamentoEhPositivo(NODETIMES *raiz)
{
    return avl_altura_no(raiz->esquerda) - avl_altura_no(raiz->direita) == 2;
}

static int DesbalanceamentoEhNegativo(NODETIMES *raiz)
{
    return avl_altura_no(raiz->esquerda) - avl_altura_no(raiz->direita) == -2;
}

int avl_altura_no(NODETIMES *raiz)
{
    if (raiz != NULL)
    {
        return raiz->altura;
    }

    return -1;
}

int maior_menor(NODETIMES *raiz, TIME *time)
{
    if (get_pontos(time) < get_pontos(raiz->time))
    {
        return MAIOR;
    }

    else if (get_pontos(time) == get_pontos(raiz->time))
    {
        if (get_vitorias(time) < get_vitorias(raiz->time))
        {
            return MAIOR;
        }

        else if (get_vitorias(time) == get_vitorias(raiz->time))
        {
            if (get_saldo(time) < get_saldo(raiz->time))
            {
                return MAIOR;
            }

            else if (get_saldo(time) == get_saldo(raiz->time))
            {
                if (get_golsPro(time) < get_golsPro(raiz->time))
                {
                    return MAIOR;
                }

                else if (get_golsPro(time) == get_golsPro(raiz->time))
                {
                    if (strcmp(get_nome(time), get_nome(raiz->time)) > 0)
                    {
                        return MAIOR;
                    }
                }
            }
        }
    }

    return MENOR;
}

void reescreve_avl_ordenada_aux(AVLTIMES *avl, TIME *time, char *campeonato, char *nomeDeUsuario)
{
    avl_apagar(avl);

    avl = criar_arvore_avl();

    adicionar_na_arvore_avl(avl, time, campeonato, nomeDeUsuario);

    avl_escrever_arquivo_em_ordem(avl, campeonato, nomeDeUsuario);
}

void avl_adicionar_resultado(AVLTIMES *avl, TIME *time, char *campeonato, char *nomeDeUsuario)
{
    adicionar_resultado(time, campeonato, nomeDeUsuario);
    reescreve_avl_ordenada_aux(avl, time, campeonato, nomeDeUsuario);
}

void avl_editar_time(AVLTIMES *avl, TIME *time, char *campeonato, char *nomeDeUsuario)
{
    lista_editar_time(time, campeonato, nomeDeUsuario);
    reescreve_avl_ordenada_aux(avl, time, campeonato, nomeDeUsuario);
}

void avl_zerar_pontuacao(NODETIMES *raiz)
{
    if (raiz != NULL)
    {
        avl_zerar_pontuacao(raiz->esquerda);
        zera_tudo(raiz->time);
        avl_zerar_pontuacao(raiz->direita);
    }
}

void zerar_pontuacao(AVLTIMES *avl)
{
    int verificador;

    do
    {
        printf("\n\nVOCE TEM CERTEZA QUE DESEJA ZERAR A PONTUACAO DO CAMPEONATO?\n"
               "[1] SIM\n[0] NAO\n\n");
        scanf("%d", &verificador);

        if (verificador != 0 && verificador != 1)
        {
            printf("Digite um numero valido!\n");
        }
    } while(verificador != 0 && verificador != 1);

    if (verificador == 1)
    {
        avl_zerar_pontuacao(avl->raiz);
        printf("\nPONTUACAO ZERADA COM SUCESSO!\n\n");
    }
}

void adicionar_na_arvore_avl(AVLTIMES *avl, TIME *time, char *campeonato, char *nomeDeUsuario)
{
    FILE *arq_times = abrir_arquivo_times(campeonato, nomeDeUsuario);

    int times_size = get_times_size(arq_times);

    for (int i = 0; i < times_size; i++)
    {
        fseek(arq_times, i * get_times_size_bytes(arq_times), SEEK_SET);
        time = read_teams(arq_times);
        avl_inserir(avl, time);
    }

    fclose(arq_times);
}

void escrever_arquivo_em_ordem(FILE *arq_times, NODETIMES *raiz)
{
    if (raiz != NULL)
    {
        escrever_arquivo_em_ordem(arq_times, raiz->esquerda);
        fwrite(raiz->time, get_times_size_bytes(arq_times), 1, arq_times);
        escrever_arquivo_em_ordem(arq_times, raiz->direita);
    }
}

void avl_escrever_arquivo_em_ordem(AVLTIMES *avl, char *campeonato, char *nomeDeUsuario)
{
    FILE *arq_times = abrir_arquivo_times(campeonato, nomeDeUsuario);
    escrever_arquivo_em_ordem(arq_times, avl->raiz);
    fclose(arq_times);
}

void avl_apagar_aux(NODETIMES *raiz)
{
    if (raiz != NULL)
    {
        avl_apagar_aux(raiz->esquerda);
        avl_apagar_aux(raiz->direita);
        item_apagar(&raiz->time);
        free(raiz);
    }
}

void avl_apagar(AVLTIMES *avl)
{
    if (avl != NULL)
    {
        avl_apagar_aux(avl->raiz);
        free(avl);
        avl = NULL;
    }
}

void reescreve_avl_ordenada(AVLTIMES *avl, TIME *time, char *campeonato, char *nomeDeUsuario)
{
    avl_escrever_arquivo_em_ordem(avl, campeonato, nomeDeUsuario);

    avl_apagar(avl);

    avl = criar_arvore_avl();

    adicionar_na_arvore_avl(avl, time, campeonato, nomeDeUsuario);

    avl_escrever_arquivo_em_ordem(avl, campeonato, nomeDeUsuario);

    avl_apagar(avl);
}

void desenha_tabela_em_ordem(NODETIMES *raiz, int *posicao)
{
    if (raiz != NULL)
    {
        desenha_tabela_em_ordem(raiz->esquerda, posicao);
        desenha_tabela_aux(raiz->time, posicao);
        desenha_tabela_em_ordem(raiz->direita, posicao);
    }
}

void avl_desenha_tabela_em_ordem(AVLTIMES *avl)
{
    int posicao = 0;

    printf("________________________________________________________________________________\n");
    printf("|    |      TIME       |  J   |  V   |  E   |  D   |  GP  |  GC  |  SG  |  P   |\n");
    printf("________________________________________________________________________________\n");

    desenha_tabela_em_ordem(avl->raiz, &posicao);

    printf("________________________________________________________________________________\n\n");
}
