#include <stdio.h>
#include <values.h>
#include <vector>

using namespace std;

#define MAXN 100
#define MAXM 10000

const int INF = MAXINT/2;

int grafo[MAXN][MAXN];

void inicializa(){
	for(int i = 0; i < MAXN; i++){
		for(int j = 0; j < MAXN; j++){
			grafo[i][j] = INF;
		}
	}
}


void floydWarshall(int n) {

	for (int k = 0; k < n; k++){
        
		for (int i = 0; i < n; i++){

			for (int j = 0; j < n; j++){
				if (grafo[i][k] + grafo[k][j] < grafo[i][j])
					grafo[i][j] = grafo[i][k] + grafo[k][j];
			}
		}
	}
}

int main(){
	int n, m, u, v, w;

	inicializa();

	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &u, &v, &w);

		grafo[u][v] = w;
		grafo[v][u] = w;

	}

	floydWarshall(n);

	int maior = -1;
	vector<int> maiores;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(maior < grafo[i][j]){
				maior = grafo[i][j];
			}
		}
		maiores.push_back(maior);
		maior = -1;
	}
	int menor = INF;
	for(int i = 0; i < (int) maiores.size(); i++){
		if(menor > maiores[i])
			menor = maiores[i];
	}
	printf("%d", menor);

	return 0;
}