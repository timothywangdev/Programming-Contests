#include <iostream>
#include <algorithm>
using namespace std;

int T, N, h[10000], w[10000],de[10000],inc[10000],mde,minc;
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N;
		mde = minc = -1;
		for (int i = 0; i < N; i++){
			cin >> h[i];
		}
		for (int i = 0; i < N; i++){
			cin >> w[i];
		}
		for (int i = 0; i < N; i++){
			de[i] = inc[i] = w[i];
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < i; j++){
				if (h[j] < h[i]){
					inc[i] = max(inc[i], inc[j] + w[i]);
				}
				if (h[j] > h[i]){
					de[i] = max(de[i], de[j] + w[i]);
				}
			}
			mde = max(mde, de[i]);
			minc = max(minc, inc[i]);
		}
		cout << "Case " << t + 1 << ". ";
		if (minc >= mde){
			cout << "Increasing (" << minc << "). Decreasing (" << mde << ")." << endl;
		}
		else{
			cout << "Decreasing (" << mde << "). Increasing (" << minc << ")." << endl;
		}
	}
	return 0;
}