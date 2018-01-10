#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int fimDePalavra;
    struct no *letras[26]; //97 a 122
} t_Trie;

t_Trie* criaTrie(t_Trie *arvore){
    int i;
    arvore = malloc(sizeof(struct no));

    for(i=0;i<26;i++){
        arvore->letras[i] = NULL;
    }
    arvore->fimDePalavra = 0;

    return arvore;
}

int insere(t_Trie *arvore, char palavra[]){
    int i, j, tam, prefixo = 0;
    tam = strlen(palavra);
    
    for(i=0;i<tam;i++){
        if(arvore->letras[palavra[i] - 97] == NULL){
            struct no *n;
            n = malloc(sizeof(struct no));
            for(j=0;j<26;j++){
                n->letras[j] = NULL;
            }
            n->fimDePalavra = 0;
            arvore->letras[palavra[i] - 97] = n;
            arvore = n;
        }
        else{ 
            if(i == tam-1){
			    //printf("conjunto ruim\n");
                prefixo = 1;
		    }
            arvore = arvore->letras[palavra[i] - 97];
        }
        if(arvore->fimDePalavra == 1){
            //printf("conjunto ruim\n");
            prefixo = 1;
        }
    }

    arvore->fimDePalavra = 1;
    return prefixo;
}

//esse codigo tem memory leak, mas foda-se
int main(){
    int i, j, N;
    char palavra[101];
    t_Trie *arvore;

    do{
        j=0;
        arvore = criaTrie(arvore);
        scanf("%d", &N);
        for(i=0;i<N;i++){
            scanf("%s", palavra);
            j = j + insere(arvore, palavra);
        }
        if(j > 0){
            printf("Conjunto Ruim\n");
        }
        else if(j == 0 && N != 0){
            printf("Conjunto Bom\n");
        }

    }while(N>0);
   
}