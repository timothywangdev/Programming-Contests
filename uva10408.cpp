#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

class Frac{
public:
  int up;
  int down;
  Frac(int up,int down):up(up),down(down){}
};

bool operator<(const Frac &a,const Frac &b){
  int aa=a.up*b.down;
  int bb=b.up*a.down;
  return aa<bb;
}
int n,k;
int main(){
  while(cin>>n>>k){
    vector<Frac> v;
    v.push_back(Frac(1,1));
    for(int i=2;i<=n;i++){
      for(int j=1;j<i;j++){
	if(gcd(i,j)==1){
	  v.push_back(Frac(j,i));
	}
      }
    }
    sort(v.begin(),v.end());
    cout<<v[k-1].up<<"/"<<v[k-1].down<<endl;
  }
  return 0;
}
