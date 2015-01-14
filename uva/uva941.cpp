#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long LL;
LL T,N;
string s;

// *************************************************************
// nth permutation of a string
// Usage: permu(ss,getDist(s)+N) returns nth permutation of a string s
LL fa[21];
class Pos{
public:
  int ori_pos;
  int s_pos;
  char ch;
  bool used;
  Pos(int ori_pos,char ch):ori_pos(ori_pos),ch(ch),used(false){}
};
bool sortByChar(const Pos &a,const Pos &b){
  return a.ch<b.ch;
} 
bool sortByOriPos(const Pos &a, const Pos &b){
  return a.ori_pos<b.ori_pos;
}
// Dist between s and sort(s)
LL getDist(string s){
  vector<Pos> v;
  vector<int> rv;
  for(int i=0;i<s.size();i++){
    v.push_back(Pos(i,s[i]));
  }
  sort(v.begin(),v.end(),sortByChar);
  for(int i=0;i<v.size();i++){
    v[i].s_pos=i;
  }
  sort(v.begin(),v.end(),sortByOriPos);
  for(int i=0;i<v.size();i++){
    rv.push_back(v[i].s_pos);
    for(int j=i+1;j<v.size();j++){
      if(v[j].s_pos>v[i].s_pos){
	v[j].s_pos--;
      }
    }
  }
  LL sum=0;
  for(int i=0;i<rv.size();i++){
    sum+=fa[rv.size()-i-1]*rv[i];
  }
  return sum;
}
// Given ss=sort(s), dist d, returns dth(zero-base) permutation of s
string permu(string ss,LL d){
  vector<Pos> v;
  vector<int> rv;
  string s;
  LL current;
  for(int i=0;i<ss.size();i++){
    v.push_back(Pos(i,ss[i]));
    v[i].s_pos=i;
  }
  for(int i=0;i<v.size();i++){
    if(i!=0){
      d-=fa[v.size()-i]*current;
    }
    current=d/fa[v.size()-i-1];
    int counter=0;
    for(int j=0;j<v.size();j++){
      if(!v[j].used){
	if(counter==current){
	  s=s+v[j].ch;
	  v[j].used=true;
	  break;
	}
	else{
	  counter++;
	}
      }
    }
  }
  return s;
}
// *************************************************************
int main(){
  cin>>T;
  fa[0]=1;
  for(int i=1;i<=20;i++){
    fa[i]=fa[i-1]*i;
  }
  for(int t=0;t<T;t++){
    cin>>s>>N;
    string ss=s;
    sort(ss.begin(),ss.end());
    cout<<permu(ss,getDist(s)+N)<<endl;
  }
  return 0;
}
