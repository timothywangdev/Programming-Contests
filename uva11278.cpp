#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char,char> m;
string s[2]={"`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>\?",
"`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP\?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\""
};

string ss;
int main(){
  for(int i=0;i<s[0].size();i++){
    m[s[0][i]]=s[1][i];
  }
  m[' ']=' ';
  while(getline(cin,ss)){
    for(int i=0;i<ss.size();i++){
      cout<<m[ss[i]];
    }
    cout<<endl;
  }
  return 0;
}
