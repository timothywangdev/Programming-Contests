#include <iostream>

using namespace std;
typedef long long LL;

LL f[77],n;

int main(){
  f[1]=1;
  f[2]=f[3]=2;
  for(int i=4;i<=76;i++){
    f[i]=f[i-2]+f[i-3];
  }
  while(cin>>n){
    cout<<f[n]<<endl;
  }
  return 0;
}
