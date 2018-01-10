tp0: main.o lista_pilha_fila.o converte_bin.o
	gcc main.o lista_pilha_fila.o converte_bin.o -o tp0 -lm -Wall -Wextra -Werror -std=c99 -pedantic

main.o: main.c lista_pilha_fila.h converte_bin.h
	gcc -g -c main.c

lista_pilha_fila.o: lista_pilha_fila.h lista_pilha_fila.c
	gcc -g -c lista_pilha_fila.c

converte_bin.o: converte_bin.h converte_bin.c
	gcc -g -c converte_bin.c

clean:
	rm *.o *.gch
