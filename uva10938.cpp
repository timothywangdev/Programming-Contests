#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N 10000
#define LOG_TWO_N 13
vector<int> edge[5000];
int parent[5000];
int L[10000],H[10000],E[10000];
int N,a,b,ind,meet1,meet2,l;

class RMQ{
  // static segment tree or sparse table data structure

  // original content
  int _A[MAX_N];
  // sparse table 
  // Spt[i][j] stores the index of the minimum value in the sub array
  // starting at i and have length 2^j
  int Spt[MAX_N][LOG_TWO_N];
public:
  RMQ(){}
  void build(int n,int A[]){
    for(int i=0;i<n;i++){
      _A[i]=A[i];
      Spt[i][0]=i;
    }
    for(int j=1;(1<<j)<=n;j++){
      for(int i=0;i+(1<<j)-1<n;i++){
	if(_A[Spt[i][j-1]]<_A[Spt[i+(1<<(j-1))][j-1]]){
	  Spt[i][j]=Spt[i][j-1];
	}
	else{
	  Spt[i][j]=Spt[i+(1<<(j-1))][j-1];
	}
      }
    }
  }
  // Returns a index
  int query(int i,int j){
    int k=(int)floor(log2((double)(j-i+1)));
    if(_A[Spt[i][k]]<=_A[Spt[j-(1<<k)+1][k]]){
      return Spt[i][k];
    }
    else{
      return Spt[j-(1<<k)+1][k];
    }
  }
};
void dfs(int cur,int depth){
  L[ind]=depth;
  H[cur]=ind;
  E[ind]=cur;
  ind++;
  for(int i=0;i<edge[cur].size();i++){
    if(H[edge[cur][i]]!=-1)continue;
    parent[edge[cur][i]]=cur;
    dfs(edge[cur][i],depth+1);
    E[ind]=cur;
    L[ind]=depth;
    ind++;
  }
}
RMQ rmq;
void BuildRMQ(){
  ind=0;
  memset(H,-1,sizeof(H));
  dfs(0,0);
  rmq.build(ind,L);
}

int getParent(int cur){
  return parent[cur];
}
int findMeetPoint(int cur,int steps){
  for(int i=0;i<steps;i++){
    cur=getParent(cur);
  }
  return cur;
}
int main(){
  while(cin>>N){
    if(!N)break;
    for(int i=0;i<N;i++){
      edge[i].clear();
    }
    for(int i=0;i<N-1;i++){
      cin>>a>>b;
      a--;
      b--;
      vector<int>::iterator it=find(edge[a].begin(),edge[a].end(),b);
      if(it==edge[a].end()){
	edge[a].push_back(b);
      }
      it=find(edge[b].begin(),edge[b].end(),a);
      if(it==edge[b].end()){
	edge[b].push_back(a);
      }
    }
    BuildRMQ();
    cin>>l;
    for(int i=0;i<l;i++){
      cin>>a>>b;
      a--;
      b--;
      int aa=a;
      int bb=b;
      a=H[a];
      b=H[b];
      if(a>b){
	swap(a,b);
      }
      //ycout<<rmq.query(a,b)<<endl;
      int ancestor=E[rmq.query(a,b)];
      // edges
      int dist=L[H[aa]]+L[H[bb]]-2*L[H[ancestor]];
      if(L[H[aa]]>L[H[bb]]){
	swap(aa,bb);
      }
      if(dist%2==0){
	meet1=findMeetPoint(bb,dist/2);
	cout<<"The fleas meet at "<<meet1+1<<"."<<endl;
      }
      else{
	meet1=findMeetPoint(bb,dist/2);
	meet2=findMeetPoint(bb,dist/2+1);
	if(meet1>meet2)swap(meet1,meet2);
	cout<<"The fleas jump forever between "<<meet1+1<<" and "<<meet2+1<<"."<<endl;
      }
    }
  }
  return 0;
}
