#include <stdio.h>

#define MAXN 10010
#define MAXM 20010
#define INF 4000020		//MAXM * |MAXT| + 1

typedef struct Aresta {
	int u, v, peso;
}Aresta;

Aresta grafo[MAXM];
int distancia[MAXN];

void initializeSingleSource(int n){
	
	for(int i = 0; i <= n; i++){
		distancia[i] = INF;
	}
}

void relax(int u, int v, int pesoUV){
	if(distancia[u] + pesoUV < distancia[v]){
		distancia[v] = distancia[u] + pesoUV;
	}
}

int bellmanFord(int s, int n, int m){
	initializeSingleSource(n);
	distancia[s] = 0;

	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < m; j++) {
			relax(grafo[j].u, grafo[j].v, grafo[j].peso);
		}
	}

	for(int i = 0; i < m; i++) {
		if(distancia[ grafo[i].v ] > distancia[ grafo[i].u ] + grafo[i].peso) {
			return 1;		// Para este problema, eu procuro ciclos de peso negativo
		}
	}
	return 0;	// Para esse problema, se não há ciclo de peso negativo, então retorno false
}

int main(){
	int n; // número de vértices
	int m; // número de arestas
	int c;

    for(scanf("%d", &c); c > 0; c--) {
	    scanf("%d %d", &n, &m);

	    for(int i = 0; i < m; i++){
	        
	        int x, y, t;
	        scanf("%d %d %d", &x, &y, &t);
	        
	        grafo[i].u = x;
	        grafo[i].v = y;
	        grafo[i].peso = t;
		}

		if (bellmanFord(0, n, m)){	// Inicia em 0
			printf("possible\n");
		} else {
			printf("not possible\n");
		}

	}

	return 0;
}