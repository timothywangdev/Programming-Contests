#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
typedef vector<LL> vl;
vl v;
LL n;
LL gcd(LL a,LL b){
  return (b==0)?a:gcd(b,a%b);
}
LL lcm(LL a,LL b){
  return a*(b/gcd(a,b));
}
vl getDivisors(LL n){
  vl rv;
  LL m=sqrt(n);
  for(LL i=1;i<=m;i++){
     if(n%i==0){
	rv.push_back(i);
	if(n/i!=i){
	  rv.push_back(n/i);
	}
     }
  }
  return rv;
}
int main(){
  while(cin>>n){
    if(!n)break;
    v=getDivisors(n);
    LL sum=0;
    for(LL i=0;i<v.size();i++){
      for(LL j=i;j<v.size();j++){
	if(lcm(v[i],v[j])==n){
	  sum++;
	}
      }
    }
    cout<<n<<" "<<sum<<endl;
  }
  return 0;
}
