#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

long long  mm[4]={2,3,5,7};
bool check(int n){
  while(true){
    bool found=false;
    for(int i=0;i<4;i++){
      if(n%mm[i]==0){
	found=true;
	n/=mm[i];
	break;
      }
    }
    if(n==1){
      return true;
    }
    if(!found){
      return false;
    }
  }
}
string getStr(int N){
  ostringstream oss;
  oss<<N;
  string s=oss.str();
    if(s[s.size()-1]=='1'){
      if(s.size()>=2&&s[s.size()-2]=='1')return "th";
      return "st";
    }
    else if(s[s.size()-1]=='2'){
      if(s.size()>=2&&s[s.size()-2]=='1')return "th";
      return "nd";
    }
    else if(s[s.size()-1]=='3'){
      if(s.size()>=2&&s[s.size()-2]=='1')return "th";
      return "rd";
    }
    return "th";
}
int N;
vector<long long> seq;
map<long long,bool> exist;
bool find_num(int n){
  if(exist.find(n)==exist.end()){
    exist[n]=true;
    return false;
  }
  else{
    return true;
  }
}
int main(){
  /*
  ofstream fout("data.out");
  seq.push_back(1);
  for(int i=2;i<=2000000000;i++){
    // cout<<"checking "<<i<<endl;
    if(check(i)){
      cout<<"passed "<<i<<endl;
      seq.push_back(i);
    }
  }
  fout<<"{"<<endl;
  for(int i=0;i<seq.size();i++){
    fout<<seq[i];
    if(i!=seq.size()-1){
      fout<<",";
    }
  }
  fout<<"}"<<endl;
  */
  seq.push_back(1);
 vector<int> tmp;
  while(true){
    if(seq.size()>=6000){
      cout<<"error"<<endl;
      break;
    }
    for(int k=0;k<4;k++){
      for(int i=0;i<seq.size();i++){
	if(seq[i]*mm[k]<=2000000000){
	  if(!find_num(seq[i]*mm[k])){
	    tmp.push_back(seq[i]*mm[k]);
	  }
	}
      }
    }
    if(tmp.size()==0)break;
    for(int i=0;i<tmp.size();i++){
      seq.push_back(tmp[i]);
    }
    tmp.clear();
  }
  sort(seq.begin(),seq.end());
  while(cin>>N){
    if(!N) break;
    cout<<"The "<<N<<getStr(N)<<" humble number is "<<seq[N-1]<<"."<<endl;
  }
  
  return 0;
}
