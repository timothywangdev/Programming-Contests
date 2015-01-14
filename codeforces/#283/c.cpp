#include <iostream>
#include <string.h>
using namespace std;

char a[100][100];
bool removed[100];
int n,m;

bool check(int r,int c){
  for(int i=0;i<=c;i++){
    if(removed[i])continue;
    if(a[r-1][i]<a[r][i])return true;
    else if(a[r-1][i]>a[r][i])return false;
  }
  return true;
}
bool violation(int c){
  for(int i=1;i<n;i++){
    if(!check(i,c)){
      return true;
    }
  }
  return false;
}
int better(int r1,int r2,int c){
  int rv=0;
  if(r1==r2)return 0;
  for(int i=c+1;i<m;i++){
    bool vio=false;
    for(int j=r1+1;j<=r2;j++){
      if(!(a[j-1][i]<a[j][i])){
	vio=true;
	break;
      }
    }
    if(vio){
      rv++;
    }
    else{
      bool inc=true;
      for(int j=r1+1;j<=r2;j++){
	if(a[j][i]==a[j-1][i]){
	  inc=false;
	  break;
	}
      }
      if(inc)break;
    }
  }
  return rv;
}
bool strictInc(int c){
  for(int j=1;j<=n;j++){
    bool inc=true;
    for(int k=0;k<=c;k++){
      if(a[j-1][k]<a[j][k]){
	inc=true;
	break;
      } 
    }
    if(!inc)return false;
   }
  return true;
}
int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  int sum=0;
  memset(removed,false,sizeof(removed));
  for(int i=0;i<m;i++){
    if(violation(i)){
      removed[i]=true;
      sum++;
    }
  }
  cout<<sum<<endl;
  return 0;
}
