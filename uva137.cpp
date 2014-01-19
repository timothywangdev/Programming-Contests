#define MAXIMUM 1000;
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;
#ifdef DEBUG
ifstream fin("uva137.in");
ofstream fout("uva137.out");
#endif

struct P{
    double x;
	double y;
};
double ccw(const P &p1,const P &p2,const P &p3){
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
vector<P> poly[2],critical;
int N1,N2;
P tmp,p0;

double getArea(vector<P> *v){
	 double rv=0;
     for(unsigned int i=0;i<v->size();i++)
		 rv+=(*v)[i].x*(*v)[(i+1)%v->size()].y-(*v)[(i+1)%v->size()].x*(*v)[i].y;
	 return rv*0.5;
}

bool onSegment(P &target,P &lineP1,P &lineP2){
	double minX=min(lineP1.x,lineP2.x);
	double maxX=max(lineP1.x,lineP2.x);
	double minY=min(lineP1.y,lineP2.y);
	double maxY=max(lineP1.y,lineP2.y);

    return (minX<=target.x)&&(target.x<=maxX)&&(minY<=target.y)&&(target.y<=maxY);
}
bool inPoly(P &point,int testPoly){
     for(unsigned int i=0;i<poly[testPoly].size();i++)
		 if(ccw(poly[testPoly][i],poly[testPoly][(i+1)%poly[testPoly].size()],point)>0)
			 return false;
		 else if(ccw(poly[testPoly][i],poly[testPoly][(i+1)%poly[testPoly].size()],point)==0){
			 if(!onSegment(point,poly[testPoly][i],poly[testPoly][(i+1)%poly[testPoly].size()]))
				 return false;
			 else 
				 return true;
		 }
	 return true;
}

bool operator==(const P &p1,const P &p2){
    return p1.x==p2.x&&p1.y==p2.y;
}
void findPointsIn(int target,int testPoly){
     for(unsigned int i=0;i<poly[target].size();i++)
		 if(inPoly(poly[target][i],testPoly))
			if(find(critical.begin(),critical.end(),poly[target][i])==critical.end())
			  critical.push_back(poly[target][i]);
}
P verticalIntersectPoint(P &p1,P &p2,P &p3,P &p4){
     P tmp;
	 tmp.x=p1.x;
	 tmp.y=(tmp.x-p4.x)*((p4.y-p3.y)/(p4.x-p3.x))+p4.y;
	 return tmp;
}
P getIntersectPoint(P &p1,P &p2,P &p3,P &p4){
     P tmp;
	 if(p1.x-p2.x==0)
		 return verticalIntersectPoint(p1,p2,p3,p4);
	 else if(p4.x-p3.x==0)
		 return verticalIntersectPoint(p3,p4,p1,p2);
	 double a=p1.x,
		    b=p1.y,
			c=p2.x,
			d=p2.y,
			e=p3.x,
			f=p3.y,
			g=p4.x,
			h=p4.y;

	 tmp.x=( (g*((f-h)/(e-g)))-(c*((d-b)/(c-a)))+d-h )/( ((f-h)/(e-g))-((d-b)/(c-a)) );
	 tmp.y=(a*d*f-a*d*h-b*c*f+b*c*h-b*e*h+b*f*g+d*e*h-d*f*g)/(a*f-a*h-b*e+b*g-c*f+c*h+d*e-d*g);
	 return tmp;
}
P SegmentsIntersect(P &p1,P &p2,P &p3,P &p4){
	  P notFound;
	  notFound.x=notFound.y=-1;
      double d1=ccw(p3,p4,p1),
		     d2=ccw(p3,p4,p2),
			 d3=ccw(p1,p2,p3),
			 d4=ccw(p1,p2,p4);
	  if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
		  return getIntersectPoint(p1,p2,p3,p4);
	  else
		  return notFound;
}
void checkIntersections(P &target1,P &target2,int testPoly){
	P tmp;
	for(unsigned int i=0;i<poly[testPoly].size();i++){
        tmp=SegmentsIntersect(target1,target2,poly[testPoly][i],poly[testPoly][(i+1)%poly[testPoly].size()]);
		if(tmp.x!=-1)
			if(find(critical.begin(),critical.end(),tmp)==critical.end())
				critical.push_back(tmp);
	}
}
void findIntersectedSegments(int target,int testPoly){
     for(unsigned int i=0;i<poly[target].size();i++)
		 checkIntersections(poly[target][i],poly[target][(i+1)%poly[target].size()],testPoly);
}
void findCriticalPoints(){
    findPointsIn(0,1);
    findPointsIn(1,0);
	findIntersectedSegments(0,1);
    findIntersectedSegments(1,0);
}
double dist(const P &v1,const P &v2){
    return (v1.x-v2.x)*(v1.x-v2.x)+(v1.y-v2.y)*(v1.y-v2.y);
}
bool comp(const P &p1,const P &p2){
	  double rv=ccw(p0,p1,p2);
      if(rv>0)
		  return true;
	  if(rv==0)
		   if(dist(p0,p1)<dist(p0,p2))
		      return true;
	  return false;
}
string getString(int n){
    ostringstream convert;
	convert<<n;
	return convert.str();
}
string makeSpaces(int n){
   string s="";
   for(int i=0;i<n;i++)
	   s=s+' ';
   return s;
}
double toDouble(string s){
   istringstream convert(s);
   double rv;
   convert>>rv;
   return rv;
}
void display(double result){
     int intergerPart=(int)result;
	 string intergerStr=getString(intergerPart);
	 string space=makeSpaces(5-intergerStr.length());
	 #ifdef DEBUG
	 if(intergerStr.length()>1){
	  double difference=result-toDouble(intergerStr.substr(0,intergerStr.length()-1))*10;
	  fout<<space+intergerStr.substr(0,intergerStr.length()-1)<<fixed<<setprecision(2)<<difference;
     }
	 else
	   fout<<fixed<<setprecision(2)<<space<<result;
     #else
	 if(intergerStr.length()>1){
	  double difference=result-toDouble(intergerStr.substr(0,intergerStr.length()-1))*10;
	  cout<<space+intergerStr.substr(0,intergerStr.length()-1)<<fixed<<setprecision(2)<<difference;
     }
	 else
	   cout<<fixed<<setprecision(2)<<space<<result;
     #endif

}
void area(){
	double miny=MAXIMUM;
	double minx=MAXIMUM;
	unsigned int minIndex=-1;
	for(unsigned int i=0;i<critical.size();i++){
		if(critical[i].y<miny){
           miny=critical[i].y;
		   minx=critical[i].x;
		   minIndex=i;
		}
		else if(critical[i].y==miny&&critical[i].x<minx){
           minx=critical[i].x;
		   minIndex=i;
		}
	}
	if(minIndex!=-1){
	  p0=critical[minIndex];
	  swap(critical[0],critical[minIndex]);
      sort(critical.begin()+1,critical.end(),comp);
	  display(0-getArea(&poly[0])-getArea(&poly[1])-2*getArea(&critical));
	}
	else{
      display(0-getArea(&poly[0])-getArea(&poly[1]));
	}
}
int main(){

	while(true){
	   poly[0].clear();
	   poly[1].clear();
	   critical.clear();
       #ifdef DEBUG
       fin>>N1;
	   if(N1==0)
		   break;
	   for(int i=0;i<N1;i++){
		   fin>>tmp.x>>tmp.y;
		   poly[0].push_back(tmp);
	   }
	   fin>>N2;
	   for(int i=0;i<N2;i++){
           fin>>tmp.x>>tmp.y;
		   poly[1].push_back(tmp);
	   }
       #else
	   cin>>N1;
	   if(N1==0)
		   break;
	   for(int i=0;i<N1;i++){
		   cin>>tmp.x>>tmp.y;
		   poly[0].push_back(tmp);
	   }
	   cin>>N2;
	   for(int i=0;i<N2;i++){
           cin>>tmp.x>>tmp.y;
		   poly[1].push_back(tmp);
	   }
	   #endif
       findCriticalPoints();
	   area();
	}
	#ifdef DEBUG
	fout<<endl;
    #else
    cout<<endl;
    #endif
	return 0;
}

