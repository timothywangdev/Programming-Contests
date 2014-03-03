#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string s;
int N,D,M,Y;
int mm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool leap(int y){
   return (y%4==0&&y%100!=0)||(y%400==0);
}
int limM(int m,int y){
	if(leap(y)&&m==2)
		return 29;
	else return mm[m];
}
string sign(int d,int m){
   if((m==1&&d>=21)||(m==2&&d<=19))
	   return "aquarius";
   if((m==2&&d>=20)||(m==3&&d<=20))
	   return "pisces";
   if((m==3&&d>=21)||(m==4&&d<=20))
	   return "aries";
   if((m==4&&d>=21)||(m==5&&d<=21))
	   return "taurus";
   if((m==5&&d>=22)||(m==6&&d<=21))
	   return "gemini";
   if((m==6&&d>=22)||(m==7&&m<=22))
	   return "cancer";
   if((m==7&&d>=23)||(m==8&&d<=21))
	   return "leo";
   if((m==8&&d>=22)||(m==9&&d<=23))
	   return "virgo";
   if((m==9&&d>=24)||(m==10&&d<=23))
	   return "libra";
   if((m==10&&d>=24)||(m==11&&d<=22))
	   return "scorpio";
   if((m==11&&d>=23)||(m==12&&d<=22))
	   return "sagittarius";
   if((m==12&&d>=23)||(m==1&&d<=20))
	   return "capricorn";
}
int toInt(string s){
	istringstream iss(s);
	int n;
	iss>>n;
	return n;
}
void getData(string s,int &d,int &m,int &y){
    string dd=s.substr(0,2);
    string mm=s.substr(2,2);
    string yyyy=s.substr(4,4);
	d=toInt(dd);
	m=toInt(mm);
	y=toInt(yyyy);
}
string toStr(int n){
	ostringstream oss;
	oss<<n;
	return oss.str();
}
string format(int D,int M,int Y){
	string d=toStr(D);
	string m=toStr(M);
	string y=toStr(Y);
	if(d.length()==1)
		d='0'+d;
	if(m.length()==1)
		m='0'+m;
	return d+'/'+m+'/'+y;
}
int main(){
    cin>>N;
    for(int k=1;k<=N;k++){
    	cin>>s;
        getData(s,M,D,Y);
        for(int i=0;i<40;i++){
        	D+=7;
        	if(D>limM(M,Y)){
        		D=D-limM(M,Y);
        		M++;
        		if(M>12){
        			M=1;
        			Y++;
        		}
        	}
        }
        cout<<k<<" "<<format(M,D,Y)<<" "<<sign(D,M)<<endl;
    }
	return 0;
}
