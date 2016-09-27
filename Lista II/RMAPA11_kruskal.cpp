/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
//#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
//#include <stack>

#define MAXN 500
#define MAXM 124750

using namespace std;

typedef struct aresta{
	int u, v, peso;
} Aresta;

//int grafo[MAXN][MAXN];
Aresta aresta[MAXM];
//vector<Aresta> aresta;
//vector<int> A;
//vector<Aresta> aresta;
//stack<int> mst;
int somaCustoTotal;
vector<int> pai, peso;

bool comparar (Aresta arestaX, Aresta arestaY) {
	return (arestaX.peso < arestaY.peso);
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
		peso[v]++;
	}
}

void kruskal(int m){
	//printf("antes\n");
	//for(int i = 0; i < m; i++){
		//printf("[%d] = %d\n", i, aresta[i].peso);
	//}
	//printf("depois\n");
	sort(aresta, aresta + m, comparar);
	somaCustoTotal = 0;

	//printf("aresta[0] == %d\n", aresta[0].peso);

	//printf("aresta.size = %d\n", aresta.size());
	//printf("depois\n");
	//for(int i = 0; i < m; i++){
		//printf("[%d] = %d\n", i, aresta[i].peso);
	//}

	for (int i = 0; i < m; i++){
		if(find(aresta[i].u) != find(aresta[i].v)){		// Se não estiverem na mesma componente
			unir(aresta[i].u, aresta[i].v);
			//printf("peso %d\n", aresta[i].peso);
			somaCustoTotal += aresta[i].peso;
			//printf("pesos: %d ", aresta[i].peso);
		}
	}

}

int main(){
	int n, m, u, v, c;

	scanf("%d %d", &n, &m);

	//aresta.resize(m);
	pai.resize(n);
	peso.resize(n);

	//aresta.clear();
	peso.clear();


	for(int i = 0; i < n; i++){
		pai[i] = i;
	}

	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &u, &v, &c);
		aresta[i].u = u - 1;
		aresta[i].v = v - 1;
		aresta[i].peso = c;

		//grafo[u - 1][v - 1] = c;
		//grafo[v - 1][u - 1] = c;
		//printf("[%d].peso = %d\n", i, aresta[i].peso);
	}

	kruskal(m);

	printf("%d\n", somaCustoTotal);

	return 0;
}