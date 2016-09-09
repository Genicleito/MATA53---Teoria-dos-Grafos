/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
//#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int tempo;
//vector< pair<int, int> > criticalLinks;
//int criticalLinks;
vector< vector<int> > grafo;
int *low, *d, *pai, *criticalLinks;//, qtdCriticalLinks;

void DFS(int vertice){

	d[vertice] = tempo++;
	low[vertice] = d[vertice];
	int cont = 0;

	for(int i = 0; i < (int) grafo[vertice].size(); i++){
		int no = grafo[vertice][i];
		if(d[no] == -1){
			cont++;
			pai[no] = vertice;
			DFS(no);

			if(low[vertice] > low[no]){
				low[vertice] = low[no];

			}
			if(low[no] >= d[vertice]){
				criticalLinks[vertice] = 1;
			}

		}else if((pai[vertice] != no) && (low[vertice] > d[no])) {
			low[vertice] = d[no];
		}
	}
	if (vertice == 0){
		criticalLinks[vertice] = cont >= 2;
	}
}
int main(){
	int n, m, x, y, teste = 1;

	for(scanf("%d %d", &n, &m); n != 0 || m != 0; scanf("%d %d", &n, &m), teste++){
		grafo.resize(n);
		low = (int *) malloc (n * sizeof(int));
		d = (int *) malloc (n * sizeof(int));
		pai = (int *) malloc (n * sizeof(int));
		criticalLinks = (int *) malloc (n * sizeof(int));

		for(int i = 0; i < n; i++){
			grafo[i].clear();
			d[i] = -1;
			low[i] = 0;
			pai[i] = -1;
			criticalLinks[i] = 0;
		}
		for(int j = 0; j < m; j++){
			scanf("%d %d", &x, &y); // Lê os vértices e arestas
			/* Cria o grafo não direcionado */
			grafo[x - 1].push_back(y - 1);
			grafo[y - 1].push_back(x - 1);
		}
		tempo = 0;
		//for(int i = 0; i < n; i++){
			//if(d[i] == -1){		// Precisa ou o grafo é sempre conexo ?
				pai[0] = -1;
				DFS(0);
			//}
		//}

		printf("Teste %d\n", teste);

		int vazio = 1;
		for(int i = 0; i < n; i++){
			if(criticalLinks[i] != 0){
				printf("%d ", i + 1);
				vazio = 0;
			}
		}
		if(vazio)
			printf("nenhum");
		printf("\n\n");
	}

	return 0;
}
