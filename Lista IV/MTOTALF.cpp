#include <stdio.h>
#include <values.h>
#include <vector>
#include <list>

using namespace std;

const int INF = MAXINT/2;

#define MAXN 800
//#define MAXN 6

int grafo[MAXN][MAXN];
int grafoResidual[MAXN][MAXN];

int visitados[MAXN];
int ancestral[MAXN];

void inicializa(){
	for (int j = 0; j < MAXN; j++){
		for(int k = 0; k < MAXN; k++){
			grafo[j][k] = grafoResidual[j][k] = 0;
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

int cToInt(char c){
	int intC = (int) c;

	if(intC < 91)	// ... < 91 ou ... < 93 ?
		return intC -= 65;
	return intC -= 71;
}

int main() {
	
	inicializa();

	int n, f;
	char a, b;

	scanf("%d", &n);

	while(n--){
		scanf(" %c %c %d", &a, &b, &f);

		grafo[ cToInt(a) ][ cToInt(b) ] += f;
		//grafo[ cToInt(b) ][ cToInt(a) ] = f;
	}

	printf("%d\n", fordFulkerson(0, 25));

	return 0;
}
