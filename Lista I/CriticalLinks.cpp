/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <bits/stdc++.h>

using namespace std;

int tempo;
vector<int> criticalLinks;
vector< vector<int> > grafo;
int *low, *d, *pai, qtdCriticalLinks;

void DFS(int vertice){
	//visitado[vertice] = 1;
	
	//tempo++;
	d[vertice] = tempo++;
	low[vertice] = d[vertice];

	for(int i = 0; i < (int) grafo[vertice].size(); i++){
		int no = grafo[vertice][i];
		if(d[no] == -1){
			pai[no] = vertice;
			DFS(no);
//printf("DebugPreIF\n");
	//printf("low de %d = %d e d de %d = %d \n", grafo[vertice][i], low[ grafo[vertice][i] ], vertice, d[vertice]);
			if(low[vertice] > low[no]){
				low[vertice] = low[no];
//printf("Debug\n");
			}
			if(low[no] == d[no]){
				qtdCriticalLinks++;
				criticalLinks.push_back(vertice);
				criticalLinks.push_back(no);
			}
			//low[vertice] = min(low[vertice], low[ grafo[vertice][i] ]);
		}else if((pai[vertice] != no) && (low[vertice] > d[no])) {
			low[vertice] = d[no];
		}
	}
	//tempo++;
}

bool ordenarResultado (int x, int y) {
	return (x < y);
}

int main(){
	int n, x, v, y;

	while(scanf("%d", &n) != EOF) {
		grafo.resize(n);
		low = (int *) malloc (n * sizeof(int));
		d = (int *) malloc (n * sizeof(int));
		pai = (int *) malloc (n * sizeof(int));

		for(int i = 0; i < n; i++){
			grafo[i].clear();
			//criticalLinks.clear();
			d[i] = -1;
			low[i] = 0;
			pai[i] = -1;
		}
		
		for(int j = 0; j < n; j++){
			scanf("%d (%d)", &v, &x); // Lê os vértices e arestas
//printf("%d %d <--\n", v, x);
			for(int i = 0; i < x; i++){
				scanf("%d", &y);
				grafo[v].push_back(y);
				grafo[y].push_back(v);
			}
		}

		qtdCriticalLinks = tempo = 0;
		for(int i = 0; i < n; i++){
			if(d[i] == -1){
				pai[i] = i;
				DFS(i);
			}
		}

		printf("%d critical links\n", qtdCriticalLinks);
		sort(criticalLinks.begin(), criticalLinks.end(), ordenarResultado);
		//qtdCriticalLinks = 0;
		for(int j = 0; j < (int) criticalLinks.size(); j++){
			// printf("%d - %d\n", criticalLinks[k], criticalLinks[k + 1]);
			// criticalLinks.pop_front();
			// criticalLinks.pop_front();
			printf("%d - ", criticalLinks[j]);
			//criticalLinks.pop_front();
			printf("%d\n", criticalLinks[++j]);
			//criticalLinks.pop_front();
		}
		criticalLinks.clear();
		printf("\n");
	}

	return 0;
}