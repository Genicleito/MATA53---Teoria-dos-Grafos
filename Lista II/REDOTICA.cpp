/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
//#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define MAXN 100
#define MAXM 5000

using namespace std;

typedef struct aresta{
	int u, v, peso;
} Aresta;

Aresta aresta[MAXM];
//stack<Aresta> mst;
Aresta mst[MAXM];
//int somaCustoTotal;
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
	//somaCustoTotal = 0;
	fimMST = 0;

	for (int i = 0; i < m; i++){
		if(find(aresta[i].u) != find(aresta[i].v)){		// Se não estiverem na mesma componente
			unir(aresta[i].u, aresta[i].v);
			//mst.push(aresta[i]);
			//printf("u = %d e v = %d\n", aresta[i].u + 1, aresta[i].v + 1);
			if(aresta[i].u > aresta[i].v){
				//printf("u = %d e v = %d\n", aresta[i].u, aresta[i].v);
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
	int n, m, x, y, z, teste = 1;

	for (scanf("%d %d", &n, &m); n != 0; scanf("%d %d", &n, &m), teste++) {
		pai.resize(n);
		peso.resize(n);

		peso.clear();


		for(int i = 0; i < n; i++){
			pai[i] = i;
		}

		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &z);
			aresta[i].u = x - 1;
			aresta[i].v = y - 1;
			aresta[i].peso = z;
		}

		kruskal(m);

		printf("Teste %d\n", teste);
		//printf("tamMst == %d\n", fimMST);

		//sort(mst, mst+fimMST, comparaVertice);
		sort(mst, mst+fimMST, comparaAresta);

		//for(int i = 1; i < n; i++){
		//while(!mst.empty()){
		for(int i = 0; i < fimMST; i++){
			//Aresta edge = mst.top();
			//mst.pop();		// Removo
			if(mst[i].u < mst[i].v)
				printf("%d %d\n", mst[i].u + 1, mst[i].v + 1);
			else
				printf("%d %d\n", mst[i].v + 1, mst[i].u + 1);
		}
		printf("\n");
	}

	return 0;
}