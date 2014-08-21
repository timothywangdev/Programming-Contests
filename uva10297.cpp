#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define PI acos(-1.0)
long long DD,VV;
double D,V;
int main(){
  while(cin>>DD>>VV){
    if(!DD&&!VV)break;
    D=(double)DD;
    V=(double)VV;
    cout<<fixed<<setprecision(3)<<pow(D*D*D-(6*V)/PI,1/(double)3)<<endl;
  }
  return 0;
}
