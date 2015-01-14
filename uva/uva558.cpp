#include <iostream>
#include <vector>
#include <string.h>
#define INF 842150450
using namespace std;
class ii{
public:
	int a;
	int b;
	ii(int a, int b) :a(a), b(b){}
};
vector<ii> edges[1000];
int dist[1000];
int N, M, T,a,b,w;
bool negative;
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N >> M;
		memset(dist, 50, sizeof(dist));
		for (int i = 0; i < N; i++){
			edges[i].clear();
		}
		for (int i = 0; i < M; i++){
			cin >> a >> b >> w;
			edges[a].push_back(ii(b, w));
		}
		dist[0] = 0;
		negative = false;
		for (int i = 0; i < N; i++){
			//cout << "Circle: " << i << endl;
			for (int j = 0; j < N; j++){
				for (int k = 0; k < edges[j].size(); k++){
					ii v = edges[j][k];
					if (dist[v.a]>dist[j] + v.b){
						if (i == N - 1){
							negative = true;
						}
						dist[v.a] = dist[j] + v.b;
						//cout << "Relex " << j << " " << v.a << endl;
					}
				}
			}
		}
		//cout << "Dist: " << dist[10] << endl;
		if (negative){
			cout << "possible" << endl;
		}
		else{ 
			cout << "not possible" << endl;
		}
	}
	return 0;
}