#include <bits/stdc++.h>

using namespace std;
string s;
int main(){
  cin>>s;
  for(int i=0;i<s.length();i++){
    int k=(int)(s[i]-'0');
    if(k>=5){
      if(i==0&&k==9)continue;
      s[i]=(char)('0'+9-k);
    }
  }
  cout<<s<<endl;
  return 0;
}
