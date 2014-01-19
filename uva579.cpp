#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

string s;
int hour,minute;
int toInt(string s){
	int n;
    istringstream iss(s);
	iss>>n;
	return n;
}
void getInfo(){
    int pos;
	for(unsigned int i=0;i<s.length();i++)
		if(s[i]==':'){
            pos=i;
			break;
		}
		hour=toInt(s.substr(0,pos));
		minute=toInt(s.substr(pos+1,s.length()-pos-1));
}
int main(){
	while(getline(cin,s)){
		if(s=="0:00")
			break;
        getInfo();
		double hd=((double)hour/12)*360+((double)minute/60)*30;
		double hm=((double)minute/60)*360;
		double d=hd-hm;
		if(d<0)
			d=-d;
		if(d>180)
			d=360-d;
		cout<<fixed<<setprecision(3)<<d<<endl;
	}
	return 0;
}