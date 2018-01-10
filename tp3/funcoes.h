//estrutura da rua
typedef struct{
	int esq;
	int dir;
} lados;

//funcao de comparacao do quicksort
int cmp(const void *a, const void *b); //O(1)

//funcao de conversao de decimal para binario em um vetor de bits
void converte_bin(int num, int N, int *vetor); //O(n)

//funcao para achar o maximo entre dois numeros
int max(int a, int b); //O(1)

//algoritmos
void guloso(); //O(n³)
void dinamico(); //O(n²)
void bruto(); //O(n2^n)