/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

int tempo;
list<int> criticalLinks;
vector< vector<int> > grafo;
int *low, *d, *visitado, *pai, qtdCriticalLinks = 0;

void DFS(int vertice){
	visitado[vertice] = 1;
	
	tempo++;
	d[vertice] = tempo;
	low[vertice] = tempo;

	for(int i = 0; i < (int) grafo[vertice].size(); i++){
		if(!visitado[ grafo[vertice][i] ]){
			//pai[ grafo[vertice][i] ] = vertice;
			DFS(grafo[vertice][i]);
			printf("Aqui1\n");
	//printf("low de %d = %d e d de %d = %d \n", grafo[vertice][i], low[ grafo[vertice][i] ], vertice, d[vertice]);
			if(low[ grafo[vertice][i] ] > d[vertice]){
				criticalLinks.push_back(vertice);
				criticalLinks.push_back(grafo[vertice][i]);
				printf("AQui\n");
				qtdCriticalLinks++;
			}
			low[vertice] = min(low[vertice], low[ grafo[vertice][i] ]);
		}else if(pai[ grafo[vertice][i] ] != vertice){
			low[vertice] = min(low[vertice], d[ grafo[vertice][i] ]);
		}
	}
	//tempo++;

//	sop[cont++] = vertice;
}

int main(){
	int n, x, v, y;

	while(scanf("%d", &n) != EOF) {
		grafo.resize(n);
		low = (int *) malloc (n * sizeof(int));
		d = (int *) malloc (n * sizeof(int));
		visitado = (int *) malloc (n * sizeof(int));
		pai = (int *) malloc (n * sizeof(int));
printf("N eh igual a: %d\n", n);
		for(int i = 0; i < n; i++){
			grafo[i].clear();
			visitado[i] = 0;
			d[i] = 0;
			low[i] = 0;
			pai[i] = -1;
		}
		
		for(int j = 0; j < n; j++){
			scanf("%d (%d)", &v, &x); // Lê os vértices e arestas
printf("%d %d <--\n", v, x);
			//scanf("(%d)", &x);	// Lê o número de arestas
printf("numero de arestas --> %d\n", x);
			for(int i = 0; i < x; i++){
				scanf("%d", &y);
				grafo[v].push_back(y);
				grafo[y].push_back(v);
			}
		}

			tempo = 0;
			for(int i = 0; i < n; i++){
				if(!visitado[i]){
					DFS(i);
				}
			}

			printf("%d critical links\n", qtdCriticalLinks);
			qtdCriticalLinks = 0;
			while(!criticalLinks.empty()){
				// printf("%d - %d\n", criticalLinks[k], criticalLinks[k + 1]);
				// criticalLinks.pop_front();
				// criticalLinks.pop_front();
				printf("%d - ", criticalLinks.front());
				criticalLinks.pop_front();
				printf("%d\n",criticalLinks.front() );
				criticalLinks.pop_front();
			}
			printf("\n");
			//criticalLinks.clear();	// Precisa ?
		}
		// if(n == 0){
		// 	printf("%d critical links\n", n);
		// }

	return 0;
}