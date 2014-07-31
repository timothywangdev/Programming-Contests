#include <iostream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
map<LL,LL> seq;
vector<LL> data;
LL fib[51];

LL T,N,tmp;
string s;
struct pkg{
  char ch;
  LL pos;
  pkg(char ch,LL pos):ch(ch),pos(pos){}
};

bool mysort(const pkg &a,const pkg &b){
  return a.pos<b.pos;
}
string decode(string cipher){
  vector<pkg> de;
  bool used[51];
  memset(used,false,sizeof(used));
  LL maximum=0;
  for(int i=0;i<data.size();i++){
    de.push_back(pkg(cipher[i],seq[data[i]]));
    used[seq[data[i]]]=true;
    maximum=max(maximum,data[i]);
  }
  for(int i=1;fib[i]<=maximum;i++){
    if(!used[i]){
      de.push_back(pkg(' ',i));
    }
  }
    sort(de.begin(),de.end(),mysort);
    string rv;
    for(int i=0;i<de.size();i++){
      rv=rv+de[i].ch;
    }
    return rv;
}
int main(){
  fib[1]=1;
  fib[2]=2;
  seq[1]=1;
  seq[2]=2;
  for(int i=3;i<=50;i++){
    fib[i]=fib[i-1]+fib[i-2];
    seq[fib[i]]=i;
  }
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>N;
    data.clear();
    for(int i=0;i<N;i++){
      cin>>tmp;
      data.push_back(tmp);
    }
    getline(cin,s);
    getline(cin,s);
    string cipher="";
    for(int i=0;i<s.size();i++){
      if('A'<=s[i]&&s[i]<='Z'){
	cipher=cipher+s[i];
      }
    }
    cout<<decode(cipher)<<endl;
  }
  return 0;
}
