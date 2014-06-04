#include <iostream>
#include <map>
#include <string.h>
#include <string>
using namespace std;

map<string, int> toID;
map<int, string> toName;
bool m[100][100];
int inDegree[100];

int N, M;
int rv[100], c;
string a, b;
string s;
int counter = 0;
int main(){
	while (cin >> N){
		counter++;
		toID.clear();
		toName.clear();
		memset(inDegree, 0, sizeof(inDegree));
		memset(m, false, sizeof(m));
		for (int i = 0; i < N; i++){
			cin >> s;
			toID[s] = i;
			toName[i] = s;
		}
		cin >> M;
		for (int i = 0; i < M; i++){
			cin >> a >> b;
			m[toID[a]][toID[b]] = true;
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
			rv[c] = target;
			c++;
			for (int i = 0; i < N; i++){
				if (m[target][i]){
					inDegree[i]--;
				}
			}
		}
		cout << "Case #" << counter << ": Dilbert should drink beverages in this order: ";
		for (int i = 0; i < N; i++){
			if (i != 0){
				cout << " ";
			}
			cout << toName[rv[i]];
		}
		cout << "."<<endl<<endl;
	}
	return 0;
}
