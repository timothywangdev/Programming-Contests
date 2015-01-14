#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int S;
int N;
int n;
int tmp;
int maximum;
int maxN;
vector<vector<int> >v;
vector<int> rv;
bool f[11][1001];
bool co[1001];
int cover(vector<int> &v){
  memset(f,false,sizeof(f));
  memset(co,false,sizeof(co));
  f[0][0]=co[0]=true;
  int m=0;
  for(int i=1;i<=S;i++){
    for(int j=0;j<=1000;j++){
      for(int k=0;k<v.size();k++){
	f[i][j]=f[i][j]||((j-v[k]>=0)&&f[i-1][j-v[k]]);
      }
      co[j]=co[j]||f[i][j];
    }
  }
  for(int i=0;i<=1000;i++){
    if(co[i]){
      m=max(m,i);
    }
    else{
      break;
    }
  }
  return m;
}
int main(){
  while(cin>>S&&S){
    cin>>N;
    v.clear();
    maximum=maxN=-1;
    for(int i=0;i<N;i++){
      cin>>n;
      vector<int> current;
      for(int j=0;j<n;j++){
	cin>>tmp;
	current.push_back(tmp);
      }
      reverse(current.begin(),current.end());
      v.push_back(current);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++){
      int tmp=cover(v[i]);
      if(tmp>maximum){
	maximum=tmp;
	maxN=v[i].size();
	rv=v[i];
      }
      else if(tmp==maximum&&v[i].size()<maxN){
	maxN=v[i].size();
	rv=v[i];
      }
    }
    cout<<"max coverage ="<<setw(4)<<max(maximum,0)<<" :";
    reverse(rv.begin(),rv.end());
    for(int i=0;i<rv.size();i++){
      cout<<setw(3)<<rv[i];
    }
    cout<<endl;
  }
  return 0;
}
