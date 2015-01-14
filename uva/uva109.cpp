//#define DEBUG
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "string.h"
#define MAXIMUM 2000000000;
using namespace std;

#ifdef DEBUG
ifstream fin("uva109.in");
ofstream fout("uva109.out");
#endif

struct P{
	int x;
	int y;
};

P sites[20][100];
P HCsites[20][101];
P p0;
bool exist[20];
int N[21];
int HCN[20];

int K=-1,x,y;



class Stack{
    int k;
	int n;
public:
	void initStack(int k){
		Stack::k=k;
		n=0;
	}
	void push(int i){
		HCsites[k][n]=sites[k][i];
		n++;
	}
	P top(){
		return HCsites[k][n-1];
	}
	P nextToTop(){
		if(n-2<0)
		  return HCsites[k][n-1];
		else
		  return HCsites[k][n-2];
	}
	void pop(){
		n--;
	}
	void endStack(){
		HCN[k]=n;
	}
};

Stack s;

int max(int a,int b){
	return (a>=b)?a:b;
}
int min(int a,int b){
	return (a>=b)?b:a;
}
int ccw(const P &p1,const P &p2,const P &p3){
	if(p1.x==p2.x&&p1.y==p2.y)
		return 1;
	return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
int distSqr(const P &p1,const P &p2){
	return (p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y);
}
void swap(P &p1,P &p2){
	P tmp=p1;
	p1=p2;
	p2=tmp;
}
bool comp(const P &p1,const P &p2){
	int orientation=ccw(p0,p1,p2);
	if(orientation>0)
		return true;
	if(orientation==0)
		if(distSqr(p0,p1)<distSqr(p0,p2))
			return true;
	return false;
}
void findExtremeP(int k){
	P extreme;
	extreme.x=MAXIMUM;
	extreme.y=MAXIMUM;

	int theExtreme=-1;

	for(int i=0;i<N[k];i++)
		if(sites[k][i].y<extreme.y){
			extreme.y=sites[k][i].y;
			extreme.x=sites[k][i].x;
			theExtreme=i;
		}
		else if(sites[k][i].y==extreme.y&&sites[k][i].x<extreme.x){
			extreme.x=sites[k][i].x;
			theExtreme=i;
		}
		swap(sites[k][0],sites[k][theExtreme]);
}



void grahamScan(int k){
	p0=sites[k][0];
	sort(sites[k]+1,sites[k]+N[k],comp);
	s.initStack(k);
	s.push(0);
	s.push(1);
	s.push(2);
	for(int i=3;i<N[k];i++){
		while(ccw(s.nextToTop(),s.top(),sites[k][i])<=0){
			s.pop();
		}
		s.push(i);
   }
   s.endStack();
}

bool onLine(P &target,P &p1, P &p2){
	int maxX=max(p1.x,p2.x);
	int minX=min(p1.x,p2.x);
	int maxY=max(p1.y,p2.y);
	int minY=min(p1.y,p2.y);
	return (minX<=target.x)&&(target.x<=maxX)&&
		   (minY<=target.y)&&(target.y<=maxY);
}
bool inSite(int k,int x,int y){
	P missile;
	missile.x=x;
	missile.y=y;
	int rv;
	for(int i=0;i<HCN[k];i++){
		rv=ccw(missile,HCsites[k][i],HCsites[k][(i+1)%HCN[k]]);
		if(rv<=0)
			return false;
		/*
		if(rv==0){
			if(onLine(missile,HCsites[k][i],HCsites[k][(i+1)%HCN[k]]))
				return true;
			else
				return false;
		}
		*/
	}
	return true;
}
void calMissile(int x,int y){
	for(int i=0;i<K;i++)
		if(inSite(i,x,y)){
			exist[i]=false;
			return;
		}
}
double getArea(int k){
	int rv=0;
	double rv2;
	HCsites[k][HCN[k]]=HCsites[k][0];
	for(int i=1;i<=HCN[k];i++)
		rv+=HCsites[k][i-1].x*HCsites[k][i].y-HCsites[k][i].x*HCsites[k][i-1].y;
	rv2=0.5*(double)rv;
	return rv2;
}
int main(){
	do{
		K++;
        #ifdef DEBUG
		fin>>N[K];
        #else
        cin>>N[K];
        #endif
		if(N[K]==-1){
			break;
		}
		for(int i=0;i<N[K];i++){
			#ifdef DEBUG
			fin>>sites[K][i].x>>sites[K][i].y;
			#else
			cin>>sites[K][i].x>>sites[K][i].y;
			#endif
		}
		findExtremeP(K);
		grahamScan(K);		
	}while(N[K]!=-1);

	memset(exist,true,sizeof(exist));
	#ifdef DEBUG
	while(fin>>x>>y){
	#else
	while(cin>>x>>y){
	#endif
		calMissile(x,y);
	}

	double totalLostArea=0.0;
	for(int i=0;i<K;i++)
		if(!exist[i])
			totalLostArea+=getArea(i);
	#ifdef DEBUG
	fout.setf(ios::fixed, ios::floatfield); 
    fout.precision(2); 
	fout<<totalLostArea<<endl;
	#else
	cout.setf(ios::fixed, ios::floatfield); 
    cout.precision(2); 
	cout<<totalLostArea<<endl;
	#endif
	return 0;
}