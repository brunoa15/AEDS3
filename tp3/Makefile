main: main.o bruto.o dinamico.o guloso.o funcoes.o
	gcc main.o bruto.o dinamico.o guloso.o funcoes.o -o main -lm -Wall -Wextra -Werror -std=c99 -pedantic

main.o: main.c bruto.c dinamico.c guloso.c
	gcc -c main.c dinamico.c guloso.c bruto.c

bruto.o: bruto.c funcoes.c
	gcc -c bruto.c funcoes.c

dinamico.o: dinamico.c funcoes.c
	gcc -c dinamico.c funcoes.c

guloso.o: guloso.c funcoes.c
	gcc -c guloso.c funcoes.c

funcoes.o: funcoes.c
	gcc -c funcoes.c

clean:
	rm *.o *.gch