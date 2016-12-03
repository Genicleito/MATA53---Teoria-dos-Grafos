#include <stdio.h>
#include <values.h>
#include <vector>
#include <list>

using namespace std;

const int INF = MAXINT/2;

#define MAXN 2000
//#define MAXN 6

int grafo[MAXN][MAXN];
int grafoIn[MAXN][MAXN];
int grafoResidual[MAXN][MAXN];

int visitados[MAXN];
int ancestral[MAXN];

void inicializa(){
	//printf("aqui\n");
	for (int j = 0; j < MAXN; j++){
		visitados[j] = 0;
		ancestral[j] = -1;

		for(int k = 0; k < MAXN; k++){
			grafo[j][k] = grafoResidual[j][k] = grafoIn[j][k] = 0;
		}
	}
}

int BFS(int s, int t){
	list<int> fila;
	
	for(int j = 0; j < MAXN; j++){
		visitados[j] = 0;
	}

	fila.push_back(s);
	visitados[s] = 1;
	ancestral[s] = -1;

	while(!fila.empty()){
		int u = fila.front();
//printf("u = %d\n", u);
		for(int v = 0; v < MAXN; v++){
			if(!visitados[v] && grafoResidual[u][v]){
				fila.push_back(v);
				visitados[v] = 1;
				ancestral[v] = u;
			}
		}
		fila.pop_front();
	}
	//return (visitados[t] == 1);
	return visitados[t];
}

int fordFulkerson(int s, int t) {
	int u, v;
//printf("DEBUG\n");	
	for (u = 0; u < MAXN; u++){
		for (v = 0; v < MAXN; v++){
			grafoResidual[u][v] = grafo[u][v];
		}
	}

	int fluxoMaximo = 0;

	while (BFS(s, t)){
		int gargalo = INF;
		for (v = t; v != s; v = ancestral[v]) {
			u = ancestral[v];
			if(gargalo > grafoResidual[u][v]){
				gargalo = grafoResidual[u][v];
			}
		}

		for (v = t; v != s; v = ancestral[v]) {
			u = ancestral[v];
			grafoResidual[u][v] -= gargalo;
			grafoResidual[v][u] += gargalo;
		}

		fluxoMaximo += gargalo;
//printf("fluxoMaximo = %d\n", fluxoMaximo);
	}
	return fluxoMaximo;
}

int main() {

	int k = 1, p, t, s, c, x, y;

	for(scanf("%d", &k); k > 0; k--){
		scanf("%d %d %d %d", &p, &t, &s, &c);
//printf("hue\n");		
		inicializa();
		int pessoas[p * 2];
		int taxistas[t * 2];

		for(int i = 1; i <= p; i++){
			grafo[0][i] = 1;
		}

		int destino = t + p + 1;

		for(int i = p + 1; i < destino; i++){
			grafo[i][destino] = 1;
		}

		for(int i = 1; i <= p; i++){
			scanf("%d %d", &x, &y);
			grafoIn[i][0] = x;
			grafoIn[i][1] = y;
		}

		for(int i = 1; i <= t; i++){
			scanf("%d %d", &x, &y);
			for(int j = 1; j <= p; j++){

				long long aux1 = x - grafoIn[j][0];
				long long aux2 = y - grafoIn[j][1];
				if(aux1 < 0)
					aux1 = aux1 * (-1);		// Se for negativo multiplico por -1 para ficar positivo
				if(aux2 < 0)
					aux2 = aux2 * (-1);		// Se for negativo multiplico por -1 para ficar positivo
				long long aux3 = c * s;
				if((aux1 + aux2) * 200 <= aux3){
					grafo[j][p + i] = 1;
				}
			}
		}

		int result = fordFulkerson(0, destino);
		printf("%d\n", result);
	}


	return 0;
}
