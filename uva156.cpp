#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "string.h"
#include "ctype.h"
using namespace std;
#ifdef DEBUG
ifstream fin("uva156.in");
ofstream fout("uva156.out");
#endif
string s;
vector<string> dict;
bool Anana[1000000];

bool anagrams(int i,int j){
   if(dict[i].length()!=dict[j].length())
	   return false;
   short counter[26];
   memset(counter,0,sizeof(counter));
   for(unsigned int k=0;k<dict[i].length();k++){
       counter[tolower(dict[i][k])-'a']++;
       counter[tolower(dict[j][k])-'a']--;
   }
   for(int k=0;k<26;k++)
	   if(counter[k]>0)
		   return false;
   return true;
}
int main(){
	while(cin>>s){
		if(s[0]=='#')
			break;
		dict.push_back(s);
	}
    sort(dict.begin(),dict.end());
	memset(Anana,true,sizeof(Anana));

	for(unsigned int i=0;i<dict.size();i++){
         if(!Anana[i])
			 continue;
		 if(dict[i].length()>1){
		   for(unsigned int j=0;j<dict.size();j++)
			 if(i!=j&&anagrams(i,j)){
                Anana[i]=false;
				Anana[j]=false;
				break;
			 }
		 }
		 if(Anana[i])
			 cout<<dict[i]<<endl;
	}

	return 0;
}