#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool m[26][26],exist[26];
int dp[26],indegree[26];
int v[26];

int T,c,gMax;
char a,b;
string s;
void process(string s){
  istringstream iss(s);
  char a,b;
  int k;
  iss>>a>>k;
  v[a-'A']=k;
  exist[a-'A']=true;
  while(iss>>b){
    exist[b-'A']=true;
    m[b-'A'][a-'A']=true;
    indegree[a-'A']++;
  }
}
vector<int> getTopoSort(){
  vector<int> rv;
  bool found=true;
  while(true){
    found=false;
    int target=-1;
    for(int i=0;i<26;i++){
      if(exist[i]&&indegree[i]==0){
	target=i;
	found=true;
	break;
      }
    }
    if(!found)
      break;
    rv.push_back(target);
    indegree[target]=-1;
    for(int i=0;i<26;i++){
      if(exist[i]&&m[target][i]){
	indegree[i]--;
      }
    }
  }
  return rv;
}
int main(){
  cin>>T;
  getline(cin,s);
  getline(cin,s);
  for(int t=0;t<T;t++){
    if(t>0)cout<<endl;
    gMax=0;
    memset(exist,false,sizeof(exist));
    memset(indegree,0,sizeof(indegree));
    memset(m,false,sizeof(m));
    while(getline(cin,s)){
      if(s=="")break;
      process(s);
    }
    vector<int> topo=getTopoSort();
    for(int i=0;i<topo.size();i++){
      int maximum=0;
      for(int j=0;j<26;j++){
	if(exist[j]&&m[j][topo[i]]){
	  maximum=max(maximum,dp[j]);
	}
      }
      dp[topo[i]]=maximum+v[topo[i]];
      gMax=max(gMax,dp[topo[i]]);
    }
    cout<<gMax<<endl;
  }
  return 0;

}

	   
