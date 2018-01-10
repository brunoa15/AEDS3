#include <stdio.h>

int verifica_amizade(int p1, int M, int amigos, int matriz[1001][1001]){

    int p2;

    if(amigos == 0){
        return 1;
    }

    for(p2=1;p2<=M;p2++){
        if(matriz[p1][p2] == 1){
            amigos--;
            verifica_amizade(p2, M, amigos, matriz);
        }
    }

}

int main(){
    int N, M, K;
    int i, p1, p2, amg;
    int MatrizAdj[1001][1001];
    int amigos[1001];
    int convidados[1001];

    printf("funciono ate aqui");

    for(p1=0;p1<1001;p1++){
        convidados[p1] = 0;
        amigos[1001] = 0;
        for(p2=0;p2<1001;p2++){
            MatrizAdj[p1][p2] = 0;
        }
    }

    //while(!feof){
        scanf("%d %d %d", &N, &M, &K);
        for(i=0;i<M;i++){
            scanf("%d %d", &p1, &p2);
            MatrizAdj[p1][p2] = 1;
            MatrizAdj[p2][p1] = 1;
            amigos[p1]++;
            amigos[p2]++;
        }

        //verificar se existe um ciclo com K+1 vertices
        
        if(K == 0){
            for(i=1;i<=M;i++){
                printf("%d ", i);
            }
        }
        else{

            for(p1=1;p1<=M;p1++){
                
                if(amigos[p1] >= K){

                    amg = amigos[p1];
                    //verifica_amizade(p1, M, amg, MatrizAdj);

                }

            }

        }
    //} 

}