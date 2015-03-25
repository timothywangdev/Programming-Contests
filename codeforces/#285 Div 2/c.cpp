#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int deg[100000],s[100000],n;
vector<pair<int,int> > rv;
queue<int> q;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>deg[i]>>s[i];
    if(deg[i]==1){
      q.push(i);
    }
  }
  while(!q.empty()){
    int front=q.front();
    q.pop();
    if(deg[front]==0)continue;
    int parent=s[front];
    rv.push_back(make_pair(front,parent));
    deg[parent]--;
    s[parent]^=front;
    if(deg[parent]==1){
      q.push(parent);
    }
  }
  cout<<rv.size()<<endl;
  for(auto i:rv){
    cout<<i.first<<" "<<i.second<<endl;
  }
  return 0;
}
