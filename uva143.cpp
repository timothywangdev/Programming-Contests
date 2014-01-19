//#define DEBUG
//#include <iostream>
//#include <iomanip>
//#include <fstream>
#include "stdio.h"
#include <algorithm>
#include <cmath>
using namespace std;
#ifdef DEBUG
ifstream fin("uva143.in");
ofstream fout("uva143.out");
#endif
double minimum=0.00000001;

bool isInt(double &n){
     double upper=ceil(n);
	 double lower=floor(n);
	 if(upper-n<minimum){
          n=upper;
		  return true;
	 }
	 else if(n-lower<minimum){
          n=lower;
		  return true;
	 }
	 else
		 return false;
}

struct P{
   double x;
   double y;
};
bool ccw(P &p1,P &p2,P &p3){
    return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x)>0;
}
class Line{
public:
	P p0;
	P p1;
	double deltaX;
	double deltaY;
	bool direction;
	Line(P &p0,P &p1):p0(p0),p1(p1){
		deltaX=p1.x-p0.x;
		deltaY=p1.y-p0.y;
	}
	void setDir(Line &other){
		if(p0.y>p1.y){
			if(!ccw(p0,other.p1,p1)){
				direction=false;
				other.direction=true;
			}
			else{
				direction=true;
				other.direction=false;
			}
		}
		else{
             if(!ccw(p0,p1,other.p1)){
				 direction=false;
				 other.direction=true;
			 }
			 else{
				 direction=true;
				 other.direction=false;
			 }
		}
	}
	int getX(double &y){
		double accurate=(p1.y!=p0.y)?(y-p0.y)*(deltaX/deltaY)+p0.x:p0.y;
		//fout<<accurate<<" "<<(int)(accurate)<<endl;
		if(!direction){
           if(isInt(accurate))
			   return ((int)(accurate)>=1)?(int)(accurate):1;
		    else
				return (int)(accurate)+1;
		}
		else{
			if(isInt(accurate)){
			}
			return ((int)(accurate)<=99)?(int)(accurate):99;
		}
	}
};

P tri[3];

bool triComp(const P &a,const P &b){
	return a.y<b.y;
}
void display(int n){
	#ifdef DEBUG
    fout<<setw(4)<<n<<endl;
    #else
	//cout<<setw(4)<<n<<endl;
	printf("%4d\n",n);
    #endif
}
void adjust(int &upper,int &lower){
    if(upper>99)
		upper=99;
	if(lower<1)
		lower=1;
}
int calLine(){
	if(tri[0].y==tri[1].y&&tri[1].y==tri[2].y){
		    if(!isInt(tri[0].y)||tri[0].y>=100||tri[0].y<=0)
				return 0;
            double minX=min(tri[0].x,min(tri[1].x,tri[2].x));
			double maxX=max(tri[0].x,max(tri[1].x,tri[2].x));
            int right,left;

			if(isInt(minX))
				left=(int)minX;
			else
				left=(int)minX+1;

			right=(int)maxX;
            adjust(left,right);
			return right-left+1;
	}
	else{
		    if(!isInt(tri[0].x)||tri[0].x>=100||tri[0].x<=0)
				return 0;

            double minY=min(tri[0].y,min(tri[1].y,tri[2].y));
			double maxY=max(tri[0].y,max(tri[1].y,tri[2].y));
            int upper,lower;

			if(isInt(minY))
				lower=(int)minY;
			else
				lower=(int)minY+1;

			upper=(int)maxY;
            adjust(upper,lower);
			return upper-lower+1;
	}
}

int calLineSum(Line &l1,Line &l2,int cl){
	//fout<<endl;
	int left,right;
	double currentLine=(double)cl;
	if(!l1.direction){
		//fout<<"l1: ";
		left=l1.getX(currentLine);
		//fout<<"l2: ";
		right=l2.getX(currentLine);
		//fout<<"left "<<left<<" right "<<right<<endl;
		if(left>right)
			return 0;
		else
			return right-left+1;
	}
	else{
		//fout<<"l1: ";
        left=l2.getX(currentLine);
		//fout<<"l2: ";
		right=l1.getX(currentLine);
		//fout<<"left "<<left<<" right"<<right<<endl;
		if(left>right)
			return 0;
		else
			return right-left+1;
	}
}
int calParallel(){
    Line l1(tri[2],tri[0]);
	Line l2(tri[2],tri[1]);
	l1.setDir(l2);
	int upper=(int)tri[2].y;
	int lower=isInt(tri[0].y)?(int)tri[0].y:(int)tri[0].y+1;
	adjust(upper,lower);
	int sum=0;
	for(int currentLine=lower;currentLine<=upper;currentLine++)
		sum+=calLineSum(l1,l2,currentLine);
    return sum;
}
int calParallelUpsideDown(){
    Line l1(tri[0],tri[1]);
	Line l2(tri[0],tri[2]);
	l1.setDir(l2);
	int upper=(int)tri[2].y;
	int lower=isInt(tri[0].y)?(int)tri[0].y:(int)tri[0].y+1;
	adjust(upper,lower);
	int sum=0;
	for(int currentLine=lower;currentLine<=upper;currentLine++)
		sum+=calLineSum(l1,l2,currentLine);
    return sum;
}
int calNonParallel(){
	Line l1(tri[2],tri[0]);
	Line l2(tri[2],tri[1]);
	l1.setDir(l2);
	int middleLine=isInt(tri[1].y)?(int)(tri[1].y):(int)(tri[1].y)+1;
	int upper=(int)tri[2].y;
	int lower=isInt(tri[0].y)?(int)tri[0].y:(int)tri[0].y+1;
	adjust(upper,lower);
	int sum=0;
	//For upper triangle
	for(int currentLine=middleLine;currentLine<=upper;currentLine++)
		sum+=calLineSum(l1,l2,currentLine);
    //fout<<"======================="<<endl;
	//For lower triangle
	Line l3(tri[0],tri[1]);
	Line l4(tri[0],tri[2]);
	l3.setDir(l4);
    for(int currentLine=lower;currentLine<middleLine;currentLine++)
		sum+=calLineSum(l3,l4,currentLine);

	return sum;
}
int main(){
	while(true){
		#ifdef DEBUG
		fin>>tri[0].x>>tri[0].y>>tri[1].x>>tri[1].y>>tri[2].x>>tri[2].y;
		#else
		//cin>>tri[0].x>>tri[0].y>>tri[1].x>>tri[1].y>>tri[2].x>>tri[2].y;
		scanf("%lf %lf %lf %lf %lf %lf",&tri[0].x,&tri[0].y,&tri[1].x,&tri[1].y,&tri[2].x,&tri[2].y);
		#endif
		if(tri[0].x==0&&tri[0].y==0&&tri[1].x==0&&tri[1].y==0&&tri[2].x==0&&tri[2].y==0)
			break;
		sort(tri,tri+3,triComp);
		if((tri[0].y==tri[1].y&&tri[1].y==tri[2].y)||
			(tri[0].x==tri[1].x&&tri[1].x==tri[2].x))
			display(calLine());
		else if(tri[0].y==tri[1].y)
		    display(calParallel());
		else if(tri[1].y==tri[2].y)
            display(calParallelUpsideDown());
		else
			display(calNonParallel());
	}
}
