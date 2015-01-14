#include <iostream>
#include <string.h>
#include <string>
#include <map>
using namespace std;

int N;
string s;
map<string,int> counter;
int main(){
  while(cin>>N){
    cin>>s;
    counter.clear();
    for(int i=0;i<s.length()-N+1;i++){
      string t=s.substr(i,N);
      map<string,int>::iterator it=counter.find(t);
      if(it==counter.end()){
	counter[t]=1;
      }
      else{
	it->second++;
      }
    }
    int maximum=0;
    string rv="";
    for(map<string,int>::iterator it=counter.begin();it!=counter.end();it++){
      if(it->second>maximum){
	maximum=it->second;
	rv=it->first;
      }
    }
    cout<<rv<<endl;
  }
  return 0;
}
