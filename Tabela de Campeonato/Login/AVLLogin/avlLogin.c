#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avlLogin.h"

struct nodeLogin_
{
    LOGIN *login;
    NODELOGIN *direita;
    NODELOGIN *esquerda;
    int altura;
};

struct avlLogin_
{
    NODELOGIN *raiz;
};

static NODELOGIN *avl_inserir_no_e_rotacionar_Login(NODELOGIN *raiz, LOGIN *login);
NODELOGIN *rodar_direita_Login(NODELOGIN *node);
NODELOGIN *rodar_esquerda_Login(NODELOGIN *node);
NODELOGIN *rodar_esquerda_direita_Login(NODELOGIN *node);
NODELOGIN *rodar_direita_esquerda_Login(NODELOGIN *node);
static int DesbalanceamentoEhPositivo_Login(NODELOGIN *raiz);
static int DesbalanceamentoEhNegativo_Login(NODELOGIN *raiz);
int avl_altura_no_Login(NODELOGIN *raiz);
int maior_menor_Login(NODELOGIN *raiz, LOGIN *login);

AVLLOGIN *criar_arvore_avl_Login()
{
    AVLLOGIN *avl = (AVLLOGIN *) malloc(sizeof(AVLLOGIN));

    if (avl != NULL)
    {
        avl->raiz = NULL;
    }

    return avl;
}

NODELOGIN *avl_cria_no_Login(LOGIN *login)
{
    NODELOGIN *node = (NODELOGIN *) malloc(sizeof(NODELOGIN));

    if (node != NULL)
    {
        node->altura = 0;
        node->direita = NULL;
        node->esquerda = NULL;
        node->login = login;
    }

    return node;
}

static NODELOGIN *inserir_no_Login(NODELOGIN *raiz, LOGIN *login)
{
    if (raiz == NULL)
    {
        raiz = avl_cria_no_Login(login);
    }

    else
    {
        if (maior_menor_Login(raiz, login) > 0)
        {
            raiz->direita = avl_inserir_no_e_rotacionar_Login(raiz->direita, login);
        }

        else
        {
            raiz->esquerda = avl_inserir_no_e_rotacionar_Login(raiz->esquerda, login);
        }
    }

    return raiz;
}

static NODELOGIN *selecionar_e_executar_rotacao_Login(NODELOGIN *raiz, LOGIN *login)
{
    if (DesbalanceamentoEhNegativo_Login(raiz))
    {
        if (maior_menor_Login(raiz, login) > 0)
        {
            raiz = rodar_esquerda_Login(raiz);
        }

        else
        {
            raiz = rodar_direita_esquerda_Login(raiz);
        }
    }

    if (DesbalanceamentoEhPositivo_Login(raiz))
    {
        if (maior_menor_Login(raiz, login) < 0)
        {
            raiz = rodar_direita_Login(raiz);
        }

        else
        {
            raiz = rodar_esquerda_direita_Login(raiz);
        }
    }

    return raiz;
}

static NODELOGIN *avl_inserir_no_e_rotacionar_Login(NODELOGIN *raiz, LOGIN *login)
{
    raiz = inserir_no_Login(raiz, login);

    raiz->altura = max(avl_altura_no_Login(raiz->esquerda), avl_altura_no_Login(raiz->direita)) + 1;

    raiz = selecionar_e_executar_rotacao_Login(raiz, login);

    return raiz;
}

NODELOGIN *rodar_direita_Login(NODELOGIN *node)
{
    NODELOGIN *node_aux = node->esquerda;

    node->esquerda = node_aux->direita;
    node_aux->direita = node;

    node->altura = max(avl_altura_no_Login(node->esquerda), avl_altura_no_Login(node->direita)) + 1;
    node_aux->altura = max(avl_altura_no_Login(node_aux->esquerda), node->altura) + 1;

    return node_aux;
}

NODELOGIN *rodar_esquerda_Login(NODELOGIN *node)
{
    NODELOGIN *node_aux = node->direita;

    node->direita = node_aux->esquerda;
    node_aux->esquerda = node;

    node->altura = max(avl_altura_no_Login(node->esquerda), avl_altura_no_Login(node->direita)) + 1;
    node_aux->altura = max(avl_altura_no_Login(node_aux->direita), node->altura) + 1;

    return node_aux;
}

NODELOGIN *rodar_esquerda_direita_Login(NODELOGIN *node)
{
    node->esquerda = rodar_esquerda_Login(node->esquerda);
    return rodar_direita_Login(node);
}

NODELOGIN *rodar_direita_esquerda_Login(NODELOGIN *node)
{
    node->direita = rodar_direita_Login(node->direita);
    return rodar_esquerda_Login(node);
}

int avl_inserir_Login(AVLLOGIN *avl, LOGIN *login)
{
    avl->raiz = avl_inserir_no_e_rotacionar_Login(avl->raiz, login);
    return avl->raiz != NULL;
}

static int DesbalanceamentoEhPositivo_Login(NODELOGIN *raiz)
{
    return avl_altura_no_Login(raiz->esquerda) - avl_altura_no_Login(raiz->direita) == 2;
}

static int DesbalanceamentoEhNegativo_Login(NODELOGIN *raiz)
{
    return avl_altura_no_Login(raiz->esquerda) - avl_altura_no_Login(raiz->direita) == -2;
}

int avl_altura_no_Login(NODELOGIN* raiz)
{
    if (raiz != NULL)
    {
        return raiz->altura;
    }

    return -1;
}

