#include <stdio.h>

int main(){
	int ini, fim, n, m, i, j, v, w, p;
	
	for(scanf("%d", &n), scanf("%d", &m); n != 0 && m != 0; scanf("%d", &n), scanf("%d", &m)){
		int G[n][n], visitado[n], fila[n];

		/* Inicialização da Matriz de Adjacência */
	        for(i = 0; i < n; i++){
	                for(j = 0; j < n; j++){
	                        G[i][j] = 0;
	                }
	        }

		for(i = 0; i < m; i++){
			scanf("%d", &v);
			scanf("%d", &w);
			scanf("%d", &p);
			G[v - 1][w - 1] = 1;
			if(p == 2)
				G[w - 1][v - 1] = 1;
		}

		/*	BFS	*/
		for(i = 0; i < n; i++)
			visitado[i] = 0;
		visitado[v - 1] = 1;	//	v - 1 = Nó inicial (Vértice da última aresta inserida)

		ini = fim = 0;
		fila[fim++] = v - 1;

		while(ini != fim){
			int no = fila[ini++], grau = 0;
			
			for(i = 0; i < n; i++){
				if(G[no][i] == 1){
					grau++;
					if(!visitado[i]){
						fila[fim++] = i;
						visitado[i] = 1;
					}
				}
			}
			if (grau == 0){
				visitado[no] = 0;
				ini = -1;
				break;
			}
		}
	
		//printf("Teste %d\n", k);
		//if(ini != fim)
		if(ini == -1)
			printf("0\n");
//		else
//			printf("1\n");
		else{
			for(i = 0; i < n; i++){
				if(!visitado[i]){
					printf("0\n");
					break;
				}
			}
			if(i == n)
				printf("1\n");
		}

	}
	
	return 0;
}
