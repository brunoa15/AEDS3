#include <stdio.h>

const int MaxN=1000001;

int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int main() {
	int N, K, T;
    int dp[MaxN], pos[MaxN], valor[MaxN];
    int i, j, k;

	scanf("%d", &T);
	for(i=0;i<T;i++){
		
        scanf("%d%d", &N, &K);

		for(j=1;j<=N;j++){
            scanf("%d", &pos[j]);
        }
            
		for(j=1;j<=N;j++){
            scanf("%d", &valor[j]);
        }
        
        k=0;
		for(j=1;j<=N;j++) {
			while(pos[j]-pos[k+1] >= K){
                k++;
            }
            
			dp[j] = max(dp[j-1], valor[j]+dp[k]);
		}

		printf("%d\n", dp[N]);

	}
	
}