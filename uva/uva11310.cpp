#include <iostream>

using namespace std;
typedef long long LL;

LL f[41],T,n;

int main(){
  f[0]=1;
  f[1]=1;
  f[2]=5;
  for(int i=3;i<=40;i++){
    f[i]=f[i-1]+4*f[i-2]+2*f[i-3];
  }
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>n;
    cout<<f[n]<<endl;
  }
  return 0;
}
