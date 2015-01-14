#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

vector<vector<int> > edge;
vector<int> maxN, minN;
bool visited[5000];
int N,n,t;
int getHeight(int u){
	visited[u] = true;
	int height = 0;
	for (int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i];
		if (!visited[v]){
			height = max(height, getHeight(v));
		}
	}
	return height + 1;
}
int main(){
	while (cin >> N){
		
		edge = vector<vector<int> >(N, vector<int>());
		for (int i = 0; i < N; i++){
			cin >> n;
			for (int j = 0; j < n; j++){
				cin >> t;
				t--;
				edge[i].push_back(t);
			}
		}
		int maximum = -2147483647;
		int minimum = 2147483647;
		for (int i = 0; i < N; i++){
			memset(visited, false, sizeof(bool) *N);
			int h = getHeight(i);
			if (h>maximum){
				maximum = h;
				maxN.clear();
				maxN.push_back(i + 1);
			}
			else if (h == maximum){
				maxN.push_back(i + 1);
			}
			if (h<minimum){
				minimum = h;
				minN.clear();
				minN.push_back(i + 1);
			}
			else if (h == minimum){
				minN.push_back(i + 1);
			}
		}
		cout << "Best Roots  :";
		for (int i = 0; i < minN.size(); i++){
			cout << " " << minN[i];
		}
		cout << endl;
		cout << "Worst Roots :";	
		for (int i = 0; i < maxN.size(); i++){
			cout << " " << maxN[i];
		}
		cout << endl;
	}
	return 0;
}