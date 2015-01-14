#include <iostream>
#include <cmath>

using namespace std;
long long T,N,i,R;
int main(){
  cin>>T;
   for(int t=0;t<T;t++){
     cin>>N;
     if(N==0){
       cout<<"0"<<endl;
       continue;
     }
     R=0;
     long long P=floor(sqrt((double)N));
     for(i=1;i<=P;i++){
       R+=N/i;
     }
     for(i=N/P-1;i>=1;i--){
       int a=floor((double)N/(double)i);
       int b=(N%(i+1)==0)?ceil((double)N/(double)(i+1))+1:ceil((double)N/(double)(i+1));
       R+=(a-b+1)*i;
     }
     cout<<R<<endl;
   }
  return 0;
}
