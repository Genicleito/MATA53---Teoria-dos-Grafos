#include <stdio.h>
#include <string.h>         /* memset() */
#include <stdlib.h>
#define MAXN 1010

/* matriz de adjacencias */
int A[MAXN][MAXN], visitado[MAXN], dis[MAXN], rota[MAXN];
int N, M, C, K, u, x, custo, menor = 10000;
 
int dijkstra(int V, int n) {
  int i;

  memset(dis, 0x3f, sizeof(dis)); /* distancia inicial infinita */
  memset(visitado, 0, sizeof(visitado));
  dis[V] = 0;

  for (;;) {
    int no = -1;
    for (i = 0; i < n; i++)
      if (!visitado[i] && (no == -1 || dis[i] < dis[no]) && i>=C)
    no = i;
    if (no == -1) break;
    visitado[no] = 1;
    for (i = 0; i < n; i++)
      if (dis[no] + A[no][i] < dis[i])
    dis[i] = dis[no] + A[no][i];
  }   
}

int distanciaRota(int k)
{
    int soma = 0;
    for(int i=k;i<(C-1);i++)
    {
        soma = soma + A[i][i+1];
    }
    return soma;
}

int main() {
  for(;;)
  {
  scanf("%d %d %d %d", &N, &M, &C, &K);
  if(N==0 && M==0 && C==0 && K==0)return 0;
  memset(A, 0x3f, sizeof(A));
  memset(rota, 0, sizeof(rota));
  for(int i=0;i<M;i++)
  {
      scanf("%d %d %d", &u, &x, &custo);
      A[u][x]=A[x][u]=custo;
  }
  dijkstra(K, N);
 
  for(int i=0;i<(C-1);i++)
  {
  rota[i]=distanciaRota(i);
  }
 
  for(int i=0;i<C;i++)
  {
  rota[i]=rota[i]+dis[i];
  if(rota[i]<menor)menor=rota[i];
  }
  
  printf("%d\n", menor);
  menor = 10000;
  }
  system("PAUSE");
  return 0;
}