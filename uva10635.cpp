#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int T,S,N,M;
int v[2][62501],pos[62501];




typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define STRICTLY_INCREASNG

VI LongestIncreasingSubsequence(VI v) {
  VPII best;
  VI dad(v.size(), -1);
  
  for (int i = 0; i < v.size(); i++) {
#ifdef STRICTLY_INCREASNG
    PII item = make_pair(v[i], 0);
    VPII::iterator it = lower_bound(best.begin(), best.end(), item);
    item.second = i;
#else
    PII item = make_pair(v[i], i);
    VPII::iterator it = upper_bound(best.begin(), best.end(), item);
#endif
    if (it == best.end()) {
      dad[i] = (best.size() == 0 ? -1 : best.back().second);
      best.push_back(item);
    } else {
      dad[i] = dad[it->second];
      *it = item;
    }
  }
  
  VI ret;
  for (int i = best.back().second; i >= 0; i = dad[i])
    ret.push_back(v[i]);
  reverse(ret.begin(), ret.end());
  return ret;
}

int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>S>>N>>M;
    for(int i=0;i<=N;i++){
      cin>>v[0][i];
    }
    for(int i=0;i<=M;i++){
      cin>>v[1][i];
    }
    int index=(N<=M)?0:1;
    memset(pos,-1,sizeof(pos));
    for(int i=1;i<max(N,M);i++){
      pos[v[1-index][i]]=i;
    }
    VI vv;
    for(int i=1;i<min(N,M);i++){
      if(pos[v[index][i]]!=-1){
	vv.push_back(pos[v[index][i]]);
      }
    }
    int rv=(vv.size()!=0)? LongestIncreasingSubsequence(vv).size():0;
    cout<<"Case "<<t+1<<": "<<rv+2<<endl;
  }
  return 0;
}
