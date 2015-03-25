#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

LL a,b,c,d;
int main(){
  cin>>a>>b>>c>>d;
  LL aa=max((3*a)/10,a-((a*c)/250));
  LL bb=max((3*b)/10,b-((b*d)/250));
  if(aa>bb){
    cout<<"Misha"<<endl;
  }
  else if(aa<bb){
    cout<<"Vasya"<<endl;
  }
  else{
    cout<<"Tie"<<endl;
  }
  return 0;
}
