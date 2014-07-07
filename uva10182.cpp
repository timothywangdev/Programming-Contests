#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int N,x,y,offset,tmp;
int main(){
  while(cin>>N){
    int n=N-1;
    if(n==0){
      cout<<"0 0"<<endl;
      continue;
    }
    // double fuck=(sqrt(12*n+9)-3)/(double)6;
    // cout<<fuck<<endl;
    int k=floor((sqrt(12*n+9)-3)/(double)6);
    //cout<<k<<endl;
    if(3*k*(1+k)==n){
      offset=6*k;
    }
    else{
      k++;
      offset=n-(3*(k-1)*k);
    }
    x=k-1;
    y=1;
    if(offset<=k){
      tmp=offset-1;
      cout<<x-tmp<<" "<<y+tmp<<endl;
    }
    else if(offset<=2*k){
      tmp=offset-k-1;
      cout<<-1-tmp<<" "<<k<<endl;
    }
    else if(offset<=3*k){
      tmp=offset-2*k-1;
      cout<<-k<<" "<<k-1-tmp<<endl;
    }
    else if(offset<=4*k){
      tmp=offset-3*k-1;
      cout<<-k+1+tmp<<" "<<-1-tmp<<endl;
    }
    else if(offset<=5*k){
      tmp=offset-4*k-1;
      cout<<1+tmp<<" "<<-k<<endl;
    }
    else if(offset<=6*k){
      tmp=offset-5*k-1;
      cout<<k<<" "<<-k+1+tmp<<endl;
    }
  }
  return 0;
}
