#include <stdio.h>
#define MAX 9999999

int min(int a, int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    int i, j;
    int P, N; //pontos de vida, numero de feiticos
    int DanoTotal;

    while(scanf("%d %d", &N, &P) != EOF){
        
        int D[N+1], M[N+1];
        int mat[N+1][P+1];

        for(i=1;i<=N;i++){
            scanf("%d %d", &D[i], &M[i]);
        }

        DanoTotal = 0;
        for(i=1;i<=N;i++){
            DanoTotal += D[i];
        }

        if(DanoTotal < P){
            printf("-1\n");
        }
        else{

            for(i=0;i<=N;i++){
                for(j=0;j<=P;j++){

                    if(i==0 || j==0){
                        mat[i][j] = MAX;
                    }

                    else if(D[i] >= j){
                        mat[i][j] = min(mat[i-1][j], M[i]);
                    }

                    else{
                        mat[i][j] = min(mat[i-1][j], (M[i] + mat[i-1][j-D[i]]));
                    }

                }
            }

            printf("%d\n", mat[N][P]);

        }      
    }
}