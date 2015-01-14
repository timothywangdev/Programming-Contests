//#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <cstdio>
using namespace std;

int N,T;
double p[5005];
int t[5005];
double cal[2][5005];
//float _p_pow[5010][5010];

int pp,tt;

int main(){
  //cin>>N>>T;
  scanf("%d %d",&N,&T);
  for(int i=1;i<=N;i++){
    //cin>>pp>>t[i];
    scanf("%d",&pp);
    scanf("%d",&t[i]);
    p[i]=(double)pp/100;
  }
  cal[0][0]=1.0;
  double sum=0.0,k;
  int a,b;
  for(int i=1;i<=N;i++){
    for(int j=i;j<=T;j++){
      a=i&1;
      b=1-a;
      cal[a][j]=cal[b][j-1]*p[i];
      if(j-1>=i){
	cal[a][j]+=cal[a][j-1]*(1-p[i]);
      }
      k=pow(1-p[i],t[i]);
      if(k<1e-12)k=0.0;
      if(j-t[i]-1>=0&&j-t[i]-1>=i-1){
	cal[a][j]-=cal[b][j-t[i]-1]*k;
      }
      if(j-t[i]>=0&&j-t[i]>=i-1){
	cal[a][j]+=cal[b][j-t[i]]*k;
      }
      if(i==N){
	k= 1.0;
      }
      else{
	if(j+t[i+1]<=T){
	  k= 0.0;
	}
	else{
	  //return _p_pow[i+1][T-j];
	  k= pow(1-p[i+1],(double)T-j);
	}
      }
      if(k<1e-12)k=0.0;
      if(cal[a][j]<1e-12)cal[a][j]=0.0;
      else sum+=cal[a][j]*k*i;
      if(sum<1e-12)sum=0.0;
    }
  }
  printf("%.9lf\n", sum);
  return 0;
}
