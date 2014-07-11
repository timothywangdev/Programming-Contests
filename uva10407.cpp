#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int t,g,a,last;
int gcd(int a,int b){
  if(a<b)swap(a,b);
  return b==0?a:gcd(b,a%b);
}
vector<int> v;
int main(){
  while(cin>>t){
    if(t==0)break;
    last=-1;
    a=t;
    while(cin>>t){
      if(t==0)break;
      if(last==-1){
	 last=abs(t-a);
	 g=last;
      }
      else{
	//cout<<last<<" "<<abs(t-a)<<endl;
	 g=gcd(gcd(last,abs(t-a)),g);
	 // cout<<"gcd: "<<g<<endl;
	 last=abs(t-a);
     }
    }
    cout<<g<<endl;
  }
  return 0;
}
