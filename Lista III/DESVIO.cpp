#include <stdio.h>

#define MAXN 500
#define INF 20000000

int visitado[MAXN];
int rota[MAXN];
int distancia[MAXN];
int grafo[MAXN][MAXN];
int deuRuim = 0;
int menor;
 
void inicializa(int n){
 	deuRuim = 0;
	menor = INF;
	//visitado.clear();
	//distancia.clear();

	for(int j = 0; j < n; j++) {
		visitado[j] = 0;
		distancia[j] = INF;
		rota[j] = 0;

		for(int k = 0; k < n; k++){
			grafo[j][k] = INF;
		}
	}
}

void dijkstra(int s, int n, int c){
	distancia[s] = 0;

	for(int g = 0; g < n; g++) {
		int no = -1;
			for(int i = 0; i < n; i++){
//printf("i = %d, distancia ao no = %d, distancia a i = %d\n", i, distancia[no], distancia[i]);
				if(!visitado[i] && (no == -1 || distancia[i] < distancia[no]) && i >= c){
					no = i;
			}
    	}
//    visitado[no] = 1;
		if(distancia[no] == INF || no == -1){
			deuRuim = 1;
			break;
		}
		visitado[no] = 1;

		for(int i = 0; i < n; i++){ //  Lista de Adj
			if(distancia[i] > distancia[no] + grafo[no][i])
        		distancia[i] = distancia[no] + grafo[no][i];
    	}
	}
}

int distanciaNaRota(int k, int c){
	int soma = 0;
	for(int i = k; i < c - 1; i++){
		soma += grafo[i][i + 1];
	}
	return soma;
}

int main() {
	int n, m, c, k, u, v, p/*menor = 10000*/;

	for(scanf("%d %d %d %d", &n, &m, &c, &k); n + m + c + k != 0; scanf("%d %d %d %d", &n, &m, &c, &k)){

		inicializa(n);

    	for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &p);
			grafo[u][v] = p;
			grafo[v][u] = p;
    	}
    	dijkstra(k, n, c);
	   
	    for(int i = 0; i < c - 1; i++) {
			rota[i] = distanciaNaRota(i, c);
    	}
	   
	    for(int i = 0; i < c; i++){
			//rota[i] = rota[i] + distancia[i];
			rota[i] += distancia[i];
	      
			if(rota[i] < menor)
				menor = rota[i];
		}
	//	printf("%d-----\n", visitado[0]);
		printf("%d\n", menor);
		//menor = INF;
	}

	return 0;
}