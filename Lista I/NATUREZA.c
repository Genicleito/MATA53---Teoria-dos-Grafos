/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Grafo{
	char nome[30];
	int *adj;
	int visitado;
} Grafo;

int BFS(int n, Grafo *G, int vertice){
	int i, cont = 1;
	int fila[n];

	G[vertice].visitado = 1;

	int ini = 0, fim = 0;
	fila[fim++] = vertice;

	while(ini != fim){
		int no = fila[ini++];
		
		for(i = 0; i < n; i++){
			if(G[no].adj[i] == 1){
				if(!G[i].visitado){
					cont++;
					fila[fim++] = i;
					G[i].visitado = 1;
				}
			}
		}
	}
	return cont;
}

int main(){
	int i, j, k, c, r;
	
	for(scanf("%d %d", &c, &r); c != 0 || r != 0; scanf("%d %d", &c, &r)) {
		//int fila[c];
		Grafo G[c];

		/* Inicialização do Grafo e leitura dos nomes dos */
	    for(i = 0; i < c; i++){
			G[i].visitado = 0;
			G[i].adj = (int *)calloc(c, sizeof(int));
			scanf(" %[^\n]s", G[i].nome);
		}

		/* Leitura das relações e preencimento do grafo */
		for (i = 0; i < r; i++){
			char c1[30], c2[30];
			scanf(" %s %s", c1, c2);

			for(j = 0; strcmp(G[j].nome, c1) != 0; j++);
			for(k = 0; strcmp(G[k].nome, c2) != 0; k++);

			G[j].adj[k] = 1;
			G[k].adj[j] = 1;
		}

		/* Realizar a busca em todos os vertices (que não foram visitados) e retornar
		 * o número de vertices de cada componente conexa. */
		int max = 0;
		for(i = 0; i < c; i++){
			if(G[i].visitado == 0){
				int temp = BFS(c, G, i);	//	temp recebe a quantidade de vértices de uma certa componente conexa
				if(temp > max)
					max = temp;		// Se esse número de vertices for o maior, então essa é a maior componente conexa desse grafo
			}
		}
		printf("%d\n", max);
	}
	
	return 0;
}