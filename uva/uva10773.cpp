#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int T;
double d,v,u;
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>d>>v>>u;
    cout<<"Case "<<t+1<<": ";
    if(u<=v||u==0||v==0){
      cout<<"can't determine"<<endl;
      continue;
    }
    double t1=d/u;
    double t2=d/sqrt(u*u-v*v);
    cout<<fixed<<setprecision(3)<<abs(t1-t2)<<endl;
  }
  return 0;
}
