#include <bits/stdc++.h>

using namespace std;
long long a,b,c;
int main(){
  cin>>a>>b>>c;
  c-=abs(a)+abs(b);
  if(c%2==0&&c>=0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
