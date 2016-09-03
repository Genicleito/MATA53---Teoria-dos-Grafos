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
		//if(!visitados[no]){
			for(int i = 0; i < G[no].size(); i++){
				if(!visitados[G[no][i]]){
					//if(!visitados[no]){
						fila.push_back(G[no][i]);
						distancias[G[no][i]] = distancias[no] + 1;
						visitados[G[no][i]] = 1;
					//}
				}
			}
			//visitados[no] = 1;
		//}

		fila.pop_front();
		vMaisLonge = no;
	}
	return vMaisLonge;
}

int main(){
	int n, x, y, teste = 1;
	
	for(cin >> n; n != 0; cin >> n, teste++) {
		/* Inicialização do Grafo e leitura dos nomes dos */
		int distancias[n];
	    for(int i = 0; i < n; i++){
			G[i].clear();
			visitados[i] = 0;
			distancias[i] = MAX;
		}

		/* Leitura das relações e preencimento do grafo */
		for (int i = 0; i < n - 1; i++){
			cin >> x >> y;
			G[x - 1].push_back(y - 1);
			G[y - 1].push_back(x - 1);
		}

		int v = BFS(1, distancias);	// Começar do vértice 0 (1 - 1)
		/* Inicialização das distancias e dos vértices visitados */
		int distancias2[n];
		for(int i = 0; i < n; i++){
			visitados[i] = 0;
			distancias2[i] = MAX;
		}

		if(n != 1){		// Se for mais de um vertice para nao dar erro
			/* Nova busca pelo vértice mais distante de v */
			v = BFS(v + 1, distancias2);

			v = distancias2[v] / 2;

			printf("Teste %d\n", teste);
			int j;
			for(j = 0; j < n; j++){		// Se o maior caminho for ímpar
				if(distancias[j] == v && distancias2[j] == v){
					cout << j + 1 << endl << endl;
					break;
				}
			}

			if(j == n){		// Se o maior caminho for par
				int verticeMeio = -1;
				for(int i = 0; i < n; i++){
					if(distancias[i] == v){
						if(verticeMeio > 0){
							if(distancias2[i] < distancias2[verticeMeio]){
								verticeMeio = i;
							}
						}else
							verticeMeio = i;
					}
				}
				cout << verticeMeio + 1 << endl << endl;
			}
		}else{
			cout << "Teste " << teste << endl << "1" << endl << endl;
		}

/*		printf("Teste %d\n", teste);
		for(int i = 0; i < n; i++){
			if(distancias[i] == v){
				cout << i + 1 << endl << endl;
				break;
			}
		}
*/	}
	return 0;
}