#include <iostream>
#include <algorithm>
using namespace std;

int N, M, b[10000], s[10000];

int t = 0;
int main(){
	while (cin >> N >> M){
		t++;
		if (!N&!M){
			break;
		}
		for (int i = 0; i < N; i++){
			cin >> b[i];
		}
		for (int i = 0; i < M; i++){
			cin >> s[i];
		}
		sort(b, b + N);
		cout << "Case " << t << ": ";
		if (N <= M){
			cout << '0' << endl;
		}
		else{
			cout << N - M <<" "<< b[0] << endl;
		}
	}
	return 0;
}