#ifndef LOGIN_H
#define LOGIN_H

#include "../../Campeonatos/Mainscreen/mainscreen.h"

#define ERRO (-32000)

typedef struct login_ LOGIN;

FILE *abrir_arquivo_Login();
int get_login_size(FILE *arq_login);
int get_login_size_bytes(FILE *arq_login);
LOGIN *read_login(FILE *arq_login);
LOGIN *item_criar_Login(char *nome, char *nomeDeUsuario, char *senha);
void logado(LOGIN *login);
char *get_nome_Login(LOGIN *login);
char *get_nomeDeUsuario(LOGIN *login);
char *get_senha(LOGIN *login);
void imprimir_Login(LOGIN *login);
void item_apagar_Login(LOGIN **login);

#endif //LOGIN_H
