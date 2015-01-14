#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "string.h"
using namespace std;
//#decine DEBUG
#ifdef DEBUG
ifstream cin("uva177.in");
ofstream cout("uva177.out");
#endif
int n,minX,maxY,maxx[250],maxy;
char display[250][250];
bool specialx,specialy;
struct p{
	int x;
	int y;
};
struct line{
	p p1;
	p p2;
};
struct O{
	int y;
	int x;
	bool horizontal;
};
p ori={0,0};
vector<line> curve,copyCurve,curves[13];
vector<O> output;
p rotate(p relative,p point){
	point.x-=relative.x;
	point.y-=relative.y;
	int ox=point.x,oy=point.y;
	point.x=oy;
	point.y=-ox;
	point.x+=relative.x;
	point.y+=relative.y;
	return point;
}
void rotateAndCopy(p &foldPoint){
	for(unsigned int i=0;i<curve.size();i++){
		line l={rotate(foldPoint,curve[i].p1),rotate(foldPoint,curve[i].p2)};
		copyCurve.push_back(l);
	}
}
void reverse(){
	for(unsigned int i=0;i<copyCurve.size()/2;i++){
		swap(copyCurve[i],copyCurve[copyCurve.size()-i-1]);
	}
}
void concatenate(){
	for(unsigned int i=0;i<copyCurve.size();i++)
		curve.push_back(copyCurve[i]);
}
void getNextFoldPoint(p &foldPoint){
	foldPoint=rotate(foldPoint,ori);
}
void store(int index){
	curves[index-1]=curve;
}
void preProcess(){
	curve.clear();
	p foldPoint={1,0};
	line startingLine={{0,0},{1,0}};
	curve.push_back(startingLine);
	for(int i=1;i<=13;i++){
		copyCurve.clear();
		rotateAndCopy(foldPoint);
		reverse();
		concatenate();
		getNextFoldPoint(foldPoint);
		store(i);
	}
}
bool H(line &l){
	return l.p1.y==l.p2.y;
}
void shift(){
	output.clear();
	for(unsigned int i=0;i<curves[n-1].size();i++){
		O tmp;
		int dxMin=min(curves[n-1][i].p1.x,curves[n-1][i].p2.x)-minX;
		int dyMin=maxY-max(curves[n-1][i].p1.y,curves[n-1][i].p2.y);
		if(H(curves[n-1][i])){
			tmp.x=2*dxMin+1-!specialx;
			tmp.y=dyMin-1+specialy;
			tmp.horizontal=true;
		}
		else{
			tmp.x=2*dxMin-!specialx;
			tmp.y=dyMin+specialy;
			tmp.horizontal=false;
		}
		
		output.push_back(tmp);
	}
}
bool comp(const O &o1,const O &o2){
	if(o1.y<o2.y)
		return true;
	else if(o1.y==o2.y){
		if(o1.x<o2.x)
			return true;
	}
	return false;
}
int cindMinX(){
	int rv=20000000;
	for(unsigned int i=0;i<curves[n-1].size();i++)
		if(min(curves[n-1][i].p1.x,curves[n-1][i].p2.x)<rv){
			rv=min(curves[n-1][i].p1.x,curves[n-1][i].p2.x);
		}
	for(unsigned int i=0;i<curves[n-1].size();i++){
		if(min(curves[n-1][i].p1.x,curves[n-1][i].p2.x)==rv&&!H(curves[n-1][i])){
			specialx=true;
			break;
		}
	}
	return rv;
}
int cindMaxY(){
	int rv=-1;
	for(unsigned int i=0;i<curves[n-1].size();i++)
		if(max(curves[n-1][i].p1.y,curves[n-1][i].p2.y)>rv){
			rv=max(curves[n-1][i].p1.y,curves[n-1][i].p2.y);
			
		}
	for(unsigned int i=0;i<curves[n-1].size();i++){
		if(max(curves[n-1][i].p1.y,curves[n-1][i].p2.y)==rv&&H(curves[n-1][i])){
			specialy=true;
			break;
		}
	}
	return rv;
}
void clearDisplay(){
	for(int i=0;i<250;i++)
		for(int j=0;j<250;j++)
			display[i][j]=' ';
}
void process(){
	specialy=specialx=false;
	minX=cindMinX();
	maxY=cindMaxY();
	shift();
	sort(output.begin(),output.end(),comp);
	clearDisplay();
	maxy=-1;
	memset(maxx,0,sizeof(maxx));
	for(unsigned int i=0;i<output.size();i++){
		display[output[i].y][output[i].x]=(output[i].horizontal)?'_':'|';
		maxx[output[i].y]=max(output[i].x,maxx[output[i].y]);
		maxy=max(output[i].y,maxy);
	}
   for(int i=0;i<=maxy;i++){
	   for(int j=0;j<=maxx[i];j++)
		   cout<<display[i][j];
	   cout<<endl;
   }
   cout<<"^"<<endl;
}
int main(){
	preProcess();
    while(cin>>n){
		if(n==0)
			break;
		process();
	}
	return 0;
}