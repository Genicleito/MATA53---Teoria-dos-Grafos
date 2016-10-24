#include <stdio.h>
#include <values.h>
#include <vector>

using namespace std;

#define MAXN 120
#define MAXM 100000

const int INF = MAXINT/2;

int grafo[MAXN][MAXN][MAXN];

void inicializa(){

	for(int i = 0; i < MAXN; i++){
		for(int j = 0; j < MAXN; j++){
			for(int k = 0; k < MAXN; k++){
				if(k == j)
					grafo[i][j][k] = 0;
				else
					grafo[i][j][k] = INF;
			}
		}
	}
}

void relaxar(int i, int j, int k){
	if(grafo[i - 1][j][i - 1] + grafo[i - 1][i - 1][k] > grafo[i - 1][j][k]){
		grafo[i][j][k] = grafo[i - 1][j][k];
	}else{
		grafo[i][j][k] = grafo[i - 1][j][i - 1] + grafo[i - 1][i - 1][k];
	}
}

void floydWarshall(int n) {

	for (int i = 1; i <= n; i++){
        
		for (int j = 0; j < n; j++){

			for (int k = 0; k < n; k++){
				relaxar(i, j, k);
			}
		}
	}
}

int main(){
	int n, m, u, v, w;
	
	for(int instancia = 1; scanf("%d %d", &n, &m) != EOF; instancia++){

		inicializa();

		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &w);

			if(grafo[0][u - 1][v - 1] > w)
				grafo[0][u - 1][v - 1] = w;
		}

		floydWarshall(n);

		printf("Instancia %d\n", instancia);
		int c;
		for(scanf("%d", &c); c > 0; c--){
			int o, d, t;
			scanf("%d %d %d", &o, &d, &t);

			if (grafo[t][o - 1][d - 1] != INF){
				printf("%d\n", grafo[t][o - 1][d - 1]);
			}else{
				printf("-1\n");
			}
		}
		printf("\n");
	}
	return 0;
}