#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include <sstream>
#include <iomanip>
#include <map>
#define MAXIMUM 842150450
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva186.in");
ofstream fout("uva186.out");
#endif
int road[150][150];
int dist[150][150];
int path[150][150];
int info[4][2];
bool first=true;
map<string,int> cityIndex;
string cityName[150];
string highway[150][150];
string s;
int cityN=0;
int toInt(const string &num){
	istringstream iss(num);
	int rv;
	iss>>rv;
	return rv;
}
string toString(int num){
	ostringstream oss;
	oss<<num;
	return oss.str();
}
int getCityIndex(int start,int end){
	string name=s.substr(start,end-start+1);
	map<string,int>::iterator it=cityIndex.find(name);
	if(it==cityIndex.end()){
		cityIndex[name]=cityN;
		cityName[cityN]=name;
		cityN++;
		return cityN-1;
	}
	else{
		return it->second;
	}

}
void addPath(){
	int indexA=getCityIndex(info[0][0],info[0][1]);
	int indexB=getCityIndex(info[1][0],info[1][1]);
	int distance=toInt(s.substr(info[3][0],info[3][1]-info[3][0]+1));
	if(distance<road[indexA][indexB]){
		highway[indexA][indexB]=highway[indexB][indexA]=s.substr(info[2][0],info[2][1]-info[2][0]+1);
		road[indexA][indexB]=road[indexB][indexA]=distance;
	}
}
void createPath(){
	int last=-1,counter=0;
	for(unsigned int i=0;i<=s.length();i++)
		if(s[i]==','||i==s.length()){
			info[counter][0]=last+1;
			info[counter][1]=i-1;
			counter++;
			last=i;
		}
		addPath();
}
string generatePathStr(int start,int end){
	int intermediate=path[start][end];
	if(intermediate==MAXIMUM)
		return "";
	return generatePathStr(start,intermediate)+" "+toString(intermediate)+" "+generatePathStr(intermediate,end);
}
void floydWarshall(){
	memset(path,50,sizeof(path));
	memset(dist,50,sizeof(dist));
	for(int i=0;i<cityN;i++)
		for(int j=0;j<cityN;j++){
			if(i==j)
				dist[i][j]=0;
			else
				dist[i][j]=road[i][j];
		}
		for(int k=0;k<cityN;k++)
			for(int i=0;i<cityN;i++)
				for(int j=0;j<cityN;j++)
					if(dist[i][k]+dist[k][j]<dist[i][j]){
						dist[i][j]=dist[i][k]+dist[k][j];
						path[i][j]=k;
					}
}
string space(int n){
	string s;
	for(int i=0;i<n;i++)
		s=s+' ';
	return s;
}
void fillUp(string &s,int length){
	int need=length-s.length();
	s=s+space(need);
}
void displayNode(int first,int second){
	if(first==second)
		return;
	string cityA=cityName[first];
	string cityB=cityName[second];
	string high=highway[first][second];
	fillUp(cityA,21);
	fillUp(cityB,21);
	fillUp(high,11);
#ifdef DEBUG
	fout<<cityA<<cityB<<high<<setw(5)<<road[first][second]<<endl;
#else
	cout<<cityA<<cityB<<high<<setw(5)<<road[first][second]<<endl;
#endif
}
void display(){
	int pos=-1,lastNode;
	for(unsigned int i=0;i<s.length();i++){
		if(s[i]==','){
			pos=i;
			break;
		}
	}
	if(pos==-1)
		return;

	string cityA=s.substr(0,pos);
	string cityB=s.substr(pos+1,s.length()-pos-1);
	string fullpath=generatePathStr(cityIndex[cityA],cityIndex[cityB]);
#ifdef DEBUG
	
	fout<<endl<<endl;
	fout<<"From                 To                   Route      Miles"<<endl;
	fout<<"-------------------- -------------------- ---------- -----"<<endl;
#else

	cout<<endl<<endl;
	cout<<"From                 To                   Route      Miles"<<endl;
	cout<<"-------------------- -------------------- ---------- -----"<<endl;
#endif

	if(dist[cityIndex[cityA]][cityIndex[cityB]]!=MAXIMUM){
		lastNode=cityIndex[cityA];
		int last=-1;
		bool finished=true;
		for(unsigned int i=0;i<=fullpath.length();i++){
			if((i!=fullpath.length())&&(!isspace(fullpath[i]))){
				if(finished){
					last=i;
					finished=false;
				}
			}
			else if(!finished){
				int currentIndex=toInt(fullpath.substr(last,i-last));
				displayNode(lastNode,currentIndex);
				lastNode=currentIndex;
				finished=true;
			}
		}
		displayNode(lastNode,cityIndex[cityB]);
	}
#ifdef DEBUG
	fout<<"                                                     -----"<<endl;
	fout<<"                                          Total      "<<setw(5)<<dist[cityIndex[cityA]][cityIndex[cityB]];
	//if(!fin.eof())
		fout<<endl;
#else
	cout<<"                                                     -----"<<endl;
	cout<<"                                          Total      "<<setw(5)<<dist[cityIndex[cityA]][cityIndex[cityB]];
	if(!cin.eof())
		cout<<endl;
#endif

}
int main(){
	memset(road,50,sizeof(road));
#ifdef DEBUG
	while(getline(fin,s)){
#else
	while(getline(cin,s)){
#endif
		if(s.length()==0)
			break;
		createPath();
	}
	floydWarshall();
#ifdef DEBUG
	while(getline(fin,s)){
#else
	while(getline(cin,s)){
#endif
		display();
	}
	return 0;
}
