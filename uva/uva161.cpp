#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <iomanip>
#include "math.h"
using namespace std;

//#define DEBUG
#ifdef DEBUG
ifstream cin("uva161.in");
ofstream cout("uva161.out");
#endif
vector<int> d;
int tmp;

struct Overlap{
    int minimum;
	int maximum;
};

void calOverlap(Overlap &ol,int j){
     // 1. min<=(left||right)<=max
     int minI=ceil((float)ol.minimum/(float)d[j]);
	 int maxI=floor((float)ol.maximum/(float)d[j]);
	 int rangeMin=-1,rangeMax=-1;
	 // If we have found it
	 if(minI==maxI){
		 // Left
		 if(minI%2==0){
            ol.minimum=minI*d[j];
			return;
		 }
		 else{
         // Right
            ol.maximum=minI*d[j]-5;
			return;
		 }
	 }
	 else{
        // Check if left<min&&max<right
		 if(minI%2==1&&maxI%2==0){
			 if(minI*d[j]-5<=ol.maximum)
				 ol.maximum=minI*d[j]-5;
            return;
		 }
	 }

	 // Not found
	 ol.minimum=-1;
}

string failure(){
    return "Signals fail to synchronise in 5 hours";
}


void getTime(Overlap ol){
   int n=ol.minimum;
   int hour=n/3600;
   int minute=(n-hour*3600)/60;
   int second=n-hour*3600-minute*60;
   if((hour>5)||(hour==5&&(minute>0||second>0)))
	   cout<<failure()<<endl;
   else
       cout<<setw(2)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minute<<":"<<setw(2)<<setfill('0')<<second<<endl;
}
void process(){
    int mind=d[0];
	Overlap ol;
	bool fail;
	for(int i=3;(i-1)*mind<=20000;i=i+2){
		ol.minimum=(i-1)*mind;
		ol.maximum=i*mind-5;
		fail=false;;
		for(unsigned int j=1;j<d.size();j++){
            calOverlap(ol,j);
			if(ol.minimum==-1||ol.minimum>=ol.maximum){
				fail=true;
                break;
			}
		}
		// Succeed
		if(!fail){
          getTime(ol);
		  return;
		}
	}
	cout<< failure()<<endl;;
}

int main(){
	while(true){
		d.clear();
		while(cin>>tmp){
           if(tmp==0)
			   break;
		   d.push_back(tmp);
		}
		if(d.size()==0){
			cin>>tmp>>tmp;
			break;
		}
		sort(d.begin(),d.end());
		process();
	}
	return 0;
}