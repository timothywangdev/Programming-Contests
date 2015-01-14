#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

class Poly{
public:
  int max_pos;
  long long c[10001];
  Poly(){
    max_pos=0;
    memset(c,0,sizeof(c));
  }
  void set_c_plus(int i,long long v){
    c[i]+=v;
    if(c[i]==0){
      if(max_pos==i&&i!=0)max_pos--;
    }
    if(c[i]!=0){
      max_pos=max(max_pos,i);
    }
  }
  void set_c(int i,long long v){
    c[i]=v;
    if(c[i]==0){
      if(max_pos==i&&i!=0)max_pos--;
    }
    if(c[i]!=0){
      max_pos=max(max_pos,i);
    }
  }
  Poly &operator=(const Poly &other){
    max_pos=other.max_pos;
    for(int i=0;i<=max_pos;i++){
      c[i]=other.c[i];
    }
    return *this;
  }
  void fuckyou(long long p1,long long v1,long long p2,long long v2){
    set_c_plus(p1,-v1);
    set_c_plus(p2,-v2);
  }
  Poly operator*=(const Poly &other){
    
    return *this;
  }

};

int N,K,i;
long long t,a,b,c,d;
int main(){
  while(cin>>N>>K){
    if(N==-1&&K==-1)break;
    Poly curr,other;
    for(i=0;i<=N;i++){
      cin>>t;
      curr.set_c(i,t);
    }
    other.set_c(0,1);
    other.set_c(K,1);
    
    do{
      i=curr.max_pos-other.max_pos;
      if(i<0)break;
      long long shit=curr.c[curr.max_pos]/other.c[other.max_pos];
      if(other.max_pos==0){
	curr.fuckyou((long long)curr.max_pos,shit*other.c[other.max_pos],(long long)i,0);
      }
      else{
	curr.fuckyou((long long)curr.max_pos,shit*other.c[other.max_pos],(long long)i,shit);
      }
      if(curr.max_pos==0&&curr.c[0]==0)break;
    }while(i>=0);
    for(int i=0;i<=curr.max_pos;i++){
      if(i>0)
	cout<<" ";
      cout<<curr.c[i];
    }
    cout<<endl;
  }
  return 0;
}
