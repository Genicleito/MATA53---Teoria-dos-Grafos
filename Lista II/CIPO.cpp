/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define MAXN 1000
#define MAXM 2000000

using namespace std;

typedef struct aresta{
	int u, v, peso;
} Aresta;

Aresta aresta[MAXM];
Aresta mst[MAXM];
vector<int> pai, peso;
int fimMST;

bool comparar (Aresta arestaX, Aresta arestaY) {
	return (arestaX.peso < arestaY.peso);
}

bool comparaAresta (Aresta arestaX, Aresta arestaY) {
	if(arestaX.u == arestaY.u)
		return (arestaX.v < arestaY.v);
	return (arestaX.u < arestaY.u);
}

int find(int x){
	if(pai[x] == x)
		return x;
	return pai[x] = find(pai[x]);
}

void unir(int u, int v){

	u = find(u);
	v = find(v);

	if(peso[u] < peso[v])
		pai[u] = v;
	else if(peso[v] < peso[u])
		pai[v] = u;
	else{
		pai[u] = v;
		peso[v]++;	// Percorro mais uma aresta até v, então incremento o peso de v
	}
}

void kruskal(int m){
	sort(aresta, aresta + m, comparar);
	fimMST = 0;
		for (int i = 0; i < m; i++){
		if(find(aresta[i].u) != find(aresta[i].v)){		// Se não estiverem na mesma componente
			unir(aresta[i].u, aresta[i].v);
			if(aresta[i].u > aresta[i].v){
				int aux = aresta[i].u;
				aresta[i].u = aresta[i].v;
				aresta[i].v = aux;
				mst[fimMST++] = aresta[i];
			}else
				mst[fimMST++] = aresta[i];
		}
	}

}

int main(){
	int n, m, u, v, c, instancia = 1;

	for ( ; scanf("%d %d", &n, &m) != EOF; instancia++) {
		pai.resize(n);
		peso.resize(n);

		peso.clear();


		for(int i = 0; i < n; i++){
			pai[i] = i;
		}

		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &c);
			aresta[i].u = u - 1;
			aresta[i].v = v - 1;
			aresta[i].peso = c;
		}

		kruskal(m);

		printf("Instancia %d\n", instancia);
		int custoMST = 0;
		for(int i = 0; i < fimMST; i++){
			custoMST += mst[i].peso;
		}
		printf("%d\n\n", custoMST);
	}

	return 0;
}