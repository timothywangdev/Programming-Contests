#include <iostream>
#include <string>

using namespace std;
typedef long long LL;

LL str_mod(string s,LL m){
  LL rv=0;
  for(LL i=0;i<s.size();i++){
    rv=(rv*(10%m)+(s[i]-'0')%m)%m;
  }
  return rv;
}

LL T,N,tmp;
string s;
int main(){
  cin>>T;
  getline(cin,s);
  for(int t=0;t<T;t++){
    getline(cin,s);
    cin>>N;
    bool rv=true;
    for(int i=0;i<N;i++){
      cin>>tmp;
      if(str_mod(s,tmp)!=0){
	rv=false;
      }
    }
    if(!rv){
      cout<<s<<" - Simple."<<endl;
    }
    else{
      cout<<s<<" - Wonderful."<<endl;
    }
    getline(cin,s);
  }
  return 0;
}
