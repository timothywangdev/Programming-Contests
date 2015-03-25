#include <bits/stdc++.h>

using namespace std;

int n;
int l[1200],r[1200];
bool f[600][1201],vis[600][1201];
int ne[600][1201];
bool solve(int i,int j){
  if(j==0)return true;
  if(vis[i][j]){
    return f[i][j];
  }
  vis[i][j]=true;
  for(int p=l[i];p<=min(r[i],j-1);p++){
    if((p+1)%2!=0)continue;
    f[i][j]|=solve(i+1,p-1)&&solve(i+(p+1)/2,j-p-1);
    if(f[i][j]){
      ne[i][j]=p;
      break;
    }
  }
  //cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
  return f[i][j];
}
void print(int i,int j){
  if(j==0)return;
  cout<<'(';
  print(i+1,ne[i][j]-1);
  cout<<')';
  print(i+(ne[i][j]+1)/2,j-ne[i][j]-1);
}
int main(){
  memset(vis,false,sizeof(vis));
  memset(f,false,sizeof(f));
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>l[i]>>r[i];
  }
  solve(0,2*n);
  if(f[0][2*n]){
    print(0,2*n);
  }
  else{
    cout<<"IMPOSSIBLE"<<endl;
  }
  return 0;
}
