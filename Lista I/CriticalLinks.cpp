/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <bits/stdc++.h>

using namespace std;

int tempo;
vector< pair<int, int> > criticalLinks;
vector< vector<int> > grafo;
int *low, *d, *pai, qtdCriticalLinks;

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
				qtdCriticalLinks++;
				if(vertice < no)
					criticalLinks.push_back(make_pair(vertice, no));
				else
					criticalLinks.push_back(make_pair(no, vertice));
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
		sort(criticalLinks.begin(), criticalLinks.end());//, ordenarResultado);
		
		for(int j = 0; j < (int) criticalLinks.size(); j++){
			printf("%d - %d\n", criticalLinks[j].first, criticalLinks[j].second);
		}
		criticalLinks.clear();
		printf("\n");
	}

	return 0;
}