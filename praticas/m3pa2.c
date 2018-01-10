#include <stdio.h>

int main(){
    int quadrados, valor[1000000];
    int soma = 0;
    unsigned long long respostas = 0;
    int i, contador[8];

    scanf("%d", &quadrados);
    for(i=0;i<quadrados;i++){
        scanf("%d", &valor[i]);
    }

    //processamento
    contador[0] = 1;
    for(i=1;i<8;i++){
        contador[i] = 0;
    }
    for(i=0;i<quadrados;i++){
        soma = soma + valor[i];
        respostas = respostas + contador[soma%8];
        contador[soma%8]++;
    }

    //saida
    printf("%llu\n", respostas);
}