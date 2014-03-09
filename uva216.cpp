#include <iostream>
#include <map>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <fstream>
#define MAXIMUM 2147483647
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva216.in");
ofstream fout("uva216.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
struct P{
	int x;
	int y;
};
map<int,P> toP;
double m[8][8];
int N,x,y,tspMin;
int nextPoint[8][255],currentNextPoint[8][255];
int counter=0,startPoint,endPoint,currentStartPoint;
unsigned int doneMask;
double getDist(P &a,P &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void copyNext(){
	for(int i=0;i<N;i++)
		for(int mask=1;mask<=doneMask;mask++)
		 nextPoint[i][mask]=currentNextPoint[i][mask];
}
unsigned turnOn(unsigned int n,int pos){
	return n|1<<pos;
}
bool getBit(unsigned n,int pos){
	return ((n&(1<<pos))!=0);
}
double tsp(){
	double t[8][255];
	for(unsigned int mask=doneMask;mask>=1;mask--){
		for(int j=0;j<N;j++)
			if(getBit(mask,j)){
				double minimum=MAXIMUM;
				int np;
				if(mask==doneMask){
					currentNextPoint[j][mask]=currentStartPoint;
				    t[j][mask]=m[j][currentStartPoint];
					continue;
				}
				for(int k=0;k<N;k++){
					if(!getBit(mask,k)){
						if(minimum>m[j][k]+t[k][turnOn(mask,k)]){
							minimum=m[j][k]+t[k][turnOn(mask,k)];
							np=k;
						}
					}
				}
				currentNextPoint[j][mask]=np;
				t[j][mask]=minimum;
			}
	}
	return t[currentStartPoint][turnOn(0,currentStartPoint)];
}

void printP(P &p){
	cout<<"(";
	cout<<p.x<<","<<p.y;
	cout<<")";
}
unsigned int power(int base,int k){
	unsigned int rv=1;
	for(int i=0;i<k;i++)
		rv*=base;
	return rv;
}
int main(){
	redirect();
	while(cin>>N){
		if(!N)
			break;
		toP.clear();
		doneMask=power(2,N)-1;
		counter++;
		for(int i=0;i<N;i++){
			cin>>x>>y;
			P tmp={x,y};
			toP[i]=tmp;
		}
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				m[i][j]=getDist(toP[i],toP[j])+16;
		double minimum=MAXIMUM;
		for(int i=0;i<N-1;i++)
			for(int j=i+1;j<N;j++){
				double old=m[i][j];
				m[i][j]=0;
				currentStartPoint=i;
				double rv=tsp();
				if(rv<minimum){
					minimum=rv;
					copyNext();
					startPoint=i;
					endPoint=j;
				}
				m[i][j]=old;
			}
			cout<<"**********************************************************"<<endl;
			cout<<"Network #"<<counter<<endl;
			int currentMask=turnOn(0,startPoint),currentPoint=startPoint;
			/*
			if(nextPoint[startPoint][currentMask]==endPoint){
				currentMask=turnOn(currentMask,endPoint);
				currentPoint=endPoint;
			}
			*/
			do{
				int nextP=nextPoint[currentPoint][currentMask];
				if(!(currentPoint==startPoint&&nextP==endPoint)){
				cout<<"Cable requirement to connect ";
				printP(toP[currentPoint]);
				cout<<" to ";
				printP(toP[nextP]);
				cout<<" is "<<fixed<<setprecision(2)<<m[currentPoint][nextP]<<" feet."<<endl;
				}
				currentPoint=nextP;
				currentMask=turnOn(currentMask,nextP);
			}while(currentPoint!=startPoint);
			
			cout<<"Number of feet of cable required is "<<fixed<<setprecision(2)<<minimum<<"."<<endl;
	}
	return 0;
}