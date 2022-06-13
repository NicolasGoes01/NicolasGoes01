#ifndef AVL_H
#define AVL_H

#include "../Login/login.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct nodeLogin_ NODELOGIN;
typedef struct avlLogin_ AVLLOGIN;

AVLLOGIN *criar_arvore_avl_Login();
int avl_inserir_Login(AVLLOGIN *avl, LOGIN *login);
void arvore_binaria_em_ordem_Login(AVLLOGIN *avl);
void ab_escrever_arquivo_em_ordem_Login(FILE *arq_login, AVLLOGIN *avl);
void adicionar_na_arvore_avl_Login(AVLLOGIN *avl, LOGIN *login);
NODELOGIN* buscaBinaria_Login(NODELOGIN *raiz, char *nomeDeUsuario);
LOGIN *fazer_cadastro(AVLLOGIN *avl);
LOGIN *fazer_login(AVLLOGIN *avl);
void avl_apagar_Login(AVLLOGIN *avl);

#endif //AVL_H
