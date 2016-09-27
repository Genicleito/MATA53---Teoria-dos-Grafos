/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

typedef struct aresta{
	int u, v;
	double peso;
} Aresta;

Aresta *aresta;
Aresta *mst;
vector<int> pai;
vector<int> peso;
int numArestas, fimMST;

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

typedef struct coord {
	double x, y;
}Coord;

Coord *coordenadas;

double CalcularDistancia(struct coord coordenadaU, struct coord coordenadaV){
	return sqrt( ((coordenadaU.x - coordenadaV.x) * (coordenadaU.x - coordenadaV.x)) + ((coordenadaU.y - coordenadaV.y) * (coordenadaU.y - coordenadaV.y)) );
}

int main(){
	int n, m;

	for (scanf("%d", &n); n != 0; scanf("%d", &n)) {
		m = n * n;	// Máximo de arestas

		pai.resize(m);
		peso.resize(m);
		numArestas = 0;

		aresta =  (Aresta *) malloc (m * sizeof(Aresta));
		mst = (Aresta *) malloc (m * sizeof(Aresta));

		coordenadas = (coord *) malloc (m * sizeof(Coord));

		peso.clear();
		pai.clear();

		for(int i = 0; i < n; i++){
			scanf("%lf %lf", &coordenadas[i].x, &coordenadas[i].y);
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i != j){
					aresta[numArestas].u = i;
					aresta[numArestas].v = j;
					aresta[numArestas].peso = CalcularDistancia(coordenadas[i], coordenadas[j]);
					
					pai[numArestas] = numArestas;
					numArestas++;
				}
			}
		}
		
		kruskal(numArestas);

		double maiorPesoTree = mst[0].peso;
		for(int i = 0; i < fimMST; i++){
			if(mst[i].peso > maiorPesoTree)
				maiorPesoTree = mst[i].peso;
		}

		printf("%.4lf\n", maiorPesoTree);
	}

	free(aresta);
	free(mst);
	free(coordenadas);

	return 0;
}