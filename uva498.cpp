#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<long long> c,v;
string s;
void getV(string s,vector<long long> &vv){
  istringstream iss(s);
  long long tmp;
  while(iss>>tmp){
    vv.push_back(tmp);
  }
}
int main(){
  while(getline(cin,s)){
    c.clear();
    v.clear();
    getV(s,c);
    getline(cin,s);
    getV(s,v);
    for(int j=0;j<v.size();j++){
      long long curr=1;
      long long sum=0;
      for(int i=c.size()-1;i>=0;i--){
	if(i==c.size()-1){
	  curr=1;
	}
	else{
	  curr*=v[j];
	}
	sum+=curr*c[i];
      }
      if(j>0)cout<<" ";
      cout<<sum;
    }
    cout<<endl;
  }
  return 0;
}
