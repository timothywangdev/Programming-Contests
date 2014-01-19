#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "string.h"
#include <algorithm>
#define MAXIMUM 100000000;
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva158.in");
ofstream fout("uva158.out");
#endif 

int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int year;
int monthaccu[12][12];
class Date{
public:
	int d;
	int m;
	Date(int d,int m):d(d),m(m){}
	bool operator>=(Date &other){
		if(m>=other.m)
			return true;
		else if(m==other.m){
			if(d>=other.d)
				return true;
		}

		if(m==1&&other.m==12)
			return true;
		return false;
	}
	bool operator<(Date &other){
		if(m<other.m)
			return true;
		else if(m==other.m&&d<other.d)
			return true;
		return false;
	}
	bool operator==(Date &other){
		return (m==other.m)&&(d==other.d);
	}
	int operator-(Date &other){
		if(m==1&&other.m==12)
			return days[11]+d-other.d;
		else
		    return monthaccu[other.m-1][m-1]+d-other.d;
	}
};
class A{
public:
	Date *date;
	string s;
	int p;
	int index;
	A(int d,int m,int p,string s,int index):p(p),s(s),index(index){
		date=new Date(d,m);
	}
};

char ch;
int d,m,p;
string s;

vector<A> cal;
vector<Date> dates;
bool comp(A a,A b){
	if(a.date->m==12&&b.date->m==1)
		return true;
	if(*(a.date)<*(b.date))
		return true;
	else if(*(a.date)==*(b.date)){
		if(a.p>b.p)
			return true;
		else if(a.p==b.p){
			if(a.index<b.index)
				return true;
		}
	}
	return false;
}
string getP(int p){
	string s;
	if(p==-1)
		return "*TODAY*";
	else{
		for(int i=1;i<=p;i++)
			s=s+'*';
		string space;
		for(int i=1;i<=7-(int)s.length();i++)
			space=space+' ';
		return s+space;
	}

}
void process(int k){
	vector<A> rv;
	for(unsigned int i=0;i<cal.size();i++){
		if(*(cal[i].date)>=dates[k]){
            int delta=*(cal[i].date)-(dates[k]);
			A newA=cal[i];
			newA.date=new Date(cal[i].date->d,cal[i].date->m);
			newA.p=newA.p-delta+1;
			if(dates[k].m==12&&newA.date->m==1)
                newA.date->m=13;
            if(*(cal[i].date)==dates[k])
				newA.p=MAXIMUM;

			if(newA.p>0&&delta>=0)
			 rv.push_back(newA);
		}
	}
	sort(rv.begin(),rv.end(),comp);
#ifdef DEBUG
    fout<<"Today is:"<<setw(3)<<dates[k].d<<setw(3)<<dates[k].m<<endl;
	for(unsigned int i=0;i<rv.size();i++){
		if(rv[i].date->m==13)
           rv[i].date->m=1;
		if(*(rv[i].date)==dates[k])
			fout<<setw(3)<<rv[i].date->d<<setw(3)<<rv[i].date->m<<" "<<getP(-1)<<" "<<rv[i].s<<endl;
		else
			fout<<setw(3)<<rv[i].date->d<<setw(3)<<rv[i].date->m<<" "<<getP(rv[i].p)<<" "<<rv[i].s<<endl;
	}
#else
	cout<<"Today is:"<<setw(3)<<dates[k].d<<setw(3)<<dates[k].m<<endl;
	for(unsigned int i=0;i<rv.size();i++){
		if(rv[i].date->m==13)
           rv[i].date->m=1;
		if(*(rv[i].date)==dates[k])
			cout<<setw(3)<<rv[i].date->d<<setw(3)<<rv[i].date->m<<" "<<getP(-1)<<" "<<rv[i].s<<endl;
		else
			cout<<setw(3)<<rv[i].date->d<<setw(3)<<rv[i].date->m<<" "<<getP(rv[i].p)<<" "<<rv[i].s<<endl;
	}
#endif

}
void removeSpaces(string &s){
	int pos=0;
	for(unsigned int i=0;i<s.length();i++)
		if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z')){
			pos=i;
			break;
		}
		s=s.substr(pos,s.length()-pos);
}
int main(){
	#ifdef DEBUG
	fin>>year;
	#else
	cin>>year;
	#endif
	if(year%4==0)
		days[1]++;
	memset(monthaccu,0,sizeof(monthaccu));
	for(int i=11;i>0;i--)
		for(int j=i-1;j>=0;j--)
			monthaccu[j][i]=monthaccu[j+1][i]+days[j];
	int counter=0;
	#ifdef DEBUG
	while(fin>>ch){
		if(ch=='A'){
			fin>>d>>m>>p;
		    getline(fin,s);
	#else
    while(cin>>ch){
		if(ch=='A'){
			cin>>d>>m>>p;
		    getline(cin,s);
	#endif
			
			removeSpaces(s);
			A newA(d,m,p,s,counter);
			cal.push_back(newA);
			counter++;
		}
		else if(ch=='D'){
			#ifdef DEBUG
			fin>>d>>m;
			#else
			cin>>d>>m;
			#endif
			Date newDate(d,m);
			dates.push_back(newDate);
		}
		else
			break;
	}
	for(unsigned int i=0;i<dates.size();i++){
		process(i);
		if(i<dates.size()-1)
			cout<<endl;
	}
	return 0;

}