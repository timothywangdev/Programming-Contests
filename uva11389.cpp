#include <iostream>
#include <algorithm>
using namespace std;

int n, d, r, m[100], e[100];
int main(){
	while (cin >> n >> d >> r){
		if (!n&&!d&&!r){
			break;
		}
		for (int i = 0; i < n; i++){
			cin >> m[i];
		}
		for (int i = 0; i < n; i++){
			cin >> e[i];
		}
		sort(m, m + n);
		sort(e, e + n);
		int sum = 0;
		for (int i = 0; i < n; i++){
			int k = m[i] + e[n - i - 1];
			if (k>d){
				sum += (k - d)*r;
			}
		}
		cout << sum << endl;
	}
	return 0;
}