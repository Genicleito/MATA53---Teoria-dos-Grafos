/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
#include <stdio.h>

int BFS(int n, int G[n][n], int *visitado, int *fila){
	int i;

	for(i = 0; i < n; i++)
		visitado[i] = 0;
	visitado[0] = 1;

	int ini = 0, fim = 0;
	fila[fim++] = 0;

	while(ini != fim){
		int no = fila[ini++];
		
		for(i = 0; i < n; i++){
			if(G[no][i] == 1){
				if(!visitado[i]){
					fila[fim++] = i;
					visitado[i] = 1;
				}
			}
		}
	}

	for(i = 0; i < n; i++){
		if(!visitado[i]){
			return 0;
		}
	}
	return 1;
}

int main(){
	int n, m, i, j, v, w, p;
	
	for(scanf("%d %d", &n, &m); n != 0 && m != 0; scanf("%d %d", &n, &m)) {
		int G[n][n], GR[n][n], visitado[n], fila[n];

		/* Inicialização dos Grafos */
	       for(i = 0; i < n; i++){
	               for(j = 0; j < n; j++){
	                       G[i][j] = 0;
	                       GR[i][j] = 0;
	               }
	       }

		for(i = 0; i < m; i++){
			scanf("%d", &v);
			scanf("%d", &w);
			scanf("%d", &p);
			G[v - 1][w - 1] = 1;
			GR[w - 1][v - 1] = 1;	//	Grafo reverso de G
			if(p == 2){
				G[w - 1][v - 1] = 1;
				GR[v - 1][w - 1] = 1;
			}
		}

		/*	BFS	*/
		if(BFS(n, G, visitado, fila)) {
			if(BFS(n, GR, visitado, fila)) {
				printf("1\n");
			}else{
				printf("0\n");
			}
		}else{
			printf("0\n");
		}
	}
	
	return 0;
}