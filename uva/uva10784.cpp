#include <iostream>
#include <cmath>

using namespace std;
typedef long long LL;

LL N,t=0;
int main(){
  while(cin>>N){
    t++;
    if(!N)break;
    cout<<"Case "<<t<<": ";
    double n=((double)3+sqrt((double)(9+8*N)))/(double)2;
    LL nn=ceil(n);
    cout<<nn<<endl;
  }
  return 0;
}
