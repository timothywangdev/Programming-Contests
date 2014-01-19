#include <iostream>
#include <fstream>
#include "string.h"
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
//#define DEBUG
#define MAXIMUM 10000
#ifdef DEBUG
ifstream fin("uva153.in");
ofstream fout("uva153.out");
#endif

void compress(string &base,string &target){
   short minChar=MAXIMUM;
   bool exist[26];
   memset(exist,false,sizeof(exist));
   for(int i=0;i<(int)base.length();i++){
	   exist[base[i]-'a']=true;
   }
   char map[26];
   int counter=0;
   for(int i=0;i<26;i++)
	   if(exist[i]){
           map[i]=(char)(counter+'a');
		   counter++;
	   }
   for(int i=0;i<(int)base.length();i++){
       base[i]=map[base[i]-'a'];
	   target[i]=map[target[i]-'a'];
   }
}
int findDiff(string &base,string &target){
    for(int i=0;i<(int)base.length();i++)
		if(base[i]!=target[i])
			return i;
	return (int)base.length();
}
long long factorial(int n){
  long long sum=1;
  for(int i=2;i<=n;i++)
	  sum*=i;
  return sum;
}
long long getSum(int n,int k){
   long long sum=1;
   for(int i=0;i<k;i++)
     sum*=n;
   return sum;
}
long long P(int n,int counterBase[]){
   int count[30];
   memset(count,0,sizeof(count));
   for(int i=1;i<=n;i++)
	   count[i]++;
   for(int i=0;i<26;i++)
	   for(int j=2;j<=counterBase[i];j++)
		   count[j]--;
   long long up=1,down=1;
   long long sum;
   for(int i=0;i<=n;i++){
	   if(count[i]==1)
		   up*=i;
	   if(count[i]<0){
		   sum=getSum(i,0-count[i]);
           if(up%sum==0)
			   up/=sum;
		   else
			   down*=sum;
	   }
   }
   return up/down;
}
long long getRepetitionSum(int counterBase[]){
	long long sum=1;
    for(int i=0;i<26;i++)
		sum*=factorial(counterBase[i]);
	return sum;
}
// Assume the two strings are the permutations from a single string
// Two strings only consist lower case letters
long long calculateDist(string base,string target){
	 if(base.length()==0&&target.length()==0)
		 return 1;
	 if(base==target)
		 return 1;
     // Step #1 Compress the two strings
	 compress(base,target);

	 // Step #2 Find the first different character
	 int pos=findDiff(base,target);

	 
	 int counterBase[26];
	 memset(counterBase,0,sizeof(counterBase));
	 for(int i=pos;i<(int)base.size();i++)
		 counterBase[(int)(base[i]-'a')]++;

	 // Step #4 Calculate the number of permutation between base and sorted(target)(exclusive)
	 long long sum=0;
	 for(char ch=base[pos];ch<target[pos];ch++){
         counterBase[(int)(ch-'a')]--;
         sum+=P((int)base.size()-pos-1,counterBase);
		 counterBase[(int)(ch-'a')]++;
	 }
     string targetSubStr=target.substr(pos+1,target.size()-pos);
	 sort(targetSubStr.begin(),targetSubStr.end());

	 return sum+calculateDist(targetSubStr,target.substr(pos+1,base.size()-pos));
}

string s,sorted;
int main(){
	while(cin>>s){
		if(s[0]=='#')
			break;
		sorted=s;
		sort(sorted.begin(),sorted.end());
		cout<<setw(10)<<calculateDist(sorted,s)<<endl;
	}
	return 0;
}