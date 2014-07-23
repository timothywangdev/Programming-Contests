#include <iostream>

using namespace std;

int a,b,n,m,T;
int fib[15000];
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>a>>b>>n>>m;
    fib[0]=a;
    fib[1]=b;
    if(n>1){
      for(int i=2;i<15000;i++){
	fib[i]=(fib[(i-1)]+fib[(i-2)])%10000;
      }
    }
    if(m==1){
      cout<<fib[n%60]%10<<endl;
    }
    if(m==2){
      cout<<fib[n%300]%100<<endl;
    }
    if(m==3){
      cout<<fib[n%1500]%1000<<endl;
    }y
    if(m==4){
      cout<<fib[n%15000]%10000<<endl;
    }
  }

  return 0;
}
