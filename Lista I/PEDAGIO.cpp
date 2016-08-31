/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <bits/stdc++.h>
#define MAX 5001

using namespace std;

vector<int> G[MAX];
int visitados[MAX];


void BFS(int v, int p, int *distancias){

	list<int> fila;
//printf("vertice inicial = %d\n\n", v);
	fila.push_back(v - 1);
	distancias[v - 1] = 0;
	//visitados[v - 1] = 1;

	while(!fila.empty()){
		int no = fila.front();	// Visitando nó
		// if (!visitados[no]){		// Opcional ?
			visitados[no] = 1;
			for(int i = 0; i < G[no].size(); i++){
				if(!visitados[G[no][i]]){
					fila.push_back(G[no][i]);
					if(distancias[G[no][i]] > distancias[no] + 1)
						distancias[G[no][i]] = distancias[no] + 1;
					//printf("Vertice %d tá a uma distancia de %d de %d\n-- O pai de %d eh %d\n", G[no][i] + 1, distancias[G[no][i]], v, G[no][i] + 1, no + 1);
					//aux--;
				}
			}
		// }

		fila.pop_front();
	}
}

int main(){
	int c, e, l, p, x, y, teste = 1;
	
	for(cin >> c >> e >> l >> p; (c + e + l + p) != 0; cin >> c >> e >> l >> p, teste++) {
		/* Inicialização do Grafo e leitura dos nomes dos */
		int distancias[c];
	    for(int i = 0; i < c; i++){
			G[i].clear();
			visitados[i] = 0;
			distancias[i] = MAX;
		}

		/* Leitura das relações e preencimento do grafo */
		for (int i = 0; i < e; i++){
			cin >> x >> y;
			G[x - 1].push_back(y - 1);
			G[y - 1].push_back(x - 1);
		}

		/* Realizar a busca em todos os vertices (que não foram visitados) */
		// for(int i = 0; i < c; i++){
		// 	if(!visitados[i])
				//Max = max(Max, BFS(i));
		// }
		BFS(l, p, distancias);
		list<int> resposta[c];
		
		//cout << "Teste " << teste << endl;	//ATENCAO
		printf("Teste %d\n", teste);
		for(int i = 0; i < c; i++){
			if(distancias[i] <= p && distancias[i] != 0)
				cout << i + 1 << " ";
		}
		cout << endl << endl;
	}
	return 0;
}