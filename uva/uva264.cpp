#include <iostream>
#include <cmath>

using namespace std;
long long n,offset;
int main(){
  while(cin>>n){
    long long k=floor((sqrt(1+8*n)-1)/2);
    offset=n-(k*(k+1))/2;
    if(offset==0){
      offset=k-1;
    }
    else{
      k++;
      offset--;
    }
    cout<<"TERM "<<n<<" IS ";
    if(k%2==1){
      cout<<k-offset<<"/"<<1+offset<<endl;
    }
    else{
      cout<<1+offset<<"/"<<k-offset<<endl;
    }
  }
  return 0;
}
