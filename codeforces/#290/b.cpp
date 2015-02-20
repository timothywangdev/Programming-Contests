#include <bits/stdc++.h>

using namespace std;

int n,m;
char a[50][50];
bool vis[50][50];
bool cycle;
int mo[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int i,int j,int pi,int pj,char color){
  //cout<<i<<" "<<j<<" --> "<<endl;
  vis[i][j]=true;
  for(int k=0;k<4;k++){
    int ii=i+mo[k][0];
    int jj=j+mo[k][1];
    if(0<=ii&&ii<n&&0<=jj&&jj<m&&a[ii][jj]==color&&!(ii==pi&&jj==pj)){
      if(vis[ii][jj]){
	cycle=true;
      }
      else {
	dfs(ii,jj,i,j,color);
      }
    }
  }
}
int main(){
  memset(vis,false,sizeof(vis));
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  cycle=false;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(!vis[i][j]){
	dfs(i,j,-1,-1,a[i][j]);
	//cout<<"==============="<<endl;
	if(cycle){
	  cout<<"Yes"<<endl;
	  return 0;
	}
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}