static void em_ordem_recursao_Login(NODELOGIN *raiz)
{
    if (raiz != NULL)
    {
        em_ordem_recursao_Login(raiz->esquerda);
        imprimir_Login(raiz->login);
        em_ordem_recursao_Login(raiz->direita);
    }
}

void arvore_binaria_em_ordem_Login(AVLLOGIN *avl)
{
    em_ordem_recursao_Login(avl->raiz);
}

void escrever_arquivo_em_ordem_Login(FILE *arq_login, NODELOGIN *raiz)
{
    if (raiz != NULL)
    {
        escrever_arquivo_em_ordem_Login(arq_login, raiz->esquerda);
        fwrite(raiz->login, get_login_size_bytes(arq_login), 1, arq_login);
        escrever_arquivo_em_ordem_Login(arq_login, raiz->direita);
    }
}

void ab_escrever_arquivo_em_ordem_Login(FILE *arq_login, AVLLOGIN *avl)
{
    arq_login = abrir_arquivo_Login();
    escrever_arquivo_em_ordem_Login(arq_login, avl->raiz);
    fclose(arq_login);
}

int maior_menor_Login(NODELOGIN *raiz, LOGIN *login)
{
    return strcmp(get_nomeDeUsuario(login), get_nomeDeUsuario(raiz->login));
}

void adicionar_na_arvore_avl_Login(AVLLOGIN *avl, LOGIN *login)
{
    FILE *arq_login = abrir_arquivo_Login();

    int login_size = get_login_size(arq_login);

    for (int i = 0; i < login_size; i++)
    {
        fseek(arq_login, i * get_login_size_bytes(arq_login), SEEK_SET);
        login = read_login(arq_login);
        avl_inserir_Login(avl, login);
    }

    fclose(arq_login);
}

NODELOGIN* buscaBinaria_Login(NODELOGIN *raiz, char *nomeDeUsuario)
{
    if (raiz != NULL)
    {
        if (strcmp(get_nomeDeUsuario(raiz->login), nomeDeUsuario) == 0)
        {
            return raiz;
        }

        if (strcmp(get_nomeDeUsuario(raiz->login), nomeDeUsuario) < 0)
        {
            return buscaBinaria_Login(raiz->direita, nomeDeUsuario);
        }

        return buscaBinaria_Login(raiz->esquerda, nomeDeUsuario);
    }

    return NULL;
}

LOGIN *cadastro(NODELOGIN *raiz)
{
    NODELOGIN *aux_raiz = raiz;
    char nome[50];
    char nomeDeUsuario[50];
    char senha[50];
    char confirmaSenha[50];
    int quantidade;

    printf("Nome: ");
    scanf(" %[^(\r|\n)]%*c", nome);

    do
    {
        raiz = aux_raiz;

        printf("Nome de usuario: ");
        scanf(" %[^(\r|\n)]%*c", nomeDeUsuario);

        raiz = buscaBinaria_Login(raiz, nomeDeUsuario);

        if (raiz != NULL)
        {
            printf("Nome de usuario ja existente! Tente Novamente!\n\n");
        }
    } while(raiz != NULL);

    do
    {
        printf("Senha (pelo menos 5 caracteres): ");
        scanf(" %[^(\r|\n)]%*c", senha);

        quantidade = strlen(senha);

        if (quantidade < 5)
        {
            printf("Senha muito curta! Digite novamente!\n\n");
        }
    } while(quantidade < 5);

    do
    {
        printf("Confirme sua senha: ");
        scanf(" %[^(\r|\n)]%*c", confirmaSenha);

        if (strcmp(senha, confirmaSenha) != 0)
        {
            printf("Senhas diferentes! Digite novamente!\n\n");
        }
    } while(strcmp(senha, confirmaSenha) != 0);

    return item_criar_Login(nome, nomeDeUsuario, senha);
}

LOGIN *fazer_cadastro(AVLLOGIN *avl)
{
    return cadastro(avl->raiz);
}

LOGIN *login(NODELOGIN *raiz)
{
    NODELOGIN *aux = raiz;
    char nomeDeUsuario[50];
    char senha[50];
    char *senhaCorreta;

    do
    {
        raiz = aux;

        printf("Nome de usuario: ");
        scanf(" %[^(\r|\n)]%*c", nomeDeUsuario);

        raiz = buscaBinaria_Login(raiz, nomeDeUsuario);

        if (raiz == NULL)
        {
            printf("Usuario nao encontrado! Tente Novamente!\n\n");
        }
    } while(raiz == NULL);

    do
    {
        printf("Senha: ");
        scanf(" %[^(\r|\n)]%*c", senha);

        senhaCorreta = get_senha(raiz->login);

        if (strcmp(senha, senhaCorreta) != 0)
        {
            printf("Senha incorreta! Tente Novamente!\n\n");
        }
    } while(strcmp(senha, senhaCorreta) != 0);

    return raiz->login;
}

LOGIN *fazer_login(AVLLOGIN *avl)
{
    return login(avl->raiz);
}

void avl_apagar_aux_Login(NODELOGIN *raiz)
{
    if (raiz != NULL)
    {
        avl_apagar_aux_Login(raiz->esquerda);
        avl_apagar_aux_Login(raiz->direita);
        item_apagar_Login(&raiz->login);
        free(raiz);
    }
}

void avl_apagar_Login(AVLLOGIN *avl)
{
    if (avl != NULL)
    {
        avl_apagar_aux_Login(avl->raiz);
        free(avl);
        avl = NULL;
    }
}
