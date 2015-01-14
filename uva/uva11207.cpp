#include <iostream>
#include <algorithm>
using namespace std;

int N;
double w,h;
int main(){
  while(cin>>N){
    if(!N)break;
    double maximum=0;
    int maxIndex=0;
    for(int i=0;i<N;i++){
      cin>>w>>h;
      double m=max(w,h);
      double n=min(w,h);
      double t=0;
      t=max(t,n/2);
      if(m/n>=4.0){
	t=max(t,n);
      }
      else{
	t=max(t,m/4.0);
      }
      if(t>maximum){
	maximum=t;
	maxIndex=i+1;
      }
    }
    cout<<maxIndex<<endl;
  }
  return 0;
}
