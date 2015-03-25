#include <bits/stdc++.h>

using namespace std;

int n,p,d;
int a[30001];
int f[30001][250*2];
bool vis[30001][250*2];
int search(int i,int offset){
  if(i>30000)return 0;
  if(vis[i][offset]){
    return f[i][offset];
  }
  vis[i][offset]=true;
  int j=d+offset-250;
  int maximum=max(search(i+j,j-d+250),search(i+j+1,j+1-d+250));
  if(j-1>0){
    maximum=max(maximum,search(i+j-1,j-1-d+250));
  }
  f[i][offset]=maximum+a[i];
  return f[i][offset];
}
int main(){
  cin>>n>>d;
  memset(a,0,sizeof(a));
  memset(vis,false,sizeof(vis));
  for(int i=0;i<n;i++){
    cin>>p;
    a[p]++;
  }
  cout<<search(d,250)<<endl;
  return 0;
}
