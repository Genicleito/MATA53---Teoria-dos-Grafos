#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAXN 1050

using namespace std;

// typedef struct aresta {
// 	int u, v, valor;
// }Aresta;

int aresta[MAXN][MAXN];

int N;

void inicializar(){
	for(int j = 0; j < N; j++)
		for(int k = 0; k < N; k++)
			aresta[j][k] = 0;
}

void encontrarCircuito(int u){
	for(int j = 0; j < N; j++){
		if(aresta[u][j]){
			aresta[u][j] -= 1;
			aresta[j][u] -= 1;
			encontrarCircuito(j);
		}
	}
	printf("vertice %d\n", u + 1);
}

int main(){
	int t, n, u, v;
	
	scanf("%d", &t);	
	for(int g = 0; g < t; g++){
		//inicializar();

		scanf("%d", &n);
		N = n;

		//Aresta aresta[n];
		inicializar();

		for(int i = 0; i < n; i++){
			scanf("%d %d", &u, &v);
			//aresta[i].push_back(u);
			//aresta[i].push_back(v);
			aresta[u - 1][v - 1] += 1;
			aresta[v - 1][u - 1] += 1;
		}

		encontrarCircuito(u - 1);

	}

	return 0;
}