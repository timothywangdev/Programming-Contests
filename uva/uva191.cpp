#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#ifdef DEBUG
ifstream cin("uva191.in");
ofstream cout("uva191.out");
#endif
struct P{
   int x;
   int y;
};
P start,end,lt,rb;
int dir(P pi,P pj,P pk){
    P v1,v2;
	v1.x=pk.x-pi.x;
	v1.y=pk.y-pi.y;
	v2.x=pk.x-pj.x;
	v2.y=pk.y-pj.y;
	return v1.x*v2.y-v2.x*v1.y;
}
bool onSegment(P pi,P pj,P pk){
    if(min(pi.x,pj.x)<=pk.x&&pk.x<=max(pi.x,pj.x)&&
	   min(pi.y,pj.y)<=pk.y&&pk.y<=max(pi.y,pj.y))
	   return true;
	return false;
}
bool intersect(P p1,P p2,P p3,P p4){
	

    int d1=dir(p3,p4,p1);
	int d2=dir(p3,p4,p2);
	int d3=dir(p1,p2,p3);
	int d4=dir(p1,p2,p4);
	if(((d1<0&&d2>0)||(d1>0&&d2<0))&&
	   ((d3<0&&d4>0)||(d3>0&&d4<0)))
	   return true;
	else if(d1==0&&onSegment(p3,p4,p1))
		return true;
	else if(d2==0&&onSegment(p3,p4,p2))
		return true;
	else if(d3==0&&onSegment(p1,p2,p3))
		return true;
	else if(d4==0&&onSegment(p1,p2,p4))
		return true;
	else
		return false;
}
void process(){
	P lb,rt;
	lb.x=lt.x;
	lb.y=rb.y;
	rt.x=rb.x;
	rt.y=lt.y;
	if((lt.x<=start.x&&start.x<=rb.x&&
	   rb.y<=start.y&&start.y<=lt.y)||
	   (lt.x<=end.x&&end.x<=rb.x&&
	   rb.y<=end.y&&end.y<=lt.y))
	{
       cout<<"T"<<endl;
	   return;
	}
    if(intersect(start,end,lt,rt)||
       intersect(start,end,rt,rb)||
	   intersect(start,end,lb,rb)||
	   intersect(start,end,lt,lb))
	   cout<<"T"<<endl;
	else
	   cout<<"F"<<endl;
}
int N;
int main(){
	cin>>N;
	P t1,t2;
	for(int i=0;i<N;i++){
	    cin>>start.x>>start.y>>end.x>>end.y>>t1.x>>t1.y>>t2.x>>t2.y;
		lt.x=min(t1.x,t2.x);
		lt.y=max(t1.y,t2.y);
		rb.x=max(t1.x,t2.x);
		rb.y=min(t1.y,t2.y);
        process();
	}
	return 0;
}