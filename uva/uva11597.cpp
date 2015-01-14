#include <iostream>

using namespace std;

int t=0,n;
int main(){
  while(cin>>n){
    if(!n)break;
    t++;
    cout<<"Case "<<t<<": ";
    if(n%2==0){
      cout<<n/2<<endl;
    }
    else{
      cout<<(n+1)/2<<endl;
    }
  }
  return 0;
}
