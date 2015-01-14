#include <iostream>

using namespace std;

int T, N, v[100000];

bool check(int k){
	int last = 0;
	for (int i = 0; i < N; i++){
		if (v[i] - last == k)
			k--;
		else if (v[i] - last>k)
			return false;
		last = v[i];
	}
	return true;
}
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> v[i];
		cout << "Case " << t + 1 << ": ";
		int lower = 1, upper = 200000,mid;
		while (lower < upper){
			mid = (lower + upper) / 2;
			if (check(mid)){
				upper = mid;
			}
			else{
				lower = mid+1;
			}
		}
		cout << lower << endl;
	}
	return 0;
}