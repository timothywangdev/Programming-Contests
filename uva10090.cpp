#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
LL x,y,d,c1,c2,n1,n2,n,mx,my;
void extendedEuclid(LL a,LL b){
  if(b==0){
    x=1;
    y=0;
    d=a;
    return;
  }
  extendedEuclid(b,a%b);
  LL x1=y;
  LL y1=x-(a/b)*y;
  x=x1;
  y=y1;
}
int main(){
  while(cin>>n){
    if(!n)break;
    cin>>c1>>n1>>c2>>n2;
    extendedEuclid(n1,n2);
    x*=(n/d);
    y*=(n/d);
    LL lower=floor(-(double)x*((double)d/n2))-1;
    LL upper=ceil((double)y*((double)d/n1))+1;
    LL minimum=-1;
    LL step;
    LL mx=-1,my=-1;
    if(n%d==0){
      LL hehe=(n2/d)*c1-(n1/d)*c2;
      if(hehe<0){
	swap(lower,upper);
	step=-1;
      }
      else{
	step=1;
      }
      for(LL i=lower;i!=upper;i+=step){
	LL xx=x+(n2/d)*i;
	LL yy=y-(n1/d)*i;
	if(xx<0||yy<0)continue;
	if(xx*n1+yy*n2!=n)continue;
	if(xx*c1+yy*c2<=minimum||minimum==-1){
	  minimum=xx*c1+yy*c2;
	  mx=xx;
	  my=yy;
	}
	break;
      }
    }
    if(mx==-1){
      cout<<"failed"<<endl;
    }
    else{
      cout<<mx<<" "<<my<<endl;
    }
  }
  return 0;
}
