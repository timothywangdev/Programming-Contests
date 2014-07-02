#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int flo[120][15][15];
int dp[120][15];
int N,M,t;
string s;
int main(){
  while(getline(cin,s)){
    cin>>N>>M;
    int gMin=2147483647;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<N-1;i++){
      for(int j=0;j<M;j++){
	for(int k=0;k<M;k++){
	  cin>>flo[i][j][k];
	}
      }
    }
    for(int i=1;i<N;i++){
      for(int j=0;j<M;j++){
	int minimum=2147483647;
	for(int k=0;k<M;k++){
	  minimum=min(minimum,flo[i-1][k][j]+dp[i-1][k]);
	}

	dp[i][j]=minimum;
	if(i==N-1){
	  gMin=min(gMin,dp[i][j]);
	}

      }
    }
    cout<<s<<endl;
    cout<<gMin+2*(N-1)<<endl;
    getline(cin,s);
  }
  return 0;
}
