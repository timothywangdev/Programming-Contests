#include <iostream>
#include <string.h>
using namespace std;

bool m[300][300];
bool color[300],used[300],sign;

int N, a, b;
void dfs(int i,bool co){
	if (!sign){
		return;
	}
	used[i] = true;
	color[i] = co;
	for (int j = 0; j < N; j++){
		if (m[i][j]){
			if (!used[j]){
				dfs(j, 1 - co);
			}
			else if (used[j]&&color[j] == co){
				sign = false;
				return;
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
		memset(used, false, sizeof(used));
		while (cin >> a >> b){
			if (!a&&!b){
				break;
			}
			m[a - 1][b - 1] = m[b - 1][a - 1] = true;
		}
		sign = true;
		dfs(0,false);
		if (!sign){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}
	return 0;
}