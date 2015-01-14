#include <iostream>

using namespace std;

char m[100][100];
int N, M,S;
int r, c, d,sum;
char ch;
int mo[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
void moveForward(int &r, int &c, int d){
	r = r + mo[d][0];
	c = c + mo[d][1];
}
bool check(int r, int c){
	if (!(0 <= r&&r < N && 0 <= c&&c < M)){
		return false;
	}
	if (m[r][c] == '#'){
		return false;
	}
	return true;
}
int main(){
	while (cin >> N >> M >> S){
		if (!N&&!M&&!S){
			break;
		}
		sum = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				cin >> m[i][j];
				if (m[i][j] == 'N'){
					d = 0;
					r = i;
					c = j;
				}
				if (m[i][j] == 'L'){
					d = 1;
					r = i;
					c = j;
				}
				if (m[i][j] == 'S'){
					d = 2;
					r = i;
					c = j;
				}
				if (m[i][j] == 'O'){
					d = 3;
					r = i;
					c = j;
				}
			}
		}
		for (int i = 0; i < S; i++){
			cin >> ch;
			if (ch == 'D'){
				d = (d + 1) % 4;
			}
			else if (ch == 'E'){
				d--;
				if (d==-1){
					d = 3;
				}
			}
			else{
				int a = r;
				int b = c;
				moveForward(a,b,d);
				if (check(a,b)){
					r = a;
					c = b;
				}
				if (m[r][c] == '*'){
					sum++;
					m[r][c] = '.';
				}
			}
		}
		cout << sum << endl;

	}
	return 0;
}