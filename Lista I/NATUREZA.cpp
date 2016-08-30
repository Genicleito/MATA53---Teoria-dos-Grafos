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


int BFS(int v){
	int cont = 0;

	list<int> fila;

	fila.push_back(v);

	while(!fila.empty()){
		int no = fila.front();	// Visitando nó
		if (!visitados[no]){
			cont++;
			visitados[no] = 1;
			for(int i = 0; i < G[no].size(); i++){
				if(!visitados[G[no][i]])
					fila.push_back(G[no][i]);
			}
		}
		fila.pop_front();
	}
	return cont;
}

int main(){
	int c, r;
	
	for(cin >> c >> r; c != 0 || r != 0; cin >> c >> r) {
		map<string, int> nomes;
		string c1, c2;
		/* Inicialização do Grafo e leitura dos nomes dos */
	    for(int i = 0; i < c; i++){
			G[i].clear();
			visitados[i] = 0;
			cin >> c1;
			nomes[c1] = i;
		}

		/* Leitura das relações e preencimento do grafo */
		for (int i = 0; i < r; i++){
			cin >> c1 >> c2;
			G[nomes[c1]].push_back(nomes[c2]);
			G[nomes[c2]].push_back(nomes[c1]);
		}

		/* Realizar a busca em todos os vertices (que não foram visitados) e retornar
		 * o número de vertices de cada componente conexa. */
		int Max = 0;
		for(int i = 0; i < c; i++){
			if(!visitados[i])
				Max = max(Max, BFS(i));
		}
		cout << Max << endl;
	}
	return 0;
}