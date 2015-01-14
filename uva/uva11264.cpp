#include <iostream>
#include <algorithm>
using namespace std;

long long T, N, v[2000],selected[2000];
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> v[i];
		}
		int sum = 0;
		int index = 0;
		int maximum = 0;
		for (int i = 0; i < N; i++){
			if (sum>v[i]){
				while (sum>v[i]){
					sum -= selected[index - 1];
					index--;
				}
			}
				sum += v[i];
				selected[index] = v[i];
				maximum = max(maximum, index);
				index++;
		}
		cout << maximum+1 << endl;
	}
	return 0;
}