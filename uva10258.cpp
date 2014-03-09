#include <iostream>
#include <string.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva10258.in");
ofstream fout("uva10258.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
class Team{
public:
	int id;
	int pSolved;
	int tTime;
	int penalty[10];
	bool solved[10];
	Team(int id):id(id){
		pSolved=0;
		tTime=0;
		memset(penalty,0,sizeof(penalty));
		memset(solved,false,sizeof(solved));
	}
	void submit(int p,int t,string L){
		if(L=="C"){
			if(solved[p])
				return;
			solved[p]=true;
			pSolved++;
			tTime+=t+penalty[p];
		}
		else if(L=="I"){
			if(solved[p])
				return;
			penalty[p]+=20;
		}
	}
	void print(){
		cout<<id<<" "<<pSolved<<" "<<tTime<<endl;
	}
};

vector<Team> v;
map<int,int> toTeam;
int N;
string s;
void process(string s){
	istringstream iss(s);
	int id,p,t;
	string L;
	iss>>id>>p>>t>>L;
	map<int,int>::iterator it=toTeam.find(id);
	if(it==toTeam.end()){
		Team tmp(id);
		tmp.submit(p,t,L);
		toTeam[id]=v.size();
		v.push_back(tmp);
	}
	else{
		v[it->second].submit(p,t,L);
	}

}
bool compare(const Team &a,const Team &b){
	if(a.pSolved>b.pSolved)
		return true;
	else if(a.pSolved==b.pSolved){
		if(a.tTime<b.tTime)
			return true;
		else if(a.tTime==b.tTime){
			return a.id<b.id;
		}
	}
	return false;
}
int main(){
	redirect();
	cin>>N;
	getline(cin,s);
	for(int i=0;i<N;i++){
		v.clear();
		toTeam.clear();
		if(i>0)
			cout<<endl;
		if(i==0)
		 getline(cin,s);
		do{
			if(!getline(cin,s))
				break;
			if(s!="")
				process(s);
		}while(s!="");
		sort(v.begin(),v.end(),compare);
		for(int j=0;j<v.size();j++)
			v[j].print();
	}
	return 0;
}