/*
* Por: Genicleito Gonçalves
* Disciplina: MATA53 - Teoria dos Grafos (2016.1)
* Universidade Federal da Bahia (UFBA)
*/
/*#include <vector>
#include <stdio.h>
//#include <cstdio>
#include <set>*/
#include <bits/stdc++.h>

#define MAXN 31

using namespace std;

int n;	// Vértices


int main(){
	int teste = 1;

	for(cin >> n; n != 0; cin >> n, teste++){
		
		string amigo;
		map<string, int> nomes;
		vector<int> grafo[MAXN];
		vector<int> lista;	// Árvore com os vértices que tem grau de entrada igual a 0
		map<int, string> resposta;
		int grau[MAXN];

		for (int i = 0; i < n; i++){

			cin >> amigo;

			nomes[amigo] = i;
			resposta[i] = amigo;

			grau[i] = 0;
			grafo[i].clear();
			lista.clear();
		}

		for (int i = 0; i < n; i++){
			string nomeAmigo;//nome1;
			int dependentes;

			cin >> nomeAmigo >> dependentes;

			if(dependentes == 0){
				lista.push_back(nomes[nomeAmigo]);
//cout << nomeAmigo << " tem grau 0" << endl;
			}

			for(int j = 0; j < dependentes; j++){
				string nome1;

				cin >> nome1;

				grafo[nomes[nome1]].push_back(nomes[nomeAmigo]);
				grau[nomes[nomeAmigo]]++;
			}
		}

		for(int i = 0; i < (int) lista.size(); i++){
			int vAtual = lista[i];
			//resposta.push_back(vAtual);
			//tree.erase(vAtual);
//cout << vAtual << " <-- vertice pai com grau = " << grau[vAtual] << endl;
			for (int j = 0; j < (int) grafo[vAtual].size(); j++){
				int vertice = grafo[vAtual][j];

				grau[vertice]--;
				if(grau[vertice] == 0){
					lista.push_back(vertice);
//cout << vertice << " vertice filho" << " com grau " << grau[vertice] << endl;
				}
			}
		}

		cout << "Teste " << teste << endl;
		if ((int) lista.size() < n) {
			printf("impossivel\n\n");
		}else{
			for(int i = 0; i < (int) lista.size(); i++){
				cout << resposta[lista[i]] << " ";
			}
			printf("\n\n");
		}
	}
	return 0;
}