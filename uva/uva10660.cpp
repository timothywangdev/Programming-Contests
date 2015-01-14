#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int m[5][5];
bool used[5][5];
int N,a,b,c,mr,mc,minimum;

int distance(int r,int c,int i,int j){

	return abs(i-r)+abs(j-c);
}
int T;
int office[5][2];
int minDist[5];
int currDist[5];
int totalMinimum;
void copyDist(){
	for(int i=0;i<5;i++){
		minDist[i]=currDist[i];
	}
}

int main(){
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		memset(used,false,sizeof(used));
		memset(m,0,sizeof(m));
		for(int i=0;i<N;i++){
			cin>>a>>b>>c;
			m[a][b]=c;
		}
		totalMinimum=2147483647;
            for (int a = 0; a < 25; ++a)
                for (int b = a + 1; b < 25; ++b)
                    for (int c = b + 1; c < 25; ++c)
                        for (int d = c + 1; d < 25; ++d)
                            for (int e = d + 1; e < 25; ++e) {
                                int sum = 0;
                                for (int row = 0; row < 5; ++row)
                                    for (int col = 0; col < 5; ++col) {
                                        int A = distance(row, col, a / 5, a % 5) * m[row][col];
                                        int B = distance(row, col, b / 5, b % 5) * m[row][col];
                                        int C = distance(row, col, c / 5, c % 5) * m[row][col];
                                        int D = distance(row, col, d / 5, d % 5) * m[row][col];
                                        int E = distance(row, col, e / 5, e % 5) * m[row][col];
                                        sum += min(min(A, min(B, C)), min(D, E));
                                    }
                                if (sum < totalMinimum) {
                                    totalMinimum = sum;
                                    minDist[0]=a;
									minDist[1]=b;
									minDist[2]=c;
									minDist[3]=d;
									minDist[4]=e;
                                }
                            }
		for(int i=0;i<5;i++){
			if(i>0)
				cout<<" ";
			cout<<minDist[i];
		}
		cout<<endl;
	}
	return 0;
}