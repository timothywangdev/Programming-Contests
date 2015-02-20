#include <bits/stdc++.h>

using namespace std;

vector<int> edge[26];
int indeg[26];
string s[100];
bool edgeExist[26][26];
bool vis[26];
int n;
bool impossible=false;
void cmp(int i,int j){
  int ml=min(s[i].length(),s[j].length());
  for(int k=0;k<ml;k++){
    if(s[i][k]!=s[j][k]){
      if(!edgeExist[s[i][k]-'a'][s[j][k]-'a']){
	edge[s[i][k]-'a'].push_back(s[j][k]-'a');
	edgeExist[s[i][k]-'a'][s[j][k]-'a']=true;
	indeg[s[j][k]-'a']++;
	//cout<<s[i][k]<<"->"<<s[j][k]<<endl;
      }
      break;
    }
  }
  bool diff=false;
  for(int k=0;k<ml;k++){
    if(s[i][k]!=s[j][k]){
      diff=true;
    }
  }
  if(!diff&&s[i].length()>s[j].length()){
    impossible=true;
  }
}
int main(){
  memset(indeg,0,sizeof(indeg));
  memset(edgeExist,false,sizeof(edgeExist));
  memset(vis,false,sizeof(vis));
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      cmp(i,j);
    }
  }
  if(impossible){
    cout<<"Impossible"<<endl;;
    return 0;
  }
  bool found=true;
  vector<int> rv;
  while(found){
    found=false;
    for(int i=0;i<26;i++){
      if(indeg[i]==0&&!vis[i]){
	//cout<<"found: "<<(char)(i+'a')<<endl;
	rv.push_back(i);
	found=true;
	vis[i]=true;
	indeg[i]=-1;
	for(int j=0;j<edge[i].size();j++){
	  indeg[edge[i][j]]--;
	}
      }
    }
  }
  for(int i=0;i<26;i++){
    if(!vis[i]){
      cout<<"Impossible"<<endl;
      return 0;
    }
  }
  for(int i=0;i<26;i++){
    cout<<(char)(rv[i]+'a');
  }
  cout<<endl;
  return 0;
}
