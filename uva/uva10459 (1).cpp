#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<vector<int> > edge;
int N, n, t, maximum,minimum;
bool visited[5000];
int height[5000];
int f[10000];
int e[5000][5000];
int ee;
void addEdge(int from, int to){
	e[from][to] = ee;
	ee++;
}
int search(int u,int parent){
	int k;
	int current = 0;
	visited[u] = true;
	if (u!=parent&&f[e[u][parent]] != -1){
		visited[u] = false;
		return f[e[u][parent]];
	}
	for (int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i];
		if (!visited[v]){
			current=max(current,search(v, u));
		}
	}
	if (u != parent){
		f[e[u][parent]] = current + 1;
	}
	visited[u] = false;
	return current+1;
}
int main(){
	while (scanf("%d", &N)==1){
		ee = 0;
		edge = vector<vector<int> >(N, vector<int>());
		memset(visited, false, sizeof(visited));
		memset(f, -1, sizeof(f));
		maximum = -1;
		minimum = 2147483647;
		for (int i = 0; i < N; i++){
			scanf("%d", &n);
			for (int j = 0; j < n; j++){
				scanf("%d",&t);
				t--;
				edge[i].push_back(t);
				addEdge(i, t);
			}
		}
		for (int i = 0; i < N; i++){
			height[i]=search(i, i);
			maximum = max(maximum, height[i]);
			minimum = min(minimum, height[i]);
		}
		printf("Best Roots  :");
		for (int i = 0; i < N; i++){
			if (height[i] == minimum){
				printf(" %d", i + 1);
			}
		}
		printf("\nWorst Roots :");
		for (int i = 0; i < N; i++){
			if (height[i] == maximum){
				printf(" %d", i + 1);
			}
		}
		printf("\n");
	}
	return 0;
}