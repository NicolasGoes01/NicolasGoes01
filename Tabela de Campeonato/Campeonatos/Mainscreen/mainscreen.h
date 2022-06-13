#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include "../Campeonato/campeonato.h"
#include "../AVLTimes/avltimes.h"
#include "../ListaTimes/listaTimes.h"
#include "../Lista/lista.h"
#include "../../Login/Login/login.h"

void mainscreen(char *nomeDeUsuario);
void mainscreenCampeonato(TIME *time, char *campeonato, char *nomeDeUsuario);

#endif //MAINSCREEN_H
