#include <iostream>
#include <string.h>
#include <iomanip>
#define EPS 1e-9
using namespace std;
typedef long long LL;
bool flooded[30][30];
LL r[30][30];
LL N,M;
double v;

LL getLowest(LL &counter){
  LL lowest=2147483647;
  for(LL i=0;i<N;i++){
    for(LL j=0;j<M;j++){
      if(r[i][j]<lowest){
	lowest=r[i][j];
	counter=1;
      }
      else if(r[i][j]==lowest){
	counter++;
      }
    }
  }
  return lowest;
}
LL getSecondLowest(LL lowest){
  LL secondlowest=2147483647;
  for(LL i=0;i<N;i++){
    for(LL j=0;j<M;j++){
      if(r[i][j]<secondlowest&&r[i][j]>lowest){
	secondlowest=r[i][j];
      }
    }
  }
  return secondlowest;
}

void raise(LL a, LL b){
  for(LL i=0;i<N;i++){
    for(LL j=0;j<M;j++){
      if(r[i][j]==a){
	r[i][j]=b;
	flooded[i][j]=true;
      }
    }
  }
}
int region=0;
int main(){
  while(cin>>N>>M){
    if(!N&&!M)break;
    region++;
    for(LL i=0;i<N;i++){
      for(LL j=0;j<M;j++){
	cin>>r[i][j];
      }
    }
    memset(flooded,false,sizeof(flooded));
    cin>>v;
    double rv;
    while(true){
      LL num;
      LL lowest=getLowest(num);
      LL secondLowest=getSecondLowest(lowest);
      LL vv=num*(secondLowest-lowest)*100;
      if((v-(double)vv)>EPS){
	v-=(double)vv;
	raise(lowest,secondLowest);
      }
      else{   
	raise(lowest,lowest+1);
	double ele=v/(double)(num*100);
	rv=ele+(double)lowest;
	break;
      }					
    }
    LL f=0;
    for(LL i=0;i<N;i++){
      for(LL j=0;j<M;j++){
	if(flooded[i][j]){
	  f++;
	}
      }
    }
    cout<<"Region "<<region<<endl;
    cout<<"Water level is "<<fixed<<setprecision(2)<<rv<<" meters."<<endl;
    cout<<fixed<<setprecision(2)<<(double)(100*f)/(N*M)<<" percent of the region is under water."<<endl<<endl;
  }
  return 0;
}
