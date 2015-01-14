#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "string.h"
using namespace std;
//#decine DEBUG
#ifdef DEBUG
ifstream cin("uva168.in");
ofstream cout("uva168.out");
#endif
string s;
string p[26];
bool candle[26];
bool used[26],firstTime;
char T,M,enterFrom,enterFromSpecial;
long long K,firstNode,S;
vector<int> circle,path;
void generatePath(int start,int end){
	if(start==end)
		return;
	while(!('A'<=s[start]&&s[start]<='Z'))
		start++;
	while(!('A'<=s[end]&&s[end]<='Z'))
		end--;
	p[s[start]-'A']=s.substr(start+2,end-start-1);
}
void getBasicinfo(int start){
	istringstream iss(s.substr(start,s.length()-start));
	iss>>M>>T>>K;
}
void generateGraph(){
	unsigned int last=0;
	for(unsigned int i=0;i<s.length();i++){
		if(s[i]==';'||s[i]=='.'){
			generatePath(last,i-1);
			last=i+1;
			if(s[i]=='.'){
				getBasicinfo(i+1);
				break;
			}
		}
	}
}
/*
bool getFirstPath(int current,int &rv){
for(unsigned int i=0;i<p[current].length();i++){
if(!candle[p[current][i]-'A']&&enterFrom!=p[current][i]){
if(firstTime&&(int)(p[current][i]-'A')==firstNode){
firstTime=false;
continue;
}
rv=(int)(p[current][i]-'A');
enterFrom=(char)(current+'A');
return true;
}
}
return false;
}
bool getFirstPathSpecial(int current,int &rv){
for(unsigned int i=0;i<p[current].length();i++){
if(!candle[p[current][i]-'A']&&enterFromSpecial!=p[current][i]){
if(firstTime&&(int)(p[current][i]-'A')==firstNode){
firstTime=false;
continue;
}
rv=(int)(p[current][i]-'A');
enterFromSpecial=(char)(current+'A');
return true;
}
}
return false;
}

void checkOrder(){
	if(circle[circle.size()-1]!=(int)(enterFrom-'A')){
		for(unsigned int i=1;i<(circle.size()-1)/2+1;i++)
			swap(circle[i],circle[circle.size()-i]);
	}
}
bool checkPath(int current){
	int pos=-1;
	for(int i=0;i<(int)path.size();i++){
		if(path[i]==current){
			pos=i;
			break;
		}
	}
	if(pos==-1)
		return false;
	for(int i=pos;i<(int)path.size();i++)
		if(i-pos<circle.size()){
			if(circle[i-pos]!=path[i])
				return false;
		}
		else{
			return false;
		}
		return true;
}
bool generateCircle(int current){
	circle.clear();
	bool passedBy[26];
	memset(passedBy,0,sizeof(passedBy));
	passedBy[current]=true;
	circle.push_back(current);
	enterFromSpecial='#';
	int rv;
	while(true){
		if(getFirstPathSpecial(current,rv)){
			current=rv;
			// circle
			if(passedBy[current])
				break;
			else{

				passedBy[current]=true;
				circle.push_back(current);
			}
		}
		else{
			//cout<<"EXCEPTION NO PATH!"<<endl;
			return false;
		}
	}
	checkOrder();
	if(!checkPath(current))
		return false;
	S=circle.size();
	return true;
}
bool existNext(int current){
	for(unsigned int i=0;i<p[current].length();i++){
		if(!candle[p[current][i]-'A']&&enterFrom!=p[current][i]){
			if(firstTime&&(int)(p[current][i]-'A')==firstNode)
				continue;
			return true;
		}
	}
	return false;
}

void generateCircle(int current){
for(unsigned int i=0;i<circle.size();i++)
if(circle[i]==current){
S=circle.size()-i;
for(unsigned int j=i;j<circle.size();j++)
swap(circle[j-i],circle[j]);
break;
}
}


void process(){
int current=(int)(M-'A');
int step=1,rv;
enterFrom='#';
memset(used,false,sizeof(used));
used[M-'A']=true;
circle.clear();
circle.push_back((int)(M-'A'));
firstTime=true;
firstNode=(int)(T-'A');
if(step==K){
candle[current]=true;
if(existNext(current))
cout<<(char)(current+'A')<<" ";
step=0;
}
while(true){
if(getFirstPath(current,rv)){
if(firstTime)
firstTime=false;
current=rv;
// Found a circle,circle should not be fake circle.
if(used[current]&&generateCircle(current)){
if(K>=S){
int next=(K-step)%S;
if(next!=0)
next--;
else
next=S-1;
candle[circle[next]]=true;	
path.clear();
current=circle[next];
enterFrom=(next-1>=0)?(char)(circle[next-1]+'A'):(char)(circle[S-1]+'A');
if(existNext(current))
cout<<(char)(current+'A')<<" ";
step=0;

}
memset(used,false,sizeof(used));
}
else{
step++;
used[current]=true;
path.push_back(current);
//circle.push_back(current);
if(step==K){
step=0;
path.clear();
candle[current]=true;
if(existNext(current))
cout<<(char)(current+'A')<<" ";
}
}
}
else{
cout<<"/"<<(char)(current+'A')<<endl;
break;
}
}
}
*/
void process(){
	int mpos=(int)(M-'A'),tpos=(int)(T-'A'),step=0;
	while(true){
		int next=-1;
		for(unsigned int i=0;i<p[mpos].length();i++){
			if(!candle[p[mpos][i]-'A']&&(int)(p[mpos][i]-'A')!=tpos){
				next=(int)(p[mpos][i]-'A');
				break;
			}
		}
		if(next==-1){
           cout<<"/"<<(char)(mpos+'A')<<endl;
		   break;
		}
		tpos=mpos;
        mpos=next;
		step++;
		if(step==K){
           cout<<(char)(tpos+'A')<<" ";
		   candle[tpos]=true;
		   step=0;
		}
	}
}
int main(){
	while(getline(cin,s)){
		if(s[0]=='#')
			break;
		memset(candle,false,sizeof(candle));
		for(int i=0;i<26;i++)
			p[i]="";
		generateGraph();
		process();
	}
	return 0;
}