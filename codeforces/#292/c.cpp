#include <bits/stdc++.h>

using namespace std;

int c[10];
vector<int> fa[10];

int main(){

  fa[2].push_back(2);
  fa[3].push_back(3);
  fa[4].push_back(2);
  fa[4].push_back(2);
  fa[5].push_back(5);
  fa[6].push_back(2);
  fa[6].push_back(3);
  fa[7].push_back(7);
  fa[8].push_back(2);
  fa[8].push_back(2);
  fa[8].push_back(2);
  fa[9].push_back(3);
  fa[9].push_back(3);
  int n;
  cin>>n;
  string s;
  cin>>s;
  for(int i=0;i<n;i++){
    int k=(int)(s[i]-'0');
    //cout<<"add: "<<k<<endl;
    if(k>=2){
      for(int p=2;p<=k;p++){
	for(int j=0;j<fa[p].size();j++){
	  c[fa[p][j]]++;
	  // cout<<fa[p][j]<<endl;
	}
      }
    }
  }
  int target=-1;
  for(int i=7;i>=2;i--){
    if(c[i]>0){
      target=i;
      break;
    }
  }
  vector<int> rv;
  while(target!=-1){
    rv.push_back(target);
    for(int i=target;i>=2;i--){
      for(int j=0;j<fa[i].size();j++){
	c[fa[i][j]]--;
      }
    }
    int newTarget=-1;
    for(int i=target;i>=2;i--){
      if(c[i]>0){
	newTarget=i;
	break;
      }
    }
    target=newTarget;
  }
  sort(rv.begin(),rv.end());
  for(int i=rv.size()-1;i>=0;i--){
    cout<<rv[i];
  }
  cout<<endl;
  return 0;
} 
