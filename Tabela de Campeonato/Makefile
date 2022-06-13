AVL=Campeonatos/AVL/avl.c
TIMES=Campeonatos/Times/times.c
LISTA=Campeonatos/Lista/lista.c
CAMPEONATO=Campeonatos/Campeonato/campeonato.c
MAINSCREEN=Campeonatos/Mainscreen/mainscreen.c
ARQUIVO=Campeonatos/Arquivo/arquivo.c
AVLLOGIN=Login/AVLLogin/avlLogin.c
LOGIN=Login/Login/login.c
MAINSCREENLOGIN=Login/MainscreenLogin/mainscreenLogin.c
MAIN=main.c
BINARY=executavel

all:
	gcc -march=native -Wall -Wextra -g $(AVL) $(TIMES) $(LISTA) $(CAMPEONATO) $(MAINSCREEN) $(ARQUIVO) $(AVLLOGIN) $(LOGIN) $(MAINSCREENLOGIN) $(MAIN) -o $(BINARY)
run:
	./$(BINARY)
valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)