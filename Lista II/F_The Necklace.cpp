#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

#define MAXN 1050

using namespace std;

int aresta[MAXN][MAXN];
vector<int> resposta;
int inicio, terminouCiclo, cont;

int N, numCores = -1;

void inicializar(){
	resposta.clear();
	for(int j = 0; j < MAXN; j++){
		for(int k = 0; k < MAXN; k++)
			aresta[j][k] = 0;
	}
}

void encontrarCircuito(int u){
	for(int j = 0; j < N; j++){
		while(aresta[u][j]){
			aresta[u][j] -= 1;
			aresta[j][u] -= 1;
			encontrarCircuito(j);
		}
	}
	resposta.push_back(u + 1);
}

int main(){
	int t, n, u, v;

	scanf("%d", &t);
	for(int g = 0; g < t; g++){

		scanf("%d", &n);
		N = n;

		int *grau = (int *) calloc (60, sizeof(int));

		inicializar();

		for(int i = 0; i < n; i++){
			scanf("%d %d", &u, &v);
			aresta[u - 1][v - 1] += 1;
			aresta[v - 1][u - 1] += 1;
			grau[u] += 1;
			grau[v] += 1;

			numCores = max(numCores, u);
			numCores = max(numCores, v);
		}
//printf("numCores %d n %d\n", numCores, n);
		int tmp = n;
		n = max(numCores, n);
		N = n;
//printf("N = %d n = %d\n", N, n);
		int deuRuim = 0;
		if(g > 0)
            printf("\n");
		printf("Case #%d\n", g + 1);
		for(int i = 0; i < 60; i++){
			if(grau[i] % 2){
//printf("1\n");
				printf("some beads may be lost\n");
				deuRuim = 1;
				break;
			}
		}

		if(!deuRuim){
			encontrarCircuito(u - 1);

			if((int) resposta.size() != tmp + 1){
//printf("2\n");
				printf("some beads may be lost\n");
			}else{
				for(int i = 0; i < tmp; i++){
					printf("%d %d\n", resposta[i], resposta[i + 1]);
				}
			}
		}
		free(grau);
	}

	return 0;
}
