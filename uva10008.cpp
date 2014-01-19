#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "string.h"
#include <ctype.h>
#include <algorithm>
using namespace std;
#ifdef DEBUG
ifstream cin("uva10008.in");
ofstream cout("uva1008.out");
#endif
struct f{
   char ch;
   int sum;
   int pos;
};
int n;
string s;
vector<f> fs;
int counter[26];
int firstpos[26];

bool comp(const f &a,const f &b){
	if(a.sum>b.sum)
		return true;
	else if(a.sum==b.sum){
          if(a.ch<b.ch)
			  return true;
	}
    return false;
}
bool letter(char ch){
  return ('A'<=ch&&ch<='Z')||('a'<=ch&&ch<='z');
}
int main(){
   cin>>n;
   for(int i=0;i<=n;i++){
        string tmp;
		getline(cin,tmp);
		s=s+tmp;
   }
   memset(counter,0,sizeof(counter));
   for(int i=0;i<s.length();i++){
       if(letter(s[i])){
	   char h=s[i];
          h=toupper(h);
		  if(counter[(int)(h-'A')]==0){
             firstpos[(int)(h-'A')]=i;
		  }
          counter[(int)(h-'A')]++;
	   }
   }
   for(int i=0;i<26;i++){
	   if(counter[i]!=0){
		   f tmp;
		   tmp.ch=(char)(i+'A');
		   tmp.sum=counter[i];
		   tmp.pos=firstpos[i];
		   fs.push_back(tmp);
	   }
   }
   sort(fs.begin(),fs.end(),comp);
   for(unsigned int i=0;i<fs.size();i++){
	   cout<<fs[i].ch<<" "<<fs[i].sum<<endl;
   }
   return 0;

}