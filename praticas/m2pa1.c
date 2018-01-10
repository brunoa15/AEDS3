#include <stdio.h>

int main(){
    int i, j;
    int x, y;
    int dir;
    char mapa[100][100];
    char resultado = 'a';

    scanf("%d", &y);
    scanf("%d", &x);
    fflush(stdin);

    for(i=0;i<x;i++){
        scanf("%s", mapa[i]);
        fflush(stdin);
    }
    
    if(mapa[0][0] == 'v') dir = 1;
    else if(mapa[0][0] == '<') dir = 2;
    else if(mapa[0][0] == '^') dir = 3;
    else if(mapa[0][0] == '>') dir = 0;

    i=0;
    j=0;
    while(resultado == 'a'){
        
        if(dir == 0){
            mapa[i][j] = '!';
            j++;
            if(j==y){
                resultado = '!';
                break;
            }
            if(mapa[i][j] == 'v') dir = 1;
            else if(mapa[i][j] == '<') dir = 2;
            else if(mapa[i][j] == '^') dir = 3;
            else if(mapa[i][j] == '*') resultado = '*';
            else if(mapa[i][j] == '!') resultado = '!';
        }

        else if(dir == 1){
            mapa[i][j] = '!';
            i++;
            if(i==x){
                resultado = '!';
                break;
            }
            if(mapa[i][j] == '>') dir = 0;
            else if(mapa[i][j] == '<') dir = 2;
            else if(mapa[i][j] == '^') dir = 3;
            else if(mapa[i][j] == '*') resultado = '*';
            else if(mapa[i][j] == '!') resultado = '!';
        }

        else if(dir == 2){
            mapa[i][j] = '!';
            j--;
            if(j == -1){
                resultado = '!';
                break;
            }
            if(mapa[i][j] == 'v') dir = 1;
            else if(mapa[i][j] == '>') dir = 0;
            else if(mapa[i][j] == '^') dir = 3;
            else if(mapa[i][j] == '*') resultado = '*';
            else if(mapa[i][j] == '!') resultado = '!';
        }

        else if(dir == 3){
            mapa[i][j] = '!';
            i--;
            if(j == -1){
                resultado = '!';
                break;
            }
            if(mapa[i][j] == 'v') dir = 1;
            else if(mapa[i][j] == '<') dir = 2;
            else if(mapa[i][j] == '>') dir = 0;
            else if(mapa[i][j] == '*') resultado = '*';
            else if(mapa[i][j] == '!') resultado = '!';
        }

    }

    printf("%c\n", resultado);

}