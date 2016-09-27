/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define MAXN 110
#define MAXM 210
#define INFINITO 999999999

using namespace std;

typedef struct aresta{
    int u, v, peso;
} Aresta;

Aresta aresta[MAXM];
Aresta mst[MAXM];
Aresta segundaMST[MAXM];
vector<int> pai, peso;
int fimMST, fimSegMST;
vector<int> used;

bool comparar (Aresta arestaX, Aresta arestaY) {
    return (arestaX.peso < arestaY.peso);
}

int find(int x){
    if(pai[x] == x)
        return x;
    return pai[x] = find(pai[x]);
}

void unir(int u, int v){

    u = find(u);
    v = find(v);

    if(peso[u] < peso[v])
        pai[u] = v;
    else if(peso[v] < peso[u])
        pai[v] = u;
    else{
        pai[u] = v;
        peso[v]++;  // Percorro mais uma aresta até v, então incremento o peso de v
    }
}

void kruskal(int m){
    sort(aresta, aresta + m, comparar);
    fimMST = 0;
    for (int i = 0; i < m; i++){
        if(find(aresta[i].u) != find(aresta[i].v)){     // Se não estiverem na mesma componente
            unir(aresta[i].u, aresta[i].v);
            used[fimMST] = i;
            mst[fimMST++] = aresta[i];
        }
    }
}

void kruskalSegundaMST(int m, int arestaMST){
    fimSegMST = 0;
    for (int i = 0; i < m; i++){
        if(i != used[arestaMST]){
            if(find(aresta[i].u) != find(aresta[i].v)){     // Se não estiverem na mesma componente
                unir(aresta[i].u, aresta[i].v);
                segundaMST[fimSegMST++] = aresta[i];
            }
        }
    }
}

void inicializar(int v){
    pai.resize(v);
    peso.resize(v);
    peso.clear();

    fimMST = 0;
    fimSegMST = 0;

    for(int i = 0; i < v; i++){
        pai[i] = i;
    }
}

int main(){
    int t, n, m, u, v, c;

    scanf("%d", &t);
    for(int g = 0; g < t; g++){
        scanf("%d %d", &n, &m);

        inicializar(n);

        used.resize(n);
        used.clear();

        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &c);
            aresta[i].u = u - 1;
            aresta[i].v = v - 1;
            aresta[i].peso = c;
        }

        kruskal(m);

        printf("Case #%d : ", g + 1);
        if(fimMST < n - 1)      // Desconexo
            printf("No way\n");
        else{
            int custoMST = INFINITO;
            int tam = fimMST;

            for(int i = 0; i < tam; i++){
                inicializar(n);
                kruskalSegundaMST(m, i);

                if(fimSegMST >= n - 1){     // Se for conexo...
                    int aux = 0;
                    for(int j = 0; j < fimSegMST; j++){
                        aux += segundaMST[j].peso;
                    }

                    if(custoMST > aux)
                        custoMST = aux;
                }
            }
            if(custoMST == INFINITO)
                printf("No second way\n");
            else
                printf("%d\n", custoMST);
        }
    }

    return 0;
}