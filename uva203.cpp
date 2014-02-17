#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

#define INFINITY 10000
#define PI 3.14159265358979323846
#define MIN_THRESHOLD 0.00000001

map<int,string> lightName;
double light_dir[4][2]={{-1,-1},{2.5,245},{357.5,115},{110,250}};
struct P{
	double x;
	double y;
};
P Ori={0,0};
P lowleft={-INFINITY,-INFINITY};

class ship{
private:
	P p;
	string name;
	double course;
	double speed;
	// 0 mast 1 red 2 green 3 stern
	bool light[4];
	double ldir[4][2];
public:
	ship(string name,double x,double y,double course,double speed):name(name),course(course),speed(speed){
		memset(light,false,sizeof(light));
		P t={x,y};
		p=t;
		for(int i=1;i<=3;i++){
			ldir[i][0]=light_dir[i][0]+course;
			ldir[i][1]=light_dir[i][1]+course;
		}
	}
    P getCor(){
    	return p;
    }
	void setRelativeCor(double x_offset,double y_offset){
        p.x-=x_offset;
        p.y-=y_offset;
	}
	double distSquare(){
		return p.x*p.x+p.y*p.y;
	}
	double distSquare(P a,P b){
		    double x=a.x-b.x;
		    double y=a.y-b.y;
			return x*x+y*y;
	}
	bool equal_hehe(double target, double test){
		return (abs(target-test)<=MIN_THRESHOLD);
	}
	int getQua(double dir){
		if(equal_hehe(0,dir))
			return 5;
		else if(equal_hehe(90,dir))
			return 6;
		else if(equal_hehe(180,dir))
			return 7;
		else if(equal_hehe(270,dir))
			return 8;
		else if(0<dir&&dir<90)
			return 1;
		else if(90<dir&&dir<180)
			return 2;
		else if(180<dir&&dir<270)
			return 3;
		else if(270<dir&&dir<360)
			return 4;
	}
	double toRadian(double dir){
		return (dir*PI)/180;
	}
	P generateInfPoint(double dir){
		P tmp;
		int quadrant=getQua(dir);
		if(quadrant==1||quadrant==3){
			tmp.x=INFINITY;
			tmp.y=tmp.x*tan(toRadian(dir));
		}
		else if(quadrant==2||quadrant==4){
			tmp.x=INFINITY;
			tmp.y=0-tmp.x*tan(toRadian(dir));
		}
		else if(quadrant==5){
			tmp.x=0;
			tmp.y=INFINITY;
		}
		else if(quadrant==7){
			tmp.x=0;
			tmp.y=-INFINITY;
		}
		else if(quadrant==6){
			tmp.x=INFINITY;
			tmp.y=0;
		}
		else if(quadrant==8){
			tmp.x=-INFINITY;
			tmp.y=0;
		}
		tmp.x+=p.x;
		tmp.y+=p.y;
		return tmp;
	}
	double ccw(const P &p1, const P &p2, const P &p3){
	    return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
	}
	/*
	bool counterClockwise(const P &a,const P &b){
		double rv=ccw(lowleft,a,b);
        if(rv>0)
        	return true;
        else if(equal_hehe(rv,0))
        	return distSquare(lowleft,a)<distSquare(lowleft,b);
	}
	*/

	static bool compare(const P &a,const P &b){
          return a.x<b.x;
	}

	bool onLine(P target,P a,P b){
		return (min(a.x,b.x)<=target.x&&target.x<=max(a.x,b.x))&&
				(min(a.y,b.y)<=target.y&&target.y<=max(a.y,b.y));
	}
	bool inTriangle(P target,P p0,P p1,P p2){
		vector<P> hehe;
		hehe.push_back(p0);
		hehe.push_back(p1);
		hehe.push_back(p2);
		sort(hehe.begin(),hehe.end(),compare);
		if(ccw(target,hehe[0],hehe[1])>0&&ccw(target,hehe[1],hehe[2])>0&&ccw(target,hehe[2],hehe[0])>0){
		  return true;
		}
		else if(ccw(target,hehe[0],hehe[1])==0&&onLine(target,hehe[0],hehe[1])){
			return true;
		}
		else if(ccw(target,hehe[1],hehe[2])==0&&onLine(target,hehe[1],hehe[2])){
			return true;
		}
		else if(ccw(target,hehe[2],hehe[0])==0&&onLine(target,hehe[2],hehe[0])){
			return true;
		}
		return false;
	}
	void checkLights(){
		if(distSquare()<100){
			light[0]=true;
			for(int i=1;i<=3;i++){
				P p1=generateInfPoint(ldir[i][0]);
				P p2=generateInfPoint(ldir[i][1]);
				if(inTriangle(Ori,p,p1,p2))
					light[i]=true;
			}
		}
	}
	void print(){
		bool found=false;
		cout<<name<<" "<<course<<" "<<sqrt(distSquare())<<" ";
        for(int i=0;i<=3;i++){
        	if(light[i])
        		cout<<" "<<lightName[i];
        }
        if(!found)
        	cout<<"Lights not visible"<<endl;
        else
        	cout<<endl;
	}
};
vector<ship*> ships;
ship *ownship;
string s,testname;
double x,y,course,speed;
int n;


int main(){
	lightName[0]="Masthead";
	lightName[1]="Red";
	lightName[2]="Green";
	lightName[3]="Stern";

     while(getline(cin,testname)){
    	if(ownship)
    		delete ownship;
    	ships.clear();
        cout<<testname<<endl<<endl;
        cout<<"Boat ID         Bearing      Distance   Lights (left to right)"<<endl;
        cout<<"---------------------------------------------------------------"<<endl;

        cin>>n;
        getline(cin,s);
        cin>>x>>y>>course>>speed;
        ownship=new ship(s,x,y,course,speed);
        P myCor=ownship->getCor();
        for(int i=0;i<n;i++){
        	getline(cin,s);
        	cin>>x>>y>>course>>speed;
        	ships.push_back(new ship(s,x,y,course,speed));
        	ships[ships.size()-1]->setRelativeCor(myCor.x,myCor.y);
        	ships[ships.size()-1]->checkLights();
        	ships[ships.size()-1]->print();
        }
        cout<<"***************************************************************"<<endl;
     }
	return 0;
}
