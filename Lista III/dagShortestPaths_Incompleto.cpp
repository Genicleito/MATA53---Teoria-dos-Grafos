//#include <cstdio>
#include <stdio.h>
#include <vector>
using namespace std;

#define MAXN 1000
#define MAXM 2000
#define INF 4000001		//MAXM * |MAXT| + 1

int n; // número de vértices
int m; // número de arestas
vector<int> grafo[MAXN];

int grau[MAXN];
int pai[MAXN], int distancia[MAXN];
vector<int> listaGrauZero;

void initializeSingleSource(){
	grau.clear();
	listaGrauZero.clear();
	for(int i = 0; i < n; i++){
		grafo[i].clear();
		grafo[i].resize(n);
		pai[i] = -1;
		distancia[i] = INF;
	}
}

void ordenacaoTopologica(){
	for(int i = 0; i < n; i++) {
			if(grau[i] == 0){
				listaGrauZero.push_back(i);
			}
	}
    
	for(int cont = 0; cont < (int) listaGrauZero.size(); cont++){
        
		int no = listaGrauZero[cont];
       
		for(int i = 0; i < (int) grafo[no].size(); i++){
			int v = grafo[no][i];
			grau[v]--;
			
			if(grau[v] == 0)
				listaGrauZero.push_back(v);
		}
	}
}
/*
void initializeSingleSource(){
	for(int )
}
*/
int main(){

    for(int c, scanf("%d", &c); c > 0; c--) {
	    scanf("%d %d", &n, &m);

	    inicializa();
	    for(int i = 0; i < m; i++){
	        
	        int x, y, t;
	        scanf("%d %d", &x, &y, &t);
	        
	        grau[y]++;
	        grafo[x][y] = t;
		}

		ordenacaoTopologica();

		initializeSingleSource();
	    
		if((int) listaGrauZero.size() < n)
			printf("not possible\n");
	}

	return 0;
}