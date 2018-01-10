#include <stdio.h>

void converte(int nMaja[], int nWilli, int aux){
    
    int i;
	while(1 == 1){
		if(nWilli == 1) return;

		aux++, nMaja[1]++, nWilli--;

		if(nWilli == 1) return;

		for(i=0;i<(aux-1);i++){
			nMaja[0]--;
			nMaja[1]++;
			nWilli--;
			if(nWilli == 1) return;
		}

		for(i=0;i<aux;i++){
			nMaja[0]--;
			nWilli--;
			if(nWilli == 1) return;
		}

		for(i=0;i<aux;i++){
			nMaja[1]--;
			nWilli--;
			if(nWilli == 1) return;
		}

		for(i=0;i<aux;i++){
			nMaja[0]++;
			nMaja[1]--;
			nWilli--;
			if(nWilli == 1) return;
		}

		for(i=0;i<aux;i++){
			nMaja[0]++;
			nWilli--;
			if(nWilli == 1) return;
		}

		for(i=0;i<aux;i++){
			nMaja[1]++;
			nWilli--;
			if(nWilli== 1) return;
		}
	}
}

int main(){
	int nMaja[2], nWilli;
	int aux;

    while(scanf("%d", &nWilli) == 1){

		nMaja[0] = nMaja[1] = aux = 0;
		converte(nMaja, nWilli, aux);
		printf("%d %d\n", nMaja[0], nMaja[1]);

	}
}