#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j, k, l, T, *Q, **x, **y;
	char **S, aux1, aux2;
	//T=numero de casos teste
	//S=string
	//Q=numero de operaçoes a serem feitas na string

	//ENTRADA
	scanf("%d", &T);
	S = malloc(T*sizeof(char*));
	Q = malloc(T*sizeof(int));
	x = malloc(T*sizeof(int*));
	y = malloc(T*sizeof(int*));
	for(i=0;i<T;i++){
		S[i] = malloc(10001*sizeof(char));
		x[i] = malloc(10001*sizeof(int));
		y[i] = malloc(10001*sizeof(int));
	}

	for(i=0;i<T;i++){
		scanf("%s", S[i]);
		fflush(stdin);
		scanf("%d", &Q[i]);
		for(j=0;j<Q[i];j++){
			scanf("%d", &x[i][j]);
			if(x[i][j] == 0 || x[i][j] == 1){
				scanf("%d", &y[i][j]);
			}
			fflush(stdin);
		}
	}

	//PROCESSAMENTO E SAIDA
	for(i=0;i<T;i++){
		printf("Caso #%d:\n", i+1);
		for(j=0;j<Q[i];j++){
			if(x[i][j] == 0){
				for(k=0;k<y[i][j];k++){
					l = 0;
					aux2 = '*';
					while(S[i][l] != '\0'){
						if(S[i][l] == 'a' || S[i][l] == 'e' || S[i][l] == 'i' || S[i][l] == 'o' || S[i][l] == 'u'){
							aux1 = S[i][l];
							S[i][l] = aux2;
							aux2 = aux1;
						}
						l++;
					}
					aux1 = '*';
					l = 0;
					while(aux1 == '*'){
						if(S[i][l] == '*'){
							S[i][l] = aux2;
							aux1 = 'a';
						}
						else l++;
					}
				}

			}
			else if(x[i][j] == 1){
				for(k=0;k<y[i][j];k++){
					l = 0;
					aux2 = '*';
					while(S[i][l] != '\0'){
						if(S[i][l] != 'a' && S[i][l] != 'e' && S[i][l] != 'i' && S[i][l] != 'o' && S[i][l] != 'u'){
							aux1 = S[i][l];
							S[i][l] = aux2;
							aux2 = aux1;
						}
						l++;
					}
					aux1 = '*';
					l = 0;
					while(aux1 == '*'){
						if(S[i][l] == '*'){
							S[i][l] = aux2;
							aux1 = 'a';
						}
						else l++;
					}
				}

			}
			else if(x[i][j] == 2){
				printf("%s\n", S[i]);
			}
		}
	}	


	//LIBERACAO DE MEMORIA
	for(i=0;i<T;i++){
		free(S[i]);
		free(x[i]);
		free(y[i]);
	}
	free(S);
	free(Q);
	free(x);
	free(y);

	return 0;
}