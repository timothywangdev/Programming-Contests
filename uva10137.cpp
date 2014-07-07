#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

long long n;
double v[1000];
double sum;

int main(){
  while(cin>>n){
    if(!n)break;
    sum=0.0;
    for(long long i=0;i<n;i++){
      cin>>v[i];
      sum+=v[i];
    }
    double avg=sum/(double)n;
    double neg=0.0,pos=0.0;
    for(long long i=0;i<n;i++){
      double diff=(double)(long)((v[i]-avg)*100.0)/100.0;
      if(diff>=0){
	pos+=diff;
      }
      else{
	neg+=diff;
      }
    }
    double resp = (-neg > pos) ? -neg : pos;
    resp = (resp<0)?-resp:resp;
    printf("$%.2lf\n",resp);
  }
  return 0;
}
