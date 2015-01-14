#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int n,x,a,b;
vector<pair<int,int> > v;
int main(){
  cin>>n>>x;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    v.push_back(make_pair(a,b));
  }
  sort(v.begin(),v.end());
  int t=1,sum=0;
  for(int i=0;i<v.size();i++){
    int d=v[i].first-t;
    sum+=v[i].second-v[i].first+1+d%x;
    t=v[i].second+1;
  }
  cout<<sum<<endl;
  return 0;
}
