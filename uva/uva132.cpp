//#define DEBUG
#include <iostream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include "math.h"
#define MAXIMUM 2147483647
using namespace std;
#ifdef DEBUG
ifstream fin("uva132.in");
ofstream fout("uva132.out");
#endif

struct Vector{
   int index;
   int x;
   int y;
};

Vector vs[2000];
Vector central;
int N;

class Stack{
public:
    int n;
    Vector s[2000];

	Stack():n(0){}
	void clear(){n=0;}
	void push(Vector v){
        s[n]=v;
		n++;
	}
	void pop(){
        n--;
	}
	Vector top(){
       return s[n-1];
	}
	Vector nextTop(){
		if(n-2<0)
			return s[n-1];
		else 
		    return s[n-2];
	}
};

Stack s;

bool cmp(Vector a, Vector b){
	if(a.y == b.y)  return a.x < b.x;
	return a.y < b.y;
}


bool ascend(Vector v1,Vector v2){
    return v1.index<v2.index;
}
int ccw(const Vector &p1,const Vector &p2,const Vector &p3){
	//if(p1.x==p2.x&&p1.y==p2.y)
	//	return 1;
	return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
int dist(const Vector &v1,const Vector &v2){
    return (v1.x-v2.x)*(v1.x-v2.x)+(v1.y-v2.y)*(v1.y-v2.y);
}
bool comp(const Vector &v1,const Vector &v2){
	  int rv=ccw(vs[0],v1,v2);
      if(rv>0)
		  return true;
	  if(rv==0)
		   if(dist(vs[0],v1)<dist(vs[0],v2))
		      return true;
	  return false;
}
void grahamScan(){
	int miny=MAXIMUM,minx=MAXIMUM,minIndex;
	for(int i=0;i<N;i++){
		if(vs[i].y<miny){
           miny=vs[i].y;
		   minx=vs[i].x;
		   minIndex=i;
		}
		else if(vs[i].y==miny&&vs[i].x<minx){
           minx=vs[i].x;
		   minIndex=i;
		}
	}
	swap(vs[0],vs[minIndex]);
	sort(vs+1,vs+N,comp);
	s.push(vs[0]);
	//s.push(vs[1]);
	//s.push(vs[2]);
	for(int i=1;i<N;i++){
		while(s.n>=2&&ccw(s.nextTop(),s.top(),vs[i])<=0){
			s.pop();
		}
		s.push(vs[i]);
	}
}

bool between(Vector &p1,Vector &p2,Vector &pp){
   if( ((double)((pp.x-p1.x)*(p2.x-p1.x)+(pp.y-p1.y)*(p2.y-p1.y)) / fabs(sqrt((double)dist(pp,p1))*sqrt((double)dist(p2,p1)))) > 0)
	   return true;
   return false;
}
int main(){
	string name;
	#ifdef DEBUG
	while(fin>>name){
		if(name=="#")
			break;
		 fin>>central.x>>central.y;
    #else
	while(cin>>name){
		if(name=="#")
			break;
		 //cin>>central.x>>central.y;
		 scanf("%d %d",&central.x,&central.y);
    #endif
		 s.clear();
		 N=0;
		 #ifdef DEBUG
		 while(fin>>vs[N].x>>vs[N].y){
         #else
         while(scanf("%d %d",&vs[N].x,&vs[N].y)){
		 #endif
			 if(vs[N].x==vs[N].y&&vs[N].x==0)
				 break;
			 vs[N].index=N+1;
			 N++;
		 }
		 grahamScan();
		 //sort(s.s,s.s+s.n,ascend);
		 //int found=false;
		 int rv=MAXIMUM;
		 for(int i=0;i<s.n;i++)
			 if(ccw(s.s[i],s.s[(i+1)%s.n],central)>0&&
			    between(s.s[i],s.s[(i+1)%s.n],central)&&
				between(s.s[(i+1)%s.n],s.s[i],central)){
              //found=true;
              rv=min(rv,max(s.s[i].index,s.s[(i+1)%s.n].index));
			 }
		 #ifdef DEBUG
         fout<<name<<" "<<rv<<endl;
		 #else
		 cout<<name<<" "<<rv<<endl;
		 #endif

	}
}