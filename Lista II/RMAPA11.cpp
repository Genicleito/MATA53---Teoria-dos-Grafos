/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
//#include <bits/stdc++.h>
#include <stdio.h>
//#include <stack>

#define MAXN 500

//using namespace std;

int fila[MAXN];
int custo[MAXN];
int grafo[MAXN][MAXN];

int main(){
	int somaCustoTotal = 0, n, m, u, v, c;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		fila[i] = 0;
		custo[i] = MAXN;

		for(int j = 0; j < n; j++){		// Inicializar o grafo
			grafo[i][j] = 0;			// O grafo guarda os pesos de um vertice a seu adjacente
		}
	}

	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &u, &v, &c);
		grafo[u - 1][v - 1] = c;
		grafo[v - 1][u - 1] = c;

	}

	custo[0] = 0;

	for (int i = 0; i < n; i++){
		int no = -1;

		for (int j = 0; j < n; j++){
			if(!fila[j] && (no == -1 || custo[j] < custo[no]))
				no = j;
		}
		fila[no] = 1;	// Fila que guarda o nó desse instante de execucão

		somaCustoTotal += custo[no];

		for(int j = 0; j < n; j++){
			if(grafo[no][j]){		// Se for adj a j
				if(custo[j] > grafo[no][j])
					custo[j] = grafo[no][j];
			}
		}

	}
	printf("%d\n", somaCustoTotal);

	return 0;
}