#include <stdio.h>
#include <string.h>

int main(){
    char risada[51];
    char vogais[51];
    int i, j = 0, tamanho;

    fgets(risada, 51, stdin);

    for(i=0;risada[i];i++){    
        if(risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u'){
            vogais[j] = risada[i];
            j++;
        }
    }
	vogais[j] = '\0';
	tamanho = strlen(vogais);

    for(i=0;i<tamanho;i++){
        if(vogais[i] != vogais[tamanho-1]){
            printf("N\n");
            return 0;
        }
        tamanho--;
    }
    printf("S\n");
    return 0;   
}