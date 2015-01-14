#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using namespace std;

class Pair{
public:
  int lo;
  int hi;
  int actor;
  int ori_idx;
  int counter;
  bool is_actor;
  Pair(int lo,int hi,int ori_idx,bool is_actor,int counter):lo(lo),hi(hi),ori_idx(ori_idx),is_actor(is_actor),counter(counter){}
};
bool operator<(const Pair &a,const Pair &b){
    if(a.lo<b.lo)return true;
    else if(a.lo==b.lo){
      if(a.is_actor&&!b.is_actor)return true;
    }
    return false;
}
vector<Pair> a;
int n,m;
int lo,hi,counter;
int c[100000],rv[100000];
set<pair<int,int> > s;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>lo>>hi;
    a.push_back(Pair(lo,hi,i,false,0));
  }
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>lo>>hi>>counter;
    c[i]=counter;
    a.push_back(Pair(lo,hi,i,true,counter));
  }
  sort(a.begin(),a.end());
  for(int i=0;i<a.size();i++){
    if(a[i].is_actor){
      s.insert(make_pair(a[i].hi,a[i].ori_idx));
    }
    else{
      set<pair<int,int> >::iterator it=s.lower_bound(make_pair(a[i].hi,0));
      if(it==s.end()){
	cout<<"NO"<<endl;
	return 0;
      }
      else{
	rv[a[i].ori_idx]=it->second+1;
	c[it->second]--;
	if(!c[it->second])s.erase(it);
      }
    }
  }
  cout<<"YES"<<endl;
  for(int i=0;i<n;i++){
    cout<<rv[i];
    if(i!=n-1)cout<<" ";
  }
  cout<<endl;
  return 0;
}
