#include <iostream>
#include <cmath>

using namespace std;

long long a,b,d;
double c;
int main(){
  while(cin>>a){
    if(!a)break;
    b=(a-1940)/10;
    c=log2((double)1);
    for(d=1;;d++){
      c+=log2((double)d);
      if(c>pow(2,(double)b)){
	cout<<d-1<<endl;
	break;
      }
    }
  }
  return 0;
}
