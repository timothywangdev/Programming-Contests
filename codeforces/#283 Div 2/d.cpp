#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 100000
using namespace std;

int n,a[MAXN];
int t,s;
int g_total=0,p_total=0;
int p_index[MAXN+1],g_index[MAXN+1],p_near[MAXN],g_near[MAXN],p_count[MAXN],g_count[MAXN];
vector<pair<int,int> > rv;
bool check(int t,int &s){
  int p_next,g_next,p_sets=0,g_sets=0;
  for(int i=0;i<n;){
    if(a[i]==1){
      if(p_count[i]+t-1>p_total){
	p_next=n;
      }
      else{
	p_next=p_index[p_count[i]+t-1];
      }
      if(g_near[i]==n){
	g_next=n;
      }
      else{
	if(g_count[g_near[i]]+t-1>g_total){
	  g_next=n;
	}
	else{
	  g_next=g_index[g_count[g_near[i]]+t-1];
	}
      }
      if(p_next<g_next){
	p_sets++;
	i=p_next+1;
      }
      else if(p_next>g_next){
	g_sets++;
	i=g_next+1;
      }
      else{
	return false;
      }
    }
    else{
      if(g_count[i]+t-1>g_total){
	g_next=n;
      }
      else{
	g_next=g_index[g_count[i]+t-1];
      }
      if(p_near[i]==n){
	p_next=n;
      }
      else{
	if(p_count[p_near[i]]+t-1>p_total){
	  p_next=n;
	}
	else{
	  p_next=p_index[p_count[p_near[i]]+t-1];
	}
      }
      if(p_next<g_next){
	p_sets++;
	i=p_next+1;
      }
      else if(p_next>g_next){
	g_sets++;
	i=g_next+1;
      }
      else{
	return false;
      }
    }
  }
  if(g_sets==p_sets){
    return false;
  }
  else{
    if(g_sets>p_sets){
      if(a[n-1]!=2)return false;
    }
    else{
      if(a[n-1]!=1)return false;
    }
    s=max(g_sets,p_sets);
    return true;
  }
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]==1){
      p_total++;
      p_index[p_total]=i;
    }
    else{
      g_total++;
      g_index[g_total]=i;
    }
    p_count[i]=p_total;
    g_count[i]=g_total;
  }
  int last_p=n,last_g=n;
  for(int i=n-1;i>=0;i--){
    if(a[i]==1){
      g_near[i]=last_g;
      last_p=i;
    }
    else{
      p_near[i]=last_p;
      last_g=i;
    }
  }
  for(int t=n;t>=1;t--){
    if(check(t,s)){
      rv.push_back(make_pair(s,t));
    }
  }
  sort(rv.begin(),rv.end());
  cout<<rv.size()<<endl;
  for(int i=0;i<rv.size();i++){
    cout<<rv[i].first<<" "<<rv[i].second<<endl;
  }
  return 0;
}
