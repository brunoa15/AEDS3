#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void dinamico(){
    unsigned long long N;
	int x, y;
	int i, j, parcial = 0, solution = 0;
	int *aux;
	lados *rua;

	scanf("%llu", &N);

	rua = malloc(N*sizeof(lados));
	aux = malloc(N*sizeof(int));

	for(i=0;i<N;i++){
		scanf("%d%d", &x, &y);

		if(x%2 == 0){
			rua[i].esq = x;
			rua[i].dir = y;
		}
		else{
			rua[i].esq = y;
			rua[i].dir = x;
		}

		aux[i] = 1;
	}

	qsort(rua, N, sizeof(lados), cmp);

	for(i=1;i<N;i++){
		for(j=0;j<i;j++){
			if(rua[j].dir < rua[i].dir){
				aux[i] = max(aux[i], aux[j]+1);
			}
		}
	}
		
	for(i=0;i<N;i++){
		solution = max(solution, aux[i]);
	}

	printf("%d\n", solution);

    free(rua);
    free(aux);
}