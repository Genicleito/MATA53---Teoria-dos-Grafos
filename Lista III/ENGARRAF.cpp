/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/

#include <stdio.h>
#include <vector>

#define INF 20000000
#define MAXN 200

using namespace std;

int visitado[MAXN];
int distancia[MAXN];
int grafo[MAXN][MAXN];
int deuRuim = 0;

void inicializa(int n){
	deuRuim = 0;
	//visitado.clear();
	//distancia.clear();

	for(int j = 0; j < n; j++) {
		visitado[j] = 0;
		distancia[j] = INF;

		for(int k = 0; k < n; k++){
			grafo[j][k] = INF;
		}
	}
}

void dijkstra(int s, int n){
	distancia[s] = 0;

	for(int g = 0; g < n; g++) {
		int no = -1;
		for(int i = 0; i < n; i++){
			if(!visitado[i] && (no == -1 || distancia[i] < distancia[no]))
				no = i;
		}
		visitado[no] = 1;

		if(distancia[no] == INF){
			deuRuim = 1;
			break;
		}

		for(int i = 0; i < n; i++){	//	Lista de Adj
			if(distancia[i] > distancia[no] + grafo[no][i])
				distancia[i] = distancia[no] + grafo[no][i];
		}
	}
}

int main(){
	int n, m;

	for(scanf("%d %d", &n, &m); n + m != 0; scanf("%d %d", &n, &m)){

		int u, v, tempo;

		inicializa(n);

		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &tempo);

			grafo[u - 1][v - 1] = tempo;
		}
		
		int s, d;
		scanf("%d %d", &s, &d);	// Inicio e destino

		dijkstra(s - 1, n);

		if(deuRuim && distancia[d - 1] == INF){
			printf("-1\n");
		}else{
			printf("%d\n", distancia[d - 1]);
		}
	}
}