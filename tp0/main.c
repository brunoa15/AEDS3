#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista_pilha_fila.h"
#include "converte_bin.h"

int main(){
    unsigned long long i, j, k;
    long long resultado, res_parcial;
    unsigned int tamanho;
    char buffer[201], aux[10], *saida;
    int qt_operadores = 0, operando1, operando2;
    int vetor_entrada[201], *possibilidades;
    t_pilha pilha;
    t_item auxItem;
    
    //LEITURA DA ENTRADA
    fgets(buffer, 201, stdin);
    scanf("%d", &resultado);
    tamanho = strlen(buffer);
    //Esse loop transforma a entrada que eh uma string em um vetor de inteiros para facilitar as operacoes.
    //espacos sao pulados, numeros sao armazenados no vetor e o os operadores '?' sao representados como -1.
    for(i=0, j=0;i<tamanho-1;i++){
        if(buffer[i] == ' ') continue;
        else if(buffer[i] == '?'){
            qt_operadores++;
            vetor_entrada[j] = -1;
            j++;
        }
        else{
            //o bloco seguinte trata de numeros que tenham mais de um algarismo, como por exemplo: 10
            //se apos a leitura de um algarismo na string, o sucessor dele nao for um espaco ou um operador '?', entao ele faz parte do inteiro anterior.
            k = 0;
            do{
                aux[k] = buffer[i];
                k++;
                if(buffer[i+1] != ' ' && buffer[i+1] != '?') i++;
                else k = 0;
            } while(k > 0);
            vetor_entrada[j] = atoi(aux);
            for(k=0;k<10;k++){
                //a variavel que armazena a string para conversao em inteiro eh zerada apos cada iteracao.
                aux[k] = '\0';
            }
            j++;
        }
    }

    //PROCESSAMENTO
    pilha_FazVazia(&pilha);
    saida = malloc((qt_operadores+1)*sizeof(char));
    possibilidades = malloc(qt_operadores*sizeof(int));

    //o programa testa todas as combinacoes possiveis de operadores que eh igual ao numero de operdores elevado ao quadrado
    for(j=0;j<pow(2,qt_operadores);j++){
        k = 0;
        /* Para o teste de todas as combinacoes eh usado o numero da iteracao em binario,
           onde 0 representa uam soma '+' e 1 representa uma multiplicacao '*'.
           Exemplo: em uma entrada que possui 3 operadores, a possibilidade combinacoes eh igual a
           8. Na quarta iteracao (j = 3) o equivalente binario será 0 1 1, que siginifica testar: + * *.
        */
        converte_bin(j, qt_operadores, possibilidades); //funcao para conversao de decimal para binario
        
        //se o item guardado pelo vetor de entrada for um numero, esse numero eh empilhado
        //se for um operador, os dois ultimos numeros sao retirados da pilha e eh feita a operacao
        for(i=0;i<tamanho/2;i++){
            auxItem.chave = vetor_entrada[i];
            if(auxItem.chave == -1){
                pilha_desempilha(&pilha, &auxItem);
                operando1 = auxItem.chave;
                pilha_desempilha(&pilha, &auxItem);
                operando2 = auxItem.chave;
                    if(possibilidades[k] == 0){
                        res_parcial = operando1 + operando2;
                        saida[k] = '+';
                        k++;
                    }
                    else{
                        res_parcial = operando1 * operando2;
                        saida[k] = '*';
                        k++;
                    }
                auxItem.chave = res_parcial;
            }
            //o resultado parcial eh armazenado na pilha a cada iteracao, se no fim o valor na pilha for igual ao 
            //resultado dado na entrada, os operadores utilizados sao impressos.
            pilha_empilha(auxItem, &pilha); 
        }
        saida[k] = '\0';

        //SAIDA
        pilha_desempilha(&pilha, &auxItem);
        if(auxItem.chave == resultado){
            printf("%s\n", saida);
        }
    }

    free(pilha.topo);
    free(saida);
    free(possibilidades);
}