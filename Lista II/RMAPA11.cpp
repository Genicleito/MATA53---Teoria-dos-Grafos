/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <bits/stdc++.h>

#define MAXN 501
#define MAXM 124751

//vector< vector<int> > grafo;
int **grafo;
int pai[MAXN], chave[MAXN];
vector<int> filaPrioridade;	// Talvez não precise, basta pegar o indice nesse primeiro for abaixo

int main(){
	int n, m, u, v, c;
	
	scanf("%d %d", &n, &m);
	
	//grafo.resize(n);
	grafo = (int **) calloc (n, sizeof(int *));	// Aloca as linhas

	for(int i = 0; i < n; i++){
		chave[i] = MAXN + 1;
		pai[i] = -1;
		
		grafo[i] = (int *) calloc (n, sizeof(int));	// Aloca as colunas
		filaPrioridade.push_back(i);
	}
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &u, &v, &c);
		grafo[u - 1][v - 1] = c;
	}
	chave[0] = 0;
/*	for(int i = 0; i < n; i++){		// Até n ou cria uma arvore ?
		//ree.insert(i);
		filaPrioridade.push_back(i);
	}*/
	int ini = 0;
	while(!fila.empty()){
		//u = filaPrioridade.front();
		u = filaPrioridade[ini];
		filaPrioridade[ini] = -1;	// pop_front()
		ini++;
		//filaPrioridade.pop_front();
		for(int i = 0; i < n; i++){
			int pesoUI = grafo[u][i];
			if(pesoUI){
				if((filaPrioridade[i] != -1) && pesoUI < chave[i]){
					chave[i] = pesoUI;
					pai[i] = u;
				}
			}
		}
	}


	return 0;
}