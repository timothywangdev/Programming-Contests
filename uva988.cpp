#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,n,t;

vector<bool> death;
vector<int> dp,inDeg;
vector<vector<int> > edge,reverseEdge;
vector<int> getTopo(){
  vector<int> rv;
  queue<int> q;
  for(int i=0;i<N;i++){
    if(inDeg[i]==0){
      q.push(i);
    }
  }
  while(q.size()){
    int front=q.front();
    q.pop();
    inDeg[front]=-1;
    rv.push_back(front);
    for(int i=0;i<edge[front].size();i++){
      int u=edge[front][i];
      inDeg[u]--;
      if(!inDeg[u]){
	q.push(u);
      }
    }
  }
  return rv;
}
bool first=true;
int main(){
  while(cin>>N){
    if(!first)cout<<endl;
    else{
      first=false;
    }
    death=vector<bool>(N,false);
    dp=vector<int>(N,0);
    inDeg=vector<int>(N,0);
    dp[0]=1;
    int total=0;
    edge=vector<vector<int> >(N,vector<int>());
    reverseEdge=vector<vector<int> >(N,vector<int>());
    for(int i=0;i<N;i++){
      cin>>n;
      if(!n){
	death[i]=true;
      }
      for(int j=0;j<n;j++){
	cin>>t;
	edge[i].push_back(t);
	inDeg[t]++;
	reverseEdge[t].push_back(i);
      }
    }
    vector<int> topo=getTopo();
    for(int i=0;i<topo.size();i++){
      int k=topo[i];
      for(int j=0;j<reverseEdge[k].size();j++){
	dp[k]+=dp[reverseEdge[k][j]];
      }
      if(death[k]){
	total+=dp
[k];
      }
    }
    cout<<total<<endl;
  }
  return 0;
}
