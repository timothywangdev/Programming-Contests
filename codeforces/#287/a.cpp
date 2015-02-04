#include <bits/stdc++.h>

using namespace std;

struct t{
  int idx;
  int v;
};
int n,k;
t a[10000];
vector<int> rv;
bool cmp(const t &a, const t &b){
  return a.v<b.v;
}
int main(){
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>a[i].v;
    a[i].idx=i;
  }
  sort(a,a+n,cmp);
  for(int i=0;i<n;i++){
    if(k-a[i].v>=0){
      k-=a[i].v;
      rv.push_back(a[i].idx+1);
    }
  }
  cout<<rv.size()<<endl;
  for(int i=0;i<rv.size();i++){
    cout<<rv[i];
    if(i!=rv.size()-1)cout<<" ";
  }
  cout<<endl;
  return 0;
}
