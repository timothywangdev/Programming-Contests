#include <bits/stdc++.h>
using namespace std;

int m,t,r;
int w[300];
int a[602];
bool used[602];
int sum=0;
int offset=301;
void ignite(int i){
  sum++;
  used[i]=true;
  for(int j=i+1;j<=i+t;j++){
    if(j<602){
      a[j]++;
    }
  }
}
void process(int k){
  if(a[k+offset]>=r)return;
  for(int i=k-1;i+offset>=0;i--){
    if(!used[i+offset]){
      ignite(i+offset);
      if(a[k+offset]>=r){
	return;
      }
    }
  }
}
int main(){
  cin>>m>>t>>r;
  memset(a,0,sizeof(a));
  for(int i=0;i<m;i++){
    cin>>w[i];
  }
  for(int i=0;i<m;i++){
    process(w[i]);
    if(a[w[i]+offset]<r){
      cout<<"-1"<<endl;
      return 0;
    }
  }
  cout<<sum<<endl;
  return 0;
}
