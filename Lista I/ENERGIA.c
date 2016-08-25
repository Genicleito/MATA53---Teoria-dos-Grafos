#include <stdio.h>
#define MAXN 100
#define MAXM 4900

//int fila[MAXN];
//int visitado[MAXN];
//int G[MAXN][MAXM];
//int grau[MAXN];

int main(){
	int ini, fim, n, m, i, j, k = 1, u, v;

	/* Inicialização da Matriz de Adjacência */
//	for(i = 0; i < MAXN; i++){
//		for(j = 0; j < MAXM; j++){
//			G[i][j] = 0;
//		}
//	}

	//scanf("%d", &n);
	//scanf("%d", &m);
	
	for(scanf("%d", &n), scanf("%d", &m); n != 0 && m != 0; scanf("%d", &n), scanf("%d", &m), k++){
	//while(n || m){
		int G[n][m], visitado[n], fila[n];

		/* Inicialização da Matriz de Adjacência */
	        for(i = 0; i < n; i++){
	                for(j = 0; j < n; j++){
	                        G[i][j] = 0;
	                }
	        }


		for(i = 0; i < m; i++){
			scanf("%d", &u);
			scanf("%d", &v);
			G[u - 1][v - 1] = 1;
		}

		/*	BFS	*/
		for(i = 0; i < n; i++)
			visitado[i] = 0;
		visitado[u - 1] = 1;	//	u - 1 = Nó inicial (Vértice da última aresta inserida)

		ini = fim = 0;
		fila[fim++] = u - 1;

		while(ini != fim){
			int no = fila[ini++];

			//Processa_No()
			
			for(i = 0; i < n; i++){
				if(G[no][i] == 1){
					if(!visitado[i]){
						fila[fim++] = i;
						visitado[i] = 1;
					}
				}
			}
		}
	
		printf("Teste %d\n", k);
		for(i = 0; i < n; i++){
			//printf("%d ", visitado[i]);
			if(!visitado[i]){
				printf("falha\n\n");
				break;
			}
		}
		if(i == n)
			printf("normal\n\n");
	}
	
	return 0;
}
