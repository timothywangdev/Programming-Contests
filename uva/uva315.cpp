#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
using namespace std;

bool m[100][100],arti[100];

int N, a, b;
string s;
int sum, counter, root, rootCount;
int low[100], num[100];
bool stop;
void addEdges(string s){
	istringstream iss(s);
	iss >> a;
	if (a == 0){
		stop = true;
		return;
	}
	a--;
	while (iss >> b){
		b--;
		m[a][b] = m[b][a] = true;
	}
}
void findArticulationPoints(int index){
	low[index] = num[index] = counter++;
	for (int i = 0; i < N; i++){
		if (m[index][i]){
			if (num[i] == -1){
				if (index == root){
					rootCount++;
				}
				findArticulationPoints(i);
				if (low[i] >= num[index]){
					arti[index] = true;
				}
				low[index] = min(low[index], low[i]);
			}
			else{
				low[index] = min(low[index], num[i]);
			}
		}
	}
}
int main(){
	while (cin >> N){
		if (!N){
			break;
		}
		memset(m, false, sizeof(m));
		memset(num, -1, sizeof(num));
		memset(arti, false, sizeof(arti));
		counter = 0;
		rootCount = 0;
		root = 0;
		getline(cin, s);
		stop = false;
		while (!stop&&getline(cin, s)){
			addEdges(s);
		}
		sum = 0;
		for (int i = 0; i<N; i++){
			if (num[i] == -1){
				root = i;
				rootCount = 0;
				findArticulationPoints(i);
				arti[root] = (rootCount > 1);
			}
		}
		for (int i = 0; i<N; i++){
			sum += arti[i];
		}
		cout << sum << endl;
	}
	return 0;
}