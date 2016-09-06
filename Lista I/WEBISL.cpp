/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

vector<int> grafo[MAXN];
vector<int> grafoRev[MAXN];

int sop[MAXN];
int sopR[MAXN];

int componente[MAXN], cont, id;

void DFS(vector<int> *grafo, int vertice, int id){
	componente[vertice] = id;
	for(int i = 0; i < (int) grafo[vertice].size(); i++){
		if(componente[grafo[vertice][i]] == -1){
			DFS(grafo, grafo[vertice][i], id);
		}
	}
	sop[cont++] = vertice;
}

int main(){
	int n, m, x, y;

	//for(cin >> n; n != 0; cin >> n++) {
	cin >> n >> m;
		/* Inicialização do Grafo e leitura dos nomes dos */
		//int distancias[n], maioresDistancias[n];
	    for(int i = 0; i < n; i++){
			grafo[i].clear();
			componente[i] = -1;
			// distancias[i] = MAX;
			// maioresDistancias[i] = 0;
		}

		/* Leitura das relações e preencimento do grafo */
		for (int i = 0; i < m; i++){
			cin >> x >> y;
			grafo[x].push_back(y);
			grafoRev[y].push_back(x);
			//G[y - 1].push_back(x - 1);
			componente[i] = -1;
		}
		cont = 0;
		for(int i = 0; i < n; i++){
			if(componente[i] == -1){
				DFS(&grafoRev[0], i, 0);
			}
		}

		for (int i = 0; i < n; i++){
			sopR[i] = sop[i];
			componente[i] = -1;	// Inicializando novamente
		}

		cont = id = 0;
		for(int i = n - 1; i > 0; i--){
			if(componente[sopR[i]] == -1){
				// cout << "DEBUG" << endl;
				DFS(&grafo[0], sopR[i], id++);
			}
		}

		int menor;// = MAXN;
		for(int i = 0; i < n; i++){
			menor = i;
			for(int j = i - 1; j >= 0; j--){
				if(componente[i] == componente[j]){
					menor = j;
				}
			}
			printf("%d\n", menor);
		}


	//}
	return 0;
}