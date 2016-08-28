/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Grafo{
	//int indice;
	char nome[30];
	int *adj;
	int visitado;
} Grafo;

int BFS(int n, /*Grafo G[n]*/Grafo *G, int fila[n], int vertice){
	int i, cont = 1;

/*	for(i = 0; i < n; i++)
		visitado[i] = 0;
	visitado[0] = 1;*/
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
/*
	for(i = 0; i < n; i++){
		if(!visitado[i]){
			return 0;
		}
	}
	*/
	return cont;
}

int main(){
	int i, j, k, c, r;
	//Grafo G;
	
	for(scanf("%d %d", &c, &r); c != 0 && r != 0; scanf("%d %d", &c, &r)) {
		int fila[c];
		Grafo G[c];

		/* Inicialização do Grafo */
	    for(i = 0; i < c; i++){
			G[i].visitado = 0;
			G[i].adj = (int *)calloc(c, sizeof(int));
		}
		//printf("G[i].adj[c] = %d\n", G[i].adj[c]);

		for(i = 0; i < c; i++){
			scanf(" %[^\n]s", G[i].nome);
			//G[i].indice = i;		//	Talvez seja desnecessario
		}

		for (i = 0; i < r; i++){
			char c1[30], c2[30];
			scanf(" %s %s", c1, c2);

			for(j = 0; strcmp(G[j].nome, c1) != 0; j++);
			for(k = 0; strcmp(G[k].nome, c2) != 0; k++);
// printf("Aqui1\n");
// printf("j = %d\n", j);
// printf("k = %d\n", k);

// printf("G[j].adj[k] = %d\n", G[j].adj[k]);
// printf("G[k].adj[j] = %d\n", G[k].adj[j]);
			G[j].adj[k] = 1;
			G[k].adj[j] = 1;
// printf("Aqui2\n");
		}
/*		char linhaBranco[30];
		scanf(" %[^\n]s", linhaBranco);
*/
		/*	BFS	*/
		int max = 0;
		for(i = 0; i < c; i++){
			if(G[i].visitado == 0){
				int temp = BFS(c, G, fila, i);
				if(temp > max)
					max = temp;
			}
		}
		printf("%d\n", max);
	}
	
	return 0;
}