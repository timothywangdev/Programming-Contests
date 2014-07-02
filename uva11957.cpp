#include <iostream>
#include <string.h>

using namespace std;

int T,N,wi;
char m[100][100];
long long dp[100][100];
int mo[4][2]={{1,-1},{1,1},{2,-2},{2,2}};
bool inRange(int i,int j){
  return 0<=i&&i<N&&0<=j&&j<N;
}
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>N;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	cin>>m[i][j];
	if(m[i][j]=='W'){
	  wi=i;
	  dp[i][j]=1;
	  m[i][j]='.';
	}
      }
    }
    // cout<<"wi: "<<wi<<endl;
    for(int i=wi-1;i>=0;i--){
      for(int j=0;j<N;j++){
	if(m[i][j]!='.')
	  continue;
	for(int k=0;k<2;k++){
	  int ii=i+mo[k][0];
	  int jj=j+mo[k][1];
	  if(inRange(ii,jj)&&m[ii][jj]=='.'){
	    dp[i][j]=(dp[i][j]+dp[ii][jj])%1000007;
	  }
	}
	for(int k=2;k<4;k++){
	  int ii=i+mo[k][0];
	  int jj=j+mo[k][1];
	  int iii=i+mo[k-2][0];
	  int jjj=j+mo[k-2][1];
	  if(inRange(ii,jj)&&m[ii][jj]=='.'&&m[iii][jjj]=='B'){
	    dp[i][j]=(dp[i][j]+dp[ii][jj])%1000007;
	  }
	}
      }
    }
    /*
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	cout<<dp[i][j];
      }
      cout<<endl;
    }
    */
    long long total=0;
    for(int i=0;i<N;i++){
      total=(total+dp[0][i])%1000007;
    }
    cout<<"Case "<<t+1<<": ";
    cout<<total<<endl;
  }
  return 0;
}
