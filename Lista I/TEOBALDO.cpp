/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <vector>
#include <stdio.h>
#include <list>

#define MAXC 101
#define MAXL 500

using namespace std;

typedef struct vertice{
	int id, paridade;
}Vertice;

vector<Vertice> grafo[MAXC * 2];
int visitados[MAXC][2];
int distancias[MAXC][2];

void BFS(Vertice s, int e, int d){

	list<Vertice> fila;
	fila.push_back(s);
	distancias[s.id][0] = 0;

	while(!fila.empty()){
		Vertice u = fila.front();	// Visitando u
		visitados[u.id][u.paridade] = 1;

		for(int i = 0; i < (int) grafo[u.id].size(); i++){
			Vertice v = grafo[u.id][i];
			v.paridade = !u.paridade;
			if(!visitados[v.id][v.paridade]){
				fila.push_back(v);
				visitados[v.id][v.paridade] = 1;
				if(distancias[v.id][v.paridade] > distancias[u.id][u.paridade] + 1)
					distancias[v.id][v.paridade] = distancias[u.id][u.paridade] + 1;
			}
		}

		fila.pop_front();
	}
}

int main(){
	int c, l, a, b, s, e, d;
	
	for(scanf("%d %d", &c, &l); c != 0; scanf("%d %d", &c, &l)) {

		/* Inicialização do Grafo e leitura dos nomes dos */
	    for(int i = 0; i < c; i++){
			grafo[i].clear();
			
			visitados[i][0] = 0;
			visitados[i][1] = 0;
			
			distancias[i][0] = MAXL * 200 * 100;		// MAXL é o número máximo de arestas no grafo
			distancias[i][1] = MAXL * 200 * 100;		// MAXL é o número máximo de arestas no grafo
		}

		/* Leitura das relações e preencimento do grafo */
		for (int i = 0; i < l; i++){
			Vertice u;
			scanf("%d %d", &a, &b);
			
			u.id = b - 1;
			u.paridade = 0;
			grafo[a - 1].push_back(u);

			u.id = a - 1;
			u.paridade = 0;
			grafo[b - 1].push_back(u);
		}

		scanf("%d %d %d", &s, &e, &d);

		Vertice u;
		u.id = s - 1;
		u.paridade = 0;

		BFS(u, e - 1, d);

		if(visitados[e - 1][d % 2] && distancias[e - 1][d % 2] <= d)		// Paridade d % 2
			printf("Yes, Teobaldo can travel.\n");
		else
			printf("No, Teobaldo can not travel.\n");
	}
	return 0;
}