#include <stdio.h>
#include <stdlib.h>
#include "converte_bin.h"

void converte_bin(unsigned long long x, int y, int *vetor){
    int *aux1, i, j, resto;
    aux1 = malloc(y*sizeof(int));
    for(i=0;i<y;i++){
            aux1[i] = 0;
    }

    i = 0;
    //zero em binario eh igual a zero
    if(x == 0){
        for(i=0, j=y-1; i<y; i++, j--){
            vetor[i] = aux1[j];
        }
        free(aux1);
        
        return;
    }
    //sao feitas sucessivas divisoes por dois e o resto das divisoes sao armazenados
    else{
        while(x != 1){
            resto = x%2;
            x = x/2;
            aux1[i] = resto;
            i++;
        }
        aux1[i] = 1;
    }

    //o vetor dado na entrada recebe o valor convertido em binario e os espacos restantes sao preenchidos com zero se necessario
    for(i=0, j=y-1; i<y; i++, j--){
        vetor[i] = aux1[j];
    }
    free(aux1);
}