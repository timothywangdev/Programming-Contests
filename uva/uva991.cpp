#include <iostream>

using namespace std;

int f[11];
int n;
bool first=true;
int main(){
  f[0]=1;
  for(int i=1;i<=10;i++){
    f[i]=0;
    for(int j=1;j<=i;j++){
      f[i]+=f[j-1]*f[i-j];
    }
  }
  while(cin>>n){
    if(!first){
      cout<<endl;
    }
    if(first){
      first=false;
    }
    cout<<f[n]<<endl;
  }
  return 0;
}
