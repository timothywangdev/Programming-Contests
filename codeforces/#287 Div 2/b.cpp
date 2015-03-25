#include <bits/stdc++.h>
using namespace std;
long long r,x,y,xx,yy,d,p,k,t;
int main(){
  cin>>r>>x>>y>>xx>>yy;
  if(x==xx&&y==yy){
    cout<<"0"<<endl;
    return 0;
  }
  d=(x-xx)*(x-xx)+(y-yy)*(y-yy);
  k=sqrt((double)d)/(double)(2*r);
  if(k*r*k*r*4==d){
    cout<<k<<endl;
  }
  else{
    cout<<k+1<<endl;
  }
  return 0;
}
