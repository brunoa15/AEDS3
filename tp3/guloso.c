#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void guloso(){
    int i, j, flag;
    int x, y, *aux, maior = 0, imaior, solution = 0;
    unsigned long long N;
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

        aux[i] = 0;
    }

    qsort(rua, N, sizeof(lados), cmp);

    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            if(rua[j].dir < rua[i].dir){
                aux[i]++;
                aux[j]++;
                if(aux[i] > maior){
                    maior = aux[i];
                    imaior = i;
                }
                if(aux[j] > maior){
                    maior = aux[j];
                    imaior = j;
                }
            }
        }
        if(aux[i] == 0){
            solution++;
        }
    }

    while(maior > 0){
        for(i=0;i<imaior;i++){
            if(rua[i].dir > rua[imaior].dir && aux[i] != 0){
                aux[i]--;
                if(aux[i] == 0) solution++;
            }
        }

        for(i=imaior+1;i<N;i++){
            if(rua[i].dir < rua[imaior].dir && aux[i] != 0){
                aux[i]--;
                if(aux[i] == 0) solution++;
            }
        }

        aux[imaior] = 0;
        maior = 0;

        for(i=0;i<N;i++){
            if(aux[i] > maior){
                maior = aux[i];
                imaior = i;
            }
        }
    }

    printf("%d\n", solution);

    free(rua);
    free(aux);
}