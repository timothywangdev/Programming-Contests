#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>
using namespace std;
typedef long long LL;
vector<pair<string,LL> > v;

string a,b,n1,s1,n2,s2,n3,s3;
int N;
bool mysort(const pair<string, LL> &a, const pair<string,LL> &b){
  string aa=a.first;
  string bb=b.first;
  transform(aa.begin(),aa.end(),aa.begin(),::tolower);
  transform(bb.begin(),bb.end(),bb.begin(),::tolower);
  if(a.second<b.second){
    return true;
  }
  else if(a.second==b.second){
    return aa<bb;
  }
  return false;
}
LL toLL(string s){
  LL rv;
  istringstream iss(s);
  iss>>rv;
  return rv;
}
int main(){
  while(cin>>N){
    v.clear();
    for(int i=0;i<N;i++){
      cin>>a>>b>>n1>>s1>>n2>>s2>>n3>>s3;
     
      v.push_back(make_pair(a,toLL(n1)*60000+toLL(n2)*1000+toLL(n3)));
    }
    sort(v.begin(),v.end(),mysort);
    for(int i=0;i<v.size();i+=2){
      cout<<"Row "<<i/2+1<<endl;
      cout<<v[i].first<<endl;
      if(i+1<v.size()){
	cout<<v[i+1].first<<endl;
      }
    }
    cout<<endl;
  }
  return 0;
}
