#include <stdio.h>

int main(){
	int ini, fim, n, m, i, j, v, w, p;
	
	for(scanf("%d", &n), scanf("%d", &m); n != 0 && m != 0; scanf("%d", &n), scanf("%d", &m)){
		int G[n][n], visitado[n], fila[n], grau[n];

		/* Inicialização da Matriz de Adjacência */
	        for(i = 0; i < n; i++){
			visitado[i] = 0;
                        grau[i] = 0;
	                for(j = 0; j < n; j++){
	                        G[i][j] = 0;
	                }
	        }

/*
		for(i = 0; i < n; i++){
                        visitado[i] = 0;
			grau[i] = 0;
		}
*/
		for(i = 0; i < m; i++){
			scanf("%d", &v);
			scanf("%d", &w);
			scanf("%d", &p);
			for(j = 0; j < n && G[v - 1][j] != 0; j++);
			
			G[v - 1][j] = w - 1;
			grau[v - 1]++;
			if(p == 2){
				for(j = 0; j < n && G[w - 1][j] != 0; j++);
				G[w - 1][j] = v - 1;
				grau[w - 1]++;
			}
		}

		/*	BFS	*/
/*		for(i = 0; i < n; i++)
			visitado[i] = 0;
		visitado[0] = 1;	//	visitado[0] = Nó inicial
*/
		ini = fim = 0;
		fila[fim++] = 0;

		while(ini != fim){
			int no = fila[ini++];
			for(i = 0; i < grau[no]; i++){
				int viz = G[no][i];
				if(viz == 0){
					visitado[viz] = 1;
				}else if(!visitado[viz]){
					fila[fim++] = viz;
					visitado[viz] = 1;
				}
			}
			for(i = 0; i < n; i++){
				if(!visitado[i]){
					printf("0\n");
					break;
				}
			}
			if(i == n)
				printf("1\n");

	}

	
	return 0;
}
