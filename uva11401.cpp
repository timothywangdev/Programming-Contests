#include <iostream>

using namespace std;

typedef long long LL;

LL f[1000001],n;

int main(){
  f[3]=0;
  f[4]=1;
  for(int i=5;i<=1000000;i++){
    LL k=i/2-1;
    f[i]=f[i-1]+k*(i-k-2);
  }
  while(cin>>n){
    if(n<3)break;
    cout<<f[n]<<endl;
  }Y
  return 0;
}
