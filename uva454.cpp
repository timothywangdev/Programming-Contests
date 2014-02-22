#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva454.in");
ofstream fout("uva454.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
struct counter{
	short c[26],u[26];
};
int N;
string s;
vector<string> dict;
vector<counter> counters;
bool first;
bool chara(char ch){
	return ('a'<=ch&&ch<='z');
}
counter getCounter(int index){
	counter newCounter;
	memset(newCounter.c,0,sizeof(newCounter.c));
	memset(newCounter.u,0,sizeof(newCounter.u));
	for(int i=0;i<dict[index].length();i++){
		if('a'<=dict[index][i]&&dict[index][i]<='z'){
			newCounter.c[dict[index][i]-'a']++;
		}
		else if('A'<=dict[index][i]&&dict[index][i]<='Z'){
			newCounter.u[dict[index][i]-'A']++;
		}
	}
	return newCounter;
}
bool anagram(int i,int j){
	for(int k=0;k<26;k++)
		if(counters[i].c[k]!=counters[j].c[k]||counters[i].u[k]!=counters[j].u[k])
			return false;
	return true;
}
bool outputed=false;
int main(){
	redirect();
	cin>>N;
	getline(cin,s);
	getline(cin,s);
	for(int i=0;i<N;i++){
		if(i>0)
			cout<<endl;
		dict.clear();
		counters.clear();
		while(getline(cin,s)){
			if(s==""){
				break;
			}
			dict.push_back(s);
		}
		sort(dict.begin(),dict.end());
		for(int i=0;i<dict.size();i++)
			counters.push_back(getCounter(i));
		for(int i=0;i<dict.size()-1;i++)
			for(int j=i+1;j<dict.size();j++)
				if(anagram(i,j)){
					cout<<dict[i]<<" = "<<dict[j]<<endl;
				}
	}
	return 0;
}