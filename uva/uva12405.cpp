#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int T, N;
bool used[100];
string f;

int getCover(int s, int e){
	int sum = 0;
	for (int i = s; i <= e; i++){
		sum += (f[i] == '.');
	}
	return sum;
}
void cover(int s, int e){
	for (int i = s; i <= e; i++){
		f[i] = '#';
	}
}

int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N;
		cin >> f;
		memset(used, false, sizeof(used));
		int count = 0;
		for (int i = 0; i < N; i++){
			count += (f[i] == '.');
		}
		int sum = 0,index,maximum;
		for (int i = 0; i < N; i++){
			if (f[i] == '.'){
				cover(i, min(N - 1, i + 2));
				sum++;
			}
		}
		cout << "Case " << t + 1 << ": "<< sum << endl;
	}
	return 0;
}