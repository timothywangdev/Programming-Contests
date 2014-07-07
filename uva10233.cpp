#include <iostream>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef pair<double,double> dd;
double D1=1/((double)2*sqrt((double)3));
double D2=(sqrt((double)3)/2)-D1;
double DD=sqrt((double)3)/2;
double W=1/(double)3;
double WW=1/(double)12;
pair<double,double> getCor(long long n){
  long long N=n+1;
  long long k=floor(sqrt(N));
  long long offset;
  if(k*k==N){
    offset=2*k-1;
  }
  else{
    offset=N-k*k;
    k++;
  }
  bool up=false;
  if(k%2==0&&n%2==1)up=true;
  if(k%2==1&&n%2==0)up=true;
  double D=(up)?D2:D1;
  return make_pair((offset-k)*(W-WW)*2,(k-1)*DD+D);
}
double getDist(dd aa,dd bb){
  double d1=aa.first-bb.first;
  double d2=aa.second-bb.second;
  return sqrt(d1*d1+d2*d2);
}
long long a,b;
int main(){
  while(cin>>a>>b){
    dd aa=getCor(a);
    dd bb=getCor(b);
    cout<<fixed<<setprecision(3)<<getDist(aa,bb)<<endl;
  }
  return 0;
}
