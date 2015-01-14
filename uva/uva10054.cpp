#include <iostream>
#include <vector>
#include <list>
#include <string.h>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
int N, T, a, b;
bool m[50][50],exist[50];
vector<ii> edge[50];
int degree[50];
list<int> cyc;
void EulerTour(list<int>::iterator it, int u){
	for (int i = 0; i < edge[u].size();i++){
		ii *v = &edge[u][i];
		if (v->second==1){
			v->second = 0;
			for (int j = 0; j < edge[v->first].size(); j++){
				ii *uu = &edge[v->first][j];
				if (uu->first == u&&uu->second == 1){
					uu->second = 0;
					break;
				}
			}
			EulerTour(cyc.insert(it, u+1), v->first);
		}
	}
}
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N;
		memset(m, false, sizeof(m));
		memset(exist, false, sizeof(exist));
		memset(degree, 0, sizeof(degree));
		for (int i = 0; i < 50; i++){
			edge[i].clear();
		}
		for (int i = 0; i < N; i++){
			cin >> a >> b;
			a--;
			b--;
			exist[a] = exist[b] = true;
			edge[a].push_back(make_pair(b, 1));
			edge[b].push_back(make_pair(a, 1));
			degree[a]++;
			degree[b]++;
		}
		bool tour = true;
		for (int i = 0; i < 50; i++){
			if (exist[i]){
				if (degree[i] % 2 == 1){
					tour = false;
					break;
				}
			}
		}
		if (t>0){
			cout << endl;
		}
		cout << "Case #" << t + 1 << endl;
		if (tour){
			cyc.clear();
			for (int i = 0; i < 50; i++){
				if (exist[i]){
					EulerTour(cyc.begin(), i);
					break;
				}
			}
			vector<int> rv;
			for (list<int>::iterator it = cyc.begin(); it != cyc.end(); it++){
				rv.push_back(*it);
			}
			int pre = -1;
			for (int i = 0; i < rv.size();){
				if (pre == -1){
					cout << rv[i] << " " << rv[i + 1] << endl;
					pre = rv[i + 1];
					i += 2;
				}
				else{
					cout << pre << " " << rv[i] << endl;
					pre = rv[i];
					i++;
				}
			}
			cout << rv[rv.size() - 1] << " " << rv[0] << endl;
		}
		else{
			cout << "some beads may be lost" << endl;
		}
	}
	return 0;
}