#include <stdio.h>
#include <stdlib.h>


int main(){
    int vertices, arestas, custo, i, j;
    int V, W, P;
    int **MatrizAdj;

    scanf("%d %d", &vertices, &arestas);
    printf("vertice = %d aresta = %d \n",vertices,arestas);
    MatrizAdj = malloc(vertices*sizeof(int *));
    for(i=0;i<vertices;i++){
        MatrizAdj[i] = malloc(vertices*sizeof(int));
    }

    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
             MatrizAdj[i][j] = 0;
        }
    }

    for(i=0;i<arestas;i++){
        scanf("%d %d %d", &V, &W, &P);
        MatrizAdj[V-1][W-1] = P;
        MatrizAdj[W-1][V-1] = P;
    }

    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            printf("%d ", MatrizAdj[i][j]);
        }
        printf("\n");
    }

}