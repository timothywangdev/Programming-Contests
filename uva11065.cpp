#include <cstdio>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef unsigned long long ULL;

int T,N,R;
ULL connections[64];
ULL a,b,maximum,total;
void search(ULL state, ULL count, int last){
  ULL p;
  for(int i=last;i<N;i++){
    p=(ULL)1<<i;
    if(!(p & state)){
      search(state|connections[i],count+1,i+1);
    }
  }
  if(state==(((ULL)1<<N)-1)){
    maximum=max(maximum,count);
    total++;
    return;
  }
}
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>N>>R;
    total=0;
    maximum=0;
    for(ULL i=0;i<N;i++){
      connections[i]=(ULL)1<<i;
    }
    for(int i=0;i<R;i++){
      cin>>a>>b;
      connections[a]|=(ULL)1<<b;
      connections[b]|=(ULL)1<<a;
    }
    search(0,0,0);
    cout<<total<<endl<<maximum<<endl;
  }
  return 0;
}
