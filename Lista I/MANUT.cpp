/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <bits/stdc++.h>

using namespace std;

int tempo;
//vector< pair<int, int> > criticalLinks;
//int criticalLinks;
vector< vector<int> > grafo;
int *low, *d, *pai, *criticalLinks;//, qtdCriticalLinks;

void DFS(int vertice){
	//visitado[vertice] = 1;

	d[vertice] = tempo++;
	low[vertice] = d[vertice];

	for(int i = 0; i < (int) grafo[vertice].size(); i++){
		int no = grafo[vertice][i];
		if(d[no] == -1){
			pai[no] = vertice;
			DFS(no);

			if(low[vertice] > low[no]){
				low[vertice] = low[no];

			}
			if(low[no] == d[no]){
				//qtdCriticalLinks++;
				//criticalLinks.push_back(vertice);
				criticalLinks[vertice] = 1;
			}
		}else if((pai[vertice] != no) && (low[vertice] > d[no])) {
			low[vertice] = d[no];
		}
	}
}
/*
bool ordenarResultado (int x, int y) {
	return (x < y);
}
*/
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
		//criticalLinks.clear();
//printf("m = %d\n", m);
		for(int j = 0; j < m; j++){
			scanf("%d %d", &x, &y); // Lê os vértices e arestas
			/* Cria o grafo não direcionado */
			grafo[x - 1].push_back(y - 1);
			grafo[y - 1].push_back(x - 1);
		}
//printf("DEBUG\n");
		tempo = 0;
		for(int i = 0; i < n; i++){
			if(d[i] == -1){		// Precisa ou o grafo é sempre conexo ?
				pai[i] = i;
				DFS(i);
			}
		}

		printf("Teste %d\n", teste);
		// if(criticalLinks.empty())
		// 	printf("nenhum\n");

		// sort(criticalLinks.begin(), criticalLinks.end());	// Precisa ordenar ?
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
		
		//criticalLinks.clear();
	}

	free(low);
	free(d);
	free(pai);
	free(criticalLinks);
	
	return 0;
}