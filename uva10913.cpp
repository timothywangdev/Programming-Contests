#include <iostream>
#include <string.h>
#include <algorithm>
#define INF 2147483647
using namespace std;

int N,K;
int m[75][75];
int dp[75][75][6];
int sum[75][75][75],sumK[75][75][75];
bool dpp[75][75][6];
int search(int r,int c,int k){
  if(r==N&&c==N-1&&k>=0){
    return 0;
  }
  if(r==N&&c!=N-1){
    return -INF;
  }
  if(k<0){
    return -INF;
  }
  if(dpp[r][c][k]){
    return dp[r][c][k];
  }
  int maximum=-INF;
  for(int i=0;i<N;i++){
    int p=search(r+1,i,k-sumK[r][c][i]);
    if(p!=-INF){
      maximum=max(maximum,sum[r][c][i]+p);
    }
  }
  dpp[r][c][k]=true;
  return dp[r][c][k]=maximum;
}
int counter=0;
int main(){
  while(cin>>N>>K){
    if(!N&&!K)break;
    counter++;
    memset(sum,0,sizeof(sum));
    memset(dp,0,sizeof(dp));
    memset(dpp,false,sizeof(dpp));
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	cin>>m[i][j];
	sum[i][j][j]=m[i][j];
	sumK[i][j][j]=(m[i][j]<0);
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	for(int k=j+1;k<N;k++){
	  sum[i][j][k]=sum[i][k][j]=sum[i][j][k-1]+m[i][k];
	  sumK[i][j][k]=sumK[i][k][j]=sumK[i][j][k-1]+(m[i][k]<0);
	}
      }
    }
    int p=search(0,0,K);
    cout<<"Case "<<counter<<": ";
    if(p==-INF){
      cout<<"impossible"<<endl;
    }
    else{
      cout<<p<<endl;
    }
  }
  return 0;
}
