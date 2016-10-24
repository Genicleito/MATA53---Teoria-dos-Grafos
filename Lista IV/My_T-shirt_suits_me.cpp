#include <stdio.h>
#include <values.h>
#include <vector>
#include <list>
#include <string.h>

using namespace std;

const int INF = MAXINT/2;

#define MAXN 40		//	(6 + m + 2)		// 6 cores
#define MAXM 100		// (6 + (m * 3))	// 6 cores

int grafo[MAXN][MAXN];
int grafoResidual[MAXN][MAXN];

int visitados[MAXN];
int ancestral[MAXN];

int numCores = 0;
int XXL = 0, XL = 0, L = 0, M = 0, S = 0, XS = 0;

void inicializa(){
	numCores = 0;
	XXL = XL = L = M = S = XS = 0;
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

int sToInt(char tam[]){
	if(strcmp(tam, "XXL") == 0){
		if(!XXL){
			XXL = 1;
			numCores++;
		}
		return 0;
	}else if(strcmp(tam, "XL") == 0){
		if(!XL){
			XL = 1;
			numCores++;
		}
		return 1;
	}else if(strcmp(tam, "L") == 0){
		if(!L){
			L = 1;
			numCores++;
		}
		return 2;
	}else if(strcmp(tam, "M") == 0){
		if(!M){
			M = 1;
			numCores++;
		}
		return 3;
	}else if(strcmp(tam, "S") == 0){
		if(!S){
			S = 1;
			numCores++;
		}
		return 4;
	}else if(strcmp(tam, "XS") == 0){
		if(!XS){
			XS = 1;
			numCores++;
		}
		return 5;
	}
}

int main() {
	int caso, n, m;
	char tam1[5], tam2[5];

	scanf("%d", &caso);

	for(int g = 1; g <= caso; g++){
		
		inicializa();

		scanf("%d %d", &n, &m);
		for(int i = m; i > 0; i--){
			scanf(" %s %s", tam1, tam2);

			grafo[ sToInt(tam1) ][ 5 + i ] = 1;		// 5 espaços no grafo estão reservados para as cores [0, ..., 5]
			grafo[ sToInt(tam2) ][ 5 + i ] = 1;
		}
		// Criar as ligações que chegam em t
		for(int i = 6; i < m + 6; i++){
			grafo[i][6 + m] = 1;		// t fica na posição m + 6 da coluna do grafo
		}
		// Criar as ligações que saem de s
		for(int i = 0; i < 6; i++){
			grafo[6 + m + 1][i] = n / 6;		// s fica na posição m + 6 + 1 da coluna do grafo
		}
		int s = 6 + m + 1;
		int t = m + 6;

		if(fordFulkerson(s, t) == m){
			printf("YES\n");
		}else{
			printf("NO\n");
		}

	}
	return 0;
}
