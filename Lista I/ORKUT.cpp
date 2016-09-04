/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <vector>
#include <stdio.h>
//#include <cstdio>
#include <set>

#define MAXN 50000

using namespace std;

int n;	// Vértices
map<strint, int> nomes;

vector<int> grafo[MAXN];
set<int> tree;	// Árvore com os vértices que tem grau de entrada igual a 0
vector<int> resposta;

int grau[MAXN];

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		string amigo;

		grafo[i].clear();
		cin >> amigo;
		nomes[amigo] = i;
	}

	for (int i = 0; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y);

		grau[y]++;
		grafo[x].push_back(y);

	}
	int vEntradaZero = 0;	// Número de vértices com grau de entrada igual a 0
	for (int i = 0; i < n; i++){
		if(grau[i] == 0){
			tree.insert(i);
			vEntradaZero++;
		}
	}

	int sizeTree = (int) tree.size();
	for(int i = 0; i < sizeTree; i++){
		int vAtual = *tree.begin();
		resposta.push_back(vAtual);
		tree.erase(vAtual);

		for (int j = 0; j < (int) grafo[vAtual].size(); j++){
			int vertice = grafo[vAtual][j];

			grau[vertice]--;
			if(grau[vertice] == 0){
				tree.insert(vertice);
				sizeTree++;
			}
		}
	}

	if ((int)resposta.size() < n) {
		printf("*\n");
	}else{
		for(int i = 0; i < sizeTree; i++)
			printf("%d ", resposta[i]);
		printf("\n");
	}

	return 0;
}