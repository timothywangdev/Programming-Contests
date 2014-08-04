#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<string> v;
void process(){
  for(int i=0;i<v.size();i++){
    for(int j=0;j<v.size();j++){
      if(i!=j){
	if(0==v[j].find(v[i])){
	  cout<<"not immediately decodable"<<endl;
	  return;
	}
      }
    }
  }
  cout<<"immediately decodable"<<endl;
}
int counter=1;
int main(){
  while(cin>>s){
    if(s[0]=='9'){
      cout<<"Set "<<counter<<" is ";
      process();
      v.clear();
      counter++;
    }
    v.push_back(s);
  }
  return 0;
}
