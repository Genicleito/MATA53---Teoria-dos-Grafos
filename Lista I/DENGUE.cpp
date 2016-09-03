/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <bits/stdc++.h>
#define MAX 102

using namespace std;

vector<int> G[MAX];
int visitados[MAX];

int BFS(int v, int *distancias){
	int vMaisLonge;
	list<int> fila;

	fila.push_back(v - 1);
	distancias[v - 1] = 0;
	visitados[v - 1] = 1;

	while(!fila.empty()){
		int no = fila.front();	// Visitando nó
		for(int i = 0; i < G[no].size(); i++){
			if(!visitados[G[no][i]]){
				fila.push_back(G[no][i]);
				distancias[G[no][i]] = distancias[no] + 1;
				visitados[G[no][i]] = 1;
			}
		}
		fila.pop_front();
		vMaisLonge = no;
	}
	return vMaisLonge;
}

int main(){
	int n, x, y, teste = 1;
	
	for(cin >> n; n != 0; cin >> n, teste++) {
		
		/* Inicialização do Grafo e leitura dos nomes dos */
		int distancias[n], maioresDistancias[n];
	    for(int i = 0; i < n; i++){
			G[i].clear();
			visitados[i] = 0;
			distancias[i] = MAX;
			maioresDistancias[i] = 0;
		}

		/* Leitura das relações e preencimento do grafo */
		for (int i = 0; i < n - 1; i++){
			cin >> x >> y;
			G[x - 1].push_back(y - 1);
			G[y - 1].push_back(x - 1);
		}

		for (int i = 0; i < n; i++){
			int v = BFS(i + 1, distancias);
			maioresDistancias[i] = distancias[v];
			
			/* Inicializar novamente para próxima chamada */
			for (int j = 0; j < n; j++){
				visitados[j] = 0;
				distancias[j] = MAX;
			}
		}
		
		int menor = MAX, resp;
		for (int i = 0; i < n; i++){
			if(maioresDistancias[i] < menor){
				menor = maioresDistancias[i];
				resp = i;
			}
		}

		printf("Teste %d\n%d\n\n", teste, resp + 1);
	}
	return 0;
}