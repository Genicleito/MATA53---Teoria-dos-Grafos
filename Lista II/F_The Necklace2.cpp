#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

#define MAXN 1050

using namespace std;

int aresta[MAXN][MAXN];
vector<int> resposta;
int inicio, terminouCiclo, cont;

int N;

void inicializar(){
	resposta.clear();
	for(int j = 0; j < N; j++){
		for(int k = 0; k < N; k++)
			aresta[j][k] = 0;
	}
}

void encontrarCircuito(int u){
	for(int j = 0; j < N; j++){
		if(aresta[u][j]){
			//printf("inicio = %d\n", inicio);
/*			if(terminouCiclo){
				inicio = j;
				printf("inicio agora eh: %d\n", inicio + 1);
				terminouCiclo = 0;
				//cont++;
			}
			if(inicio == j && cont != 0){
				terminouCiclo = 1;
			}*/
			aresta[u][j] -= 1;
			aresta[j][u] -= 1;
			cont++;
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
		}

		int deuRuim = 0;
		printf("Case #%d\n", g + 1);
		for(int i = 0; i < 60; i++){
			if(grau[i] % 2){
				printf("some beads may be lost\n\n");
				deuRuim = 1;
				break;
			}
		}

		if(!deuRuim){
			inicio = u - 1;
			terminouCiclo = 0;
			cont = 0;
			encontrarCircuito(inicio);

			if((int) resposta.size() != n + 1){
				printf("some beads may be lost\n\n");
			}else{
				for(int i = 0; i < n; i++){
					printf("%d %d\n", resposta[i], resposta[i + 1]);
				}
			}
			printf("\n");
		}
		free(grau);
	}

	return 0;
}