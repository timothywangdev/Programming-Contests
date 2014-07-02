#include <iostream>
#include <string.h>
#include <algorithm>
#define INF 2147483647
using namespace std;
int N,K,d;
long long dist[605][605];
long long dp[605][301];

long long search(int camp,int k){
  if(k==0){
    return dist[camp][N+1];
  }
  if(dp[camp][k]!=-1){
    return dp[camp][k];
  }
  long long minimum=2147483647;
  for(int i=1;i<=N;i++){
    if(i==camp)
      continue;
    long long p=search(i,k-1);
    minimum=min(minimum,max(dist[camp][i],p));
  }
  return dp[camp][k]=minimum;
}
int main(){
  while(cin>>N>>K){
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=N;i++){
      cin>>dist[i][i+1];
    }
    for(int i=0;i<=N;i++){
      for(int j=i+2;j<=N+1;j++){
	dist[i][j]=dist[j][i]=dist[i][j-1]+dist[j-1][j];
      }
    }
    cout<<search(0,K)<<endl;
  }
  return 0;
}
