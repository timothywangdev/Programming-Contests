#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "string.h"
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva169.in");
ofstream fout("uva169.out");
#endif
string s;
string input;
bool exist[26];
struct Info{
	int range[2];
	bool trueWord;
};
class Word{
public:
#ifdef DEBUG
	string ori;
#endif
	short unique[26];
	int start;
	int end;
	int length;
	bool first;
	Info *info;
	Word(int sp,int ep):start(sp),end(ep){
		first=false;
		length=ep-sp+1;
		info=NULL;
		memset(unique,0,sizeof(unique));
		for(int i=start;i<=end;i++)
			unique[s[i]-'a']++;
#ifdef DEBUG
		for(int i=start;i<=end;i++)
			ori=ori+s[i];
#endif
	}
	~Word(){
        if(first)
			delete info;
	}
	bool operator==(const Word &other){
		for(int i=0;i<26;i++)
			if(unique[i]!=other.unique[i])
				return false;
		return true;
	}
	bool operator<(const Word &other){
		for(int i=0;i<26;i++)
			if(unique[i]<other.unique[i])
				return true;
			else if(unique[i]>other.unique[i])
				return false;
		return start<other.start;
	}
	bool exist(Word *other,int s1,int e1,int s2,int e2){
		for(int i=0;i<e1-s1+1;i++)
			if(s[s1+i]!=s[s2+i])
				return false;
		return true;
	}
	bool find(Word *other){
		string tmp=s.substr(start,end-start+1);
		string target=s.substr(other->start,(other->end)-(other->start)+1);
		return (tmp.find(target)!=string::npos||target.find(tmp)!=string::npos);
	}
};
vector<Word*> words;
bool validChar(char &ch){
	return ('a'<=ch&&ch<='z');
}
void createCleanString(){
	for(unsigned int i=0;i<input.length();i++)
		if(validChar(input[i])){
			s=s+input[i];
			exist[input[i]-'a']=true;
		}
}
void addWord(int start,int end){
	if(end-start<1)
		return;
	if(end-start+1>250)
		return;
	words.push_back(new Word(start,end));
}
void findWordsBySpacer(char spacer){
	int lastPos=-1;
	for(unsigned int i=0;i<s.length();i++){
		if(s[i]==spacer){
			addWord(lastPos+1,i-1);
			lastPos=i;
		}
		else if(i==s.length()-1){
			addWord(lastPos+1,i);
		}
	}
}
void findWords(){
	for(int i=0;i<26;i++)
		if(exist[i])
			findWordsBySpacer((char)(i+'a'));
}
bool comp(Word *a,Word *b){
	return (*a)<(*b);
}
void sortWords(){
	sort(words.begin(),words.end(),comp);
	unsigned int last=-1;
	for(unsigned int i=0;i<words.size();i++)
		if(i>=1&&(*words[i-1])==(*words[i])){
			words[i]->info=words[i-1]->info;
			words[i]->info->range[1]=i;
			words[i-1]->info->trueWord=words[i]->info->trueWord=true;
		}
		else{
			words[i]->first=true;
			words[i]->info=new Info;
			words[i]->info->range[0]=i;
			words[i]->info->trueWord=false;
		}
}
bool overlap(Word *a,Word *b){
	/*
	//a<->b
	for(int i=a->end;i>=a->start+1;i--)
		if(b->start+a->end-i<b->end)
			if(a->exist(b,i,a->end,b->start,b->start+a->end-i))
				return true;
	//b<->a
	for(int i=b->end;i>=b->start+1;i--)
		if(a->start+b->end-i<a->end)
			if(b->exist(a,i,b->end,a->start,a->start+b->end-i))
				return true;
	//if(a->find(b))
	//	return true;
	*/
	if((b->start<=a->start&&a->start<=b->end)||(b->start<=a->end&&a->end<=b->end))
		return true;
	return false;
}
bool byStartingPos(Word *a,Word *b){
	if(a->end<b->start)
	 return a->start<b->start;
	else
	 return a->end<b->end;
}
void findRealWords(){
	vector<Word*> filter;
	vector<Word*> real;
	for(unsigned int i=0;i<words.size();i++){
		if(words[i]->info->trueWord){
			filter.push_back(words[i]);
		}
	}
	for(unsigned int i=0;i<words.size();i++){
		if(words[i]->info->trueWord){
			words[i]->info->trueWord=false;
		}
	}
	for(unsigned int i=0;i<filter.size();i++){
		if(i>=1&&(*filter[i-1])==(*filter[i])){
			filter[i]->info->range[1]=i;
		}
		else{
			filter[i]->info->range[0]=i;
		}
	}
	for(unsigned int i=0;i<filter.size();i++){
		for(unsigned int j=i+1;j<filter.size();)
			if((filter[i]->info!=filter[j]->info)&&overlap(filter[i],filter[j])){
			//if(overlap(filter[i],filter[j])){
				filter[i]->info->trueWord=filter[j]->info->trueWord=true;
				j=filter[j]->info->range[1]+1;
			}
			else{
				j++;
			}
	}
	for(unsigned int i=0;i<filter.size();){
		if(filter[i]->info->trueWord){
			real.push_back(filter[i]);
			i=filter[i]->info->range[1]+1;
		}
		else{
			i++;
		}
	}
	sort(real.begin(),real.end(),byStartingPos);
#ifdef DEBUG
	for(unsigned int i=0;i<real.size();i++){
		//fout<<real[i]->ori<<endl;
		for(int j=real[i]->start;j<=real[i]->end;j++)
			fout<<s[j];
		fout<<endl;
	}
	fout<<"*"<<endl;
#else
for(unsigned int i=0;i<real.size();i++){
		//fout<<real[i]->ori<<endl;
		for(int j=real[i]->start;j<=real[i]->end;j++)
			cout<<s[j];
		cout<<endl;
	}
	cout<<"*"<<endl;
#endif
}
void process(){
	findWords();
	sortWords();
	findRealWords();
}
int main(){
	memset(exist,false,sizeof(exist));
	bool merge=false;
	#ifdef DEBUG
	while(getline(fin,input)){
	#else
	while(getline(cin,input)){
	#endif
		if(input[0]=='#'&&input.size()==1&&!merge)
			break;
		createCleanString();
		// END
		if(input.size()==0||input[input.length()-1]!='-'){
			process();
			s="";
			/*
			for(unsigned int i=0;i<words.size();i++)
				delete words[i];
				*/
			words.clear();
			memset(exist,false,sizeof(exist));
			input.clear();
			merge=false;
		}
		else if(input.size()!=0||input[input.length()-1]!='-'){
            merge=true;
		}
	}
	return 0;
}