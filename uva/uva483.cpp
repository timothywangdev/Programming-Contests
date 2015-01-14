#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;
#ifdef DEBUG
ifstream cin("uva483.in");
ofstream cout("uva483.out");
#endif
vector<string> word;
string s;
string reverse(string &s){
     string tmp="";
	 for(unsigned int i=0;i<s.length();i++)
		 tmp=tmp+s[s.length()-i-1];
	 return tmp;
}

void createWords(){
   int last=-1;
   bool cinished=true;
   for(unsigned int i=0;i<=s.length();i++){
	   if(cinished){
		   if(!isspace(s[i])){
               cinished=false;
			   last=i;
		   }
	   }
	   else{
		   if(i==s.length()||isspace(s[i])){
               cinished=true;
			   word.push_back(s.substr(last,i-last));
		   }
	   }
   }
}
int main(){
	while(getline(cin,s)){
		word.clear();
        createWords();
		for(unsigned int i=0;i<word.size();i++){
            cout<<reverse(word[i]);
			if(i!=word.size()-1)
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}