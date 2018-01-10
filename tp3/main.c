#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
	char algoritmo;

	scanf("%c", &algoritmo);

	if(algoritmo == 'g'){
		guloso();
	}

	else if(algoritmo == 'd'){
		dinamico();
	}

	else if(algoritmo == 'b'){
		bruto();
	}
}