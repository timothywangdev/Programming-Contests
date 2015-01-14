#include <iostream>
#include <fstream>
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("test.in");
ofstream fout("test.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(fin.rdbuf());
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(fout.rdbuf());
#endif
}
long long heap[20][20][20],s[3],maximum,sum[20][20][20][20][20];
int T;
long long getRangeMax(int x1, int x2, int y1, int y2){
	if (x1 == x2&&x2 == 1 && y1 == y2&&y2 == 1){
		//cout << "hohoho" << endl;
	}
	long long current = 0, m = -10000000000;
	for (int i = 0; i < s[2]; i++){
		current += sum[x1][x2][y1][y2][i];
		if (current>m)
			m = current;
		if (current < 0){
			current = 0;
		}
	}
	return m;
}
int main(){
	redirect();
	cin >> T;
	for (int t = 1; t <= T; t++){
		if (t>1)
			cout << endl;
		maximum = -10000000000;
		cin >> s[0] >> s[1] >> s[2];
		for (int x = 0; x < s[0]; x++){
			for (int y = 0; y < s[1]; y++){
				for (int z = 0; z < s[2]; z++){
					cin >> heap[x][y][z];
					sum[x][x][y][y][z] = heap[x][y][z];
				}
			}
		}
		int xstart, xend, ystart, yend;
		for (int xs = 1; xs <= s[0]; xs++){
			for (int ys = 1; ys <= s[1]; ys++){
				for (int x = 0; x + xs - 1 < s[0]; x++){
					for (int y = 0; y + ys - 1 < s[1]; y++){
						for (int z = 0; z < s[2]; z++){
							xstart = x;
							xend = x + xs - 1;
							ystart = y;
							yend = y + ys - 1;
							if (xstart == xend&&ystart == yend){
								continue;
							}
							else if (xstart < xend){
								sum[xstart][xend][ystart][yend][z] = sum[xstart][xend - 1][ystart][yend][z] + sum[xend][xend][ystart][yend][z];
							}
							else if (ystart < yend){
								sum[xstart][xend][ystart][yend][z] = sum[xstart][xend][ystart][yend-1][z] + sum[xstart][xend][yend][yend][z];
							}
						}
					}
				}
			}
		}

		for (int x1 = 0; x1 < s[0]; x1++){
			for (int x2 = x1 ; x2 < s[0]; x2++){
				for (int y1 = 0; y1 < s[1] ; y1++){
					for (int y2 = y1; y2 < s[1]; y2++){
						long long k = getRangeMax(x1, x2, y1, y2);
						if (k>maximum)
							maximum = k;
					}
				}
			}
		}
		cout << maximum << endl;
	}
	return 0;
}