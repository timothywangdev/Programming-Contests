#include <iostream>
#include <algorithm>
using namespace std;

int N, M, d[20000], k[20000];
int main(){
	while (cin >> N >> M){
		if (!N&&!M){
			break;
		}
		for (int i = 0; i < N; i++){
			cin >> d[i];
		}
		for (int i = 0; i < M; i++){
			cin >> k[i];
		}
		sort(d, d + N);
		sort(k, k + M);
		int current = 0;
		int sum = 0;
		for (int i = 0; i < M&&current<N; i++){
			if (k[i] >= d[current]){
				sum += k[i];
				current++;
			}
		}
		if (current != N){
			cout << "Loowater is doomed!" << endl;
		}
		else{
			cout << sum << endl;
		}
	}

	return 0;
}