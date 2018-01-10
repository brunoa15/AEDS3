#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int cmp(const void *a, const void *b){
	return(*(int*)a - *(int*)b);
}

void converte_bin(int num, int N, int *vetor){
	int *aux1, i, j, resto;
	aux1 = malloc(N*sizeof(int));
	for(i=0;i<N;i++){
			aux1[i] = 0;
	}

	i = 0;
	//zero em binario eh igual a zero
	if(num == 0){
		for(i=0, j=N-1; i<N; i++, j--){
			vetor[i] = aux1[j];
		}
		free(aux1);
		
		return;
	}
	//sao feitas sucessivas divisoes por dois e o resto das divisoes sao armazenados
	else{
		while(num != 1){
			resto = num%2;
			num = num/2;
			aux1[i] = resto;
			i++;
		}
		aux1[i] = 1;
	}

	//o vetor dado na entrada recebe o valor convertido em binario e os espacos restantes sao preenchidos com zero se necessario
	for(i=0, j=N-1; i<N; i++, j--){
		vetor[i] = aux1[j];
	}
	free(aux1);
}

int max(int a, int b){
	if(a > b) return a;
	else return b;
}