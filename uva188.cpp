#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "string.h"
using namespace std;
#ifdef DEBUG
ifstream fin("uva188.in");
ofstream fout("uva188.out");
#endif
string s;
unsigned int words[13],C;
int n;
unsigned int power(unsigned int base,unsigned int pow){
    unsigned int rv=1;
	for(int i=1;i<=pow;i++)
		rv*=base;
	return rv;
}
void add(string &word){
   for(unsigned int i=0;i<word.length();i++)
      words[n]+=power(32,word.length()-i-1)*(unsigned int)(word[i]-'a'+1);
   n++;
}
unsigned int result(int index){
    return (C/words[index])%n;
}
unsigned int next(int i,int j){
    return min((C/words[i]+1)*words[i],(C/words[j]+1)*words[j]);
}
void process(){
   memset(words,0,sizeof(words));
   istringstream iss(s);
   string tmp;
   n=0;
   while(iss>>tmp){
       add(tmp);
   }
   sort(words,words+n);
   C=words[0];
   bool jump;
   while(true){
      jump=false;
	  for(int i=0;i<n-1;i++){
		  if(jump)
			  break;
		  for(int j=i+1;j<n;j++)
			  if(result(i)==result(j)){
			     C=next(i,j);
                 jump=true;
				 break;
			  }
	  }
	  if(!jump)
		  break;
   }
   cout<<s<<endl<<C<<endl;
   if(!cin.eof())
	   cout<<endl;
}
int main(){

	while(getline(cin,s)){
        process();
	}
	return 0;
}