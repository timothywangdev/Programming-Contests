#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1.0)
using namespace std;

int N,D,L;

double area_of_ellipse(double a, double b){
  return PI*a*b;
}

int main(){
  cin>>N;
  for(int t=0;t<N;t++){
    cin>>D>>L;
    double a=(double)L/2;
    double tt=(double)D/2;
    double b=sqrt(a*a-tt*tt);
    cout<<fixed<<setprecision(3)<<PI*a*b<<endl;
  }
  return 0;
}
