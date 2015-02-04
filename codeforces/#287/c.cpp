#include <bits/stdc++.h>

using namespace std;

long long h,n;

long long pow2[51];
long long f(long long h,long long n,bool left){
  if(h==1){
    return 0;
  }
  if(left){
    if(pow2[h-1]/2<n){
      return pow2[h-1]-1+f(h-1,n-(pow2[h-1]/2),true)+1;
    }
    else{
      return f(h-1,n,false)+1;
    }
  }
  else{
    if(pow2[h-1]/2>=n){
      return pow2[h-1]-1+f(h-1,n,false)+1;
    }
    else{
      return f(h-1,n-(pow2[h-1]/2),true)+1;
    }
  }
}
int main(){
  cin>>h>>n;
  pow2[0]=1;
  for(long long i=1;i<=50;i++){
    pow2[i]=pow2[i-1]*2;
  }
  cout<<f(h+1,n,true)<<endl;
  return 0;
}
