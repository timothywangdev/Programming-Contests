#include <iostream>

using namespace std;

int v[100], N,T;
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> v[i];
		}
		cout << "Case " << t + 1 << ": " << v[N / 2] << endl;
	}
}