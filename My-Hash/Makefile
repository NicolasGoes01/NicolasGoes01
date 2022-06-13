all: compila_montador  montador simulador

montador:
	./montador_fonte/montador myHash.asm myHash.mif

simulador:
	./simulador_fonte/sim myHash.mif charmap.mif

compila_montador:
	gcc montador_fonte/*.c -o montador_fonte/montador
