#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1.0)
using namespace std;

double deg_to_rad(double theta){
  return theta*(PI/180.0);
}
double l,w,h,theta;
int main(){
  while(cin>>l>>w>>h>>theta){
    double s=(h/tan(deg_to_rad(theta))<l)?0.5*w*h*(h/tan(deg_to_rad(theta))):w*(l*h-0.5*l*l*tan(deg_to_rad(theta)));
  cout<<fixed<<setprecision(3)<<s<<" mL"<<endl;
  }
  return 0;
}
