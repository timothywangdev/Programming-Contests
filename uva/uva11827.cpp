#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;
int T;

int gcd(int a,int b){
  if(a<b)swap(a,b);
  return (b==0)?a:gcd(b,a%b);
}

void process(string s){
  istringstream iss(s);
  vector<int> v;
  int k;
  while(iss>>k){
    v.push_back(k);
  }
  int maximum=-1;
  for(int i=0;i<v.size()-1;i++){
    for(int j=i+1;j<v.size();j++){
      maximum=max(maximum,gcd(v[i],v[j]));
    }
  }
  cout<<maximum<<endl;
}
int main(){
  cin>>T;
  getline(cin,s);
  for(int t=0;t<T;t++){
    getline(cin,s);
    process(s);
  }
  return 0;
}
