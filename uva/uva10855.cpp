#include <iostream>
#include <string.h>
using namespace std;

char big[1000][1000],small[4][1000][1000];
int counter[4];
int N,n;
void rotate(int from,int to){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			small[to][j][n-i-1]=small[from][i][j];
}
bool check(int i,int j,int k){
	for(int r=0;r<n;r++)
		for(int c=0;c<n;c++)
			if(big[i+r][j+c]!=small[k][r][c])
				return false;
	return true;
}
int main(){
	while(cin>>N>>n){
		if(N==0&&n==0)
			break;
		memset(counter,0,sizeof(counter));
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				cin>>big[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>small[0][i][j];
		for(int i=1;i<4;i++)
			rotate(i-1,i);
		for(int k=0;k<4;k++)
			for(int i=0;i<=N-n;i++)
				for(int j=0;j<=N-n;j++)
					if(check(i,j,k))
						counter[k]++;
		cout<<counter[0];
		for(int i=1;i<4;i++)
			cout<<" "<<counter[i];
		cout<<endl;
	}
	return 0;
}