#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(b);i>=(a);i--)
#define F(i,n) for(int i=0;i<(n);i++)
#define FR(i,n) for(int i=(n)-1;i>=0;i--)
#define R(a,i,b) (a<=i&&i<=b)
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef long long LL;

int n;
double a[200000];

double cal(double x, int sign){
  double sum=0,rv=0;
  F(i,n){
    sum+=sign*(a[i]-x);
    rv=max(sum,rv);
    if(sum<0){
      sum=0;
    }
  }
  return rv;
}
int main(){
  cin>>n;
  F(i,n){
    cin>>a[i];
  }
  double l=*min_element(a,a+n);
  double r=*max_element(a,a+n);
  double m,A,B,rv;
  F(i,40){
    m=(l+r)/2;
    A=cal(m,1);
    B=cal(m,-1);
    rv=max(A,B);
    if(A>=B){
      l=m;
    }
    else{
      r=m;
    }
  }
  cout<<fixed<<setprecision(7)<<rv<<endl;
   return 0;
}
