#include <iostream>
#include <cmath>
#include <algorithm>
#define PI 3.14159265
#define INF 1.7e+308
using namespace std;

int a,b,v,A,s;
double vx,vy,T,tx,ty,x,y,tc,ax,ay;
int cx,cy;
int main(){
  while(cin>>a>>b>>v>>A>>s){
    if(!a&&!b&&!v&&!A&&!s){
      break;
    }
    cx=cy=0;
    T=0.0;
    if(A!=90){
      vx=(double)v*cos((double)A*PI/180.0);
    }
    else{
      vx=0.0;
    }
    if(A!=0){
      vy=(double)v*sin((double)A*PI/180.0);
    }
    else{
      vy=0.0;
    }
    ax=-vx/s;
    ay=-vy/s;
    x=(double)a/2;
    y=(double)b/2;
    while(true){
      double dx=(vx>=0)?a-x:x;
      double dy=(vy>=0)?b-y:y;
      double TR=s-T;
      double maxD;
      if(ax!=0.0){
	double vxx=abs(vx);
	double axx=abs(ax);
	maxD=vxx*TR+0.5*(-axx)*TR*TR;
	if(maxD<dx){
	  tx=INF;
	}
	else{
	  tx=(-vxx+sqrt(vxx*vxx+2*(-axx)*dx))/(-axx);
	}
      }
      else{
	tx=INF;
      }
      if(ay!=0.0){
	double vyy=abs(vy);
	double ayy=abs(ay);
	maxD=vyy*TR+0.5*(-ayy)*TR*TR;
	if(maxD<dy){
	  ty=INF;
	}
	else{
	  ty=(-vyy+sqrt(vyy*vyy+2*(-ayy)*dy))/(-ayy);
	}
      }
      else{
	ty=INF;
      }
      tc=min(tx,ty);
      T+=tc;
      if(T<=(double)s){
	if(tx<=ty){
	  x=(vx>=0)?a:0;
	}
	else{
	  if(vx<0){
	    x-=tc*abs(vx)+0.5*(0-abs(ax))*tc*tc;
	  }
	  else{
	    x+=tc*abs(vx)+0.5*(0-abs(ax))*tc*tc;
	  }
	}
	if(ty<=tx){
	  y=(vy>=0)?b:0;
	}
	else{
	  if(vy<0){
	    y-=tc*abs(vy)+0.5*(0-abs(ay))*tc*tc;
	  }
	  else{
	    y+=tc*abs(vy)+0.5*(0-abs(ay))*tc*tc;
	  }
	}
	if(x>a)x=a;
	if(x<0)x=0;
	if(y>b)y=b;
	if(y<0)y=0;
	cy+=(tx<=ty);
	cx+=(tx>=ty);
	if(vx>0)vx-=tc*abs(ax);else vx+=tc*abs(ax);
	if(vy>0)vy-=tc*abs(ay);else vy+=tc*abs(ay);
	ax=(tx<=ty)?-ax:ax;
	ay=(ty<=tx)?-ay:ay;
	vx=(tx<=ty)?-vx:vx;
	vy=(ty<=tx)?-vy:vy;
      }
      else{
	break;
      }
    }
    cout<<cy<<" "<<cx<<endl;
  }
  return 0;
}
