#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
//#define DEBUG
using namespace std;

#ifdef DEBUG
ifstream fin("uva150.in");
ofstream fout("uva150.out");
#endif
string dayStr[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
map<string,int> dayInt;
string monthStr[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
map<string,int> monthInt;

map<string,int> toOld;
map<string,int> toNew;

struct Date{
	int date;
    int year;
	int month;
	int day;
};

Date oc[200000],nc[200000];
int ocounter=1,ncounter=1;
int addDate(int date,int days){
    return (date+1)%(days+1);
}
bool leap(int year){

   if(year%100==0&&year%400==0)
	   return true;
   else if(year%100!=0&&year%4==0)
	   return true;
   return false;
	//return year%400==0;
}
bool leapOld(int year){
      return year%4==0;
}
string toStr(int n){
 ostringstream convert;
 convert<<n;
 return convert.str();
}
string getStr(Date d){
	string rv=dayStr[d.day];
	rv=rv+" "+toStr(d.date)+" "+monthStr[d.month-1]+" "+toStr(d.year);
	return rv;
}
string getStrRv(Date d){
	string rv=dayStr[d.day];
	rv=rv+" "+toStr(d.date)+"* "+monthStr[d.month-1]+" "+toStr(d.year);
	return rv;
}
void preprocess(){
	// Old
	Date record;
	record.year=1582;
	record.month=10;
	record.date=5;
	record.day=5;
    
	while(record.year<=2101){
		oc[ocounter]=record;
		toOld[getStr(record)]=ocounter;
		//fout<<getStr(record)<<endl;
		ocounter++;
		record.day=(record.day+1)%7;
	    // Feb
		if(record.month==2&&leapOld(record.year))
           record.date=addDate(record.date,days[record.month-1]+1);
		else
           record.date=addDate(record.date,days[record.month-1]);

		if(record.date==0){
             record.date++;
			 record.month++;
		}

		if(record.month>12){
           record.month=1;
		   record.year++;
		}
	}

	//New
	record.year=1582;
	record.month=10;
	record.date=15;
	record.day=5;
    
	while(record.year<=2101){
		//fout<<record.year<<" "<<record.month<<" "<<record.date<<endl;
		//if(record.year%10==0)
		//	cout<<record.year<<" "<<ncounter<<endl;
		nc[ncounter]=record;
		toNew[getStr(record)]=ncounter;
		ncounter++;
		record.day=(record.day+1)%7;
	    // Feb
		if(record.month==2&&leap(record.year))
           record.date=addDate(record.date,days[record.month-1]+1);
		else
           record.date=addDate(record.date,days[record.month-1]);

		if(record.date==0){
             record.date++;
			 record.month++;
		}

		if(record.month>12){
           record.month=1;
		   record.year++;
		}
	}
}
int main(){
    for(int i=0;i<7;i++)
		dayInt[dayStr[i]]=i;
    for(int i=0;i<12;i++)
		monthInt[monthStr[i]]=i;
    preprocess();
	
	string s;
	
	while(getline(cin,s)){
		if(s[0]=='#')
			break;
		
		int oIndex=-1,nIndex=-1;
		if(toOld.find(s)!=toOld.end())
		   oIndex=toOld[s];
	    if(toNew.find(s)!=toNew.end())
		   nIndex=toNew[s];
	   if(oIndex!=-1)
		   cout<<getStr(nc[oIndex])<<endl;
	   if(nIndex!=-1)
		   cout<<getStrRv(oc[nIndex])<<endl;
		   
		//fout<<s<<endl;
	}
	
	return 0;
}