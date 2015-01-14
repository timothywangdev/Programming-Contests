#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include "string.h"
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva195.in");
ofstream fout("uva195.out");
#endif
int N;
vector<char> chs;
string s,last;
string searchStr;
int counter[52];
void search(int pos){
	if(pos==s.length()){
		cout<<searchStr<<endl;
		return;
	}
	for(unsigned int i=0;i<chs.size();i++){

		if('A'<=chs[i]&&chs[i]<='Z'){
			if(counter[chs[i]-'A']<=0)
				continue;
		}
		else if(counter[chs[i]-'a'+26]<=0)
			continue;

		if((searchStr.length()>pos&&searchStr[i]==chs[i]))
			continue;

		if('A'<=chs[i]&&chs[i]<='Z')
			counter[chs[i]-'A']--;
		else
			counter[chs[i]-'a'+26]--;
		searchStr=searchStr+chs[i];
		search(pos+1);
		searchStr.erase(searchStr.begin()+pos);
		if('A'<=chs[i]&&chs[i]<='Z')
			counter[chs[i]-'A']++;
		else
			counter[chs[i]-'a'+26]++;

	}
}
bool upper(char &ch){
    return ('A'<=ch&&ch<='Z');
}
bool lower(char &ch){
    return ('a'<=ch&&ch<='z');
}
bool comp(char a,char b){
	if(tolower(a)==tolower(b)){
        if(upper(a)&&lower(b))
			return true;
		return false;
	}
	else{
       if(tolower(a)<tolower(b))
		   return true;
	   return false;
	}
}
void process(){
	chs.clear();
	memset(counter,0,sizeof(counter));
	for(unsigned int i=0;i<s.length();i++){
		if('A'<=s[i]&&s[i]<='Z'){
			if(counter[s[i]-'A']>0){
				counter[s[i]-'A']++;
				continue;
			}
			counter[s[i]-'A']++;
		}
		else{
			if(counter[s[i]-'a'+26]>0){
				counter[s[i]-'a'+26]++;
				continue;
			}
			counter[s[i]-'a'+26]++;
		}

		chs.push_back(s[i]);
	}
	sort(chs.begin(),chs.end(),comp);
	search(0);
}
int main(){

	cin>>N;
	for(int i=0;i<N;i++){
		cin>>s;
		process();
	}
	return 0;
}