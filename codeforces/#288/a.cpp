#include <bits/stdc++.h>

using namespace std;

int n,m,k,r,c;
bool a[1000][1000];
bool range(int r,int c){
  return (0<=r&&r<n&&0<=c&&c<m);
}
bool check(int r,int c){
  if(range(r+1,c)&&a[r+1][c]&&range(r,c+1)&&a[r][c+1]&&range(r+1,c+1)&&a[r+1][c+1]){
    return true;
  }
  if(range(r,c-1)&&a[r][c-1]&&range(r+1,c-1)&&a[r+1][c-1]&&range(r+1,c)&&a[r+1][c]){
    return true;
  }
  if(range(r-1,c)&&a[r-1][c]&&range(r,c+1)&&a[r][c+1]&&range(r-1,c+1)&&a[r-1][c+1]){
    return true;
  }
  if(range(r,c-1)&&a[r][c-1]&&range(r-1,c-1)&&a[r-1][c-1]&&range(r-1,c)&&a[r-1][c]){
    return true;
  }
  return false;
}
int main(){
  cin>>n>>m>>k;
  memset(a,false,sizeof(a));
  int rv=0;
  for(int i=0;i<k;i++){
    cin>>r>>c;
    r--;
    c--;
    a[r][c]=true;
    if(check(r,c)){
      cout<<i+1<<endl;
      return 0;
    }
  }
  cout<<rv<<endl;
  return 0; 
}
