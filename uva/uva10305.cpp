#include <iostream>
#include <string.h>
using namespace std;

bool m[100][100];
int inDegree[100];

int N, M,a,b;
int rv[100],c;
int main(){
	while (cin >> N >> M){
		if (!N&&!M){
			break;
		}
		memset(inDegree, 0, sizeof(inDegree));
		memset(m, false, sizeof(m));
		for (int i = 0; i < M; i++){
			cin >> a >> b;
			a--;
			b--;
			m[a][b] = true;
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (m[j][i]){
					inDegree[i]++;
				}
			}
		}
		int target;
		c = 0;
		while (c<N){
			target = -1;
			for (int i = 0; i < N; i++){
				if (inDegree[i] == 0){
					target = i;
					break;
				}
			}
			if (target == -1){
				break;
			}
			inDegree[target] = -1;
			rv[c] = target + 1;
			c++;
			for (int i = 0; i < N; i++){
				if (m[target][i]){
					inDegree[i]--;
				}
			}
		}
		for (int i = 0; i < N; i++){
			if (i != 0){
				cout << " ";
			}
			cout << rv[i];
		}
		cout << endl;
	}
	return 0;
}
