#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes.h"

void bruto(){
	unsigned long long N, i, k;
	int x, y;
	int j, maior;
	lados *rua;
	int *possibilidades;
	int parcial = 0, solution = 0;

	scanf("%llu", &N);
	
	k = pow(2,N);
	rua = malloc(N*sizeof(lados));
	possibilidades = malloc(N*sizeof(int));

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
	}

	qsort(rua, N, sizeof(lados), cmp);

	for(i=1;i<k;i++){
		converte_bin(i, N, possibilidades);
		maior = 0;
		for(j=0;j<N;j++){
			if(possibilidades[j] == 1){
				if(rua[j].dir > maior){
					parcial++;
					maior = rua[j].dir;
				}
				else break;
			}
		}
		if(parcial > solution){
			solution = parcial;
		}
		parcial = 0;
		maior = 0;
	}

	printf("%d\n", solution);

	free(rua);
	free(possibilidades);
}