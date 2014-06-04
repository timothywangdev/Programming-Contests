#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int mo[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
string m[100];
bool used[100][100];
int N,T,sum;
bool inRange(int r, int c){
	return 0 <= r &&r< N && 0 <= c&&c < N;
}
bool search(int r, int c){
	used[r][c] = true;
	bool sign = (m[r][c] == 'x');
	for (int i = 0; i < 4; i++){
		int rr = r + mo[i][0];
		int cc = c + mo[i][1];
		if (inRange(rr, cc) && (m[rr][cc] == 'x' || m[rr][cc] == '@') && !used[rr][cc]){
			sign = search(rr, cc) || sign;
		}
	}
	return sign;
}
int main(){
	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> N;
		for (int r = 0; r < N; r++){
			cin >> m[r];
		}
		memset(used, false, sizeof(used));
		sum = 0;
		for (int r = 0; r < N; r++){
			for (int c = 0; c < N; c++){
				if ((m[r][c] == 'x' || m[r][c] == '@')&&!used[r][c]){
					if (search(r, c)){
						sum++;
					}
				}
			}
		}
		cout << "Case " << i + 1 << ": " << sum << endl;
	}
	return 0;
}