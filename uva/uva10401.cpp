#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

string s;
long long dp[16][16];
int toInt(char ch){
  if('0'<=ch&&ch<='9'){
    return (int)(ch-'0');
  }
  else{
    return (int)(ch-'A')+10;
  }
}
int main(){
  while(cin>>s){
    int N=s.size();
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=N;i++){
      dp[0][i]=1;
    }
    for(int i=1;i<=N;i++){
      char ch=s[i-1];
      if(ch!='?'){
	int p=toInt(ch);
	if(i==1){
	  dp[i][p]=1;
	  continue;
	}
	for(int j=1;j<=N;j++){
	  if(abs(p-j)>=2){
	    dp[i][p]+=dp[i-1][j];
	  }
	}
      }
      else{
	for(int j=1;j<=N;j++){
	  if(i==1){
	    dp[i][j]=1;
	  }
	  else{
	    for(int k=1;k<=N;k++){
	      if(abs(j-k)>=2){
		dp[i][j]+=dp[i-1][k];
	      }
	    }
	  }
	}
      }
    }
    long long total=0;
    for(int i=1;i<=N;i++){
      total+=dp[N][i];
    }
    cout<<total<<endl;
  }
  return 0;
}
