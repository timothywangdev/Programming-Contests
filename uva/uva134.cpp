//#define DEBUG
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
#include <ctype.h>
using namespace std;
#ifdef DEBUG
ifstream fin("uva134.in");
ofstream fout("uva134.out");
#endif
istringstream iss;
string issString,word;
vector<string> sentence;
map<string,string> basic;

bool vowel(char ch){
   return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}
void translate(int i){
	

	if(!vowel(sentence[i][sentence[i].length()-1]))
            sentence[i]="NAM";
	else{
		if(basic.find(sentence[i])!=basic.end())
		   sentence[i]=basic[sentence[i]];
		else if(sentence[i].length()==5&&(
			   (!vowel(sentence[i][0])&&!vowel(sentence[i][1])&&vowel(sentence[i][2])&&!vowel(sentence[i][3])&&vowel(sentence[i][4]))||
			   (!vowel(sentence[i][0])&&vowel(sentence[i][1])&&!vowel(sentence[i][2])&&!vowel(sentence[i][3])&&vowel(sentence[i][4])))){
		   sentence[i]="PREDA";
		}
	}
}
#ifdef DEBUG
void display(){
   for(unsigned int i=0;i<sentence.size();i++)
	   fout<<sentence[i]<<" ";
   fout<<endl;
}
#endif
int findPos(int start,string target){
    int rv=-1;
	for(unsigned int i=(unsigned int)start;i<sentence.size();i++)
		if(sentence[i]==target){
           rv=i;
		   break;
		}
	return rv;
}


bool predstring(int start,int end){
     if(start>end)
		 return false;
	 for(int i=start;i<=end;i++)
		 if(sentence[i]!="PREDA")
			 return false;
	 return true;
}
bool predname(int start,int end){

	 if(start>end)
		 return false;

     if(start==end&&sentence[start]=="NAM")
		 return true;
	 if(sentence[start]=="LA")
		 if(predstring(start+1,end))
			 return true;
	 return false;
}
bool verbpred(int start,int end){

     if(start>end)
		 return false;

	 if(sentence[start]=="MOD")
		 if(predstring(start+1,end))
			 return true;
	 return false;
}
bool statement(){
     int MODpos=findPos(0,"MOD");
	 if(MODpos==-1)
		 return false;
	 int secondPrednamePos=findPos(MODpos+1,"LA");
	 if(secondPrednamePos==-1){
	   int NAMpos=findPos(MODpos+1,"NAM");
	   if(NAMpos==-1){
	     if(predname(0,MODpos-1)&&verbpred(MODpos,sentence.size()-1))
			 return true;
	   }
	   else{
         if(predname(0,MODpos-1)&&verbpred(MODpos,sentence.size()-2)&&NAMpos==sentence.size()-1)
			 return true;
	   }
	 }
	 else{
         if(predname(0,MODpos-1)&&verbpred(MODpos,secondPrednamePos-1)&&predname(secondPrednamePos,sentence.size()-1))
			 return true;
	 }
	 return false;
}
bool preds(int start,int end){

	if(start>end)
		 return false;
    
	int Apos=start,lastApos=start-1;

	while(Apos<=end){
         Apos=findPos(lastApos+1,"A");
		 if(Apos==-1){
             if(predstring(lastApos+1,end))
				 return true;
			 else
				 return false;
		 }
		 else{
             if(!predstring(lastApos+1,Apos-1))
				 return false;
			 lastApos=Apos;
		 }
	}
	return false;
}
bool predclaim(){
     int BApos=findPos(0,"BA");
	 if(BApos!=-1){
        if(predname(0,BApos-1)&&preds(BApos+1,sentence.size()-1))
			return true;
	 }
	 else{
         if(sentence[0]=="DA")
			 if(preds(1,sentence.size()-1))
				 return true;
	 }
	 return false;
}

bool specialCase(string s){
     for(unsigned int i=0;i<s.length();i++)
		 if(isspace(s[i]))
			 continue;
		 else if(s[i]=='.')
			 return true;
		 else
			 return false;
	 return false;
}

int main(){
	basic["a"]="A";
	basic["e"]="A";
	basic["i"]="A";
	basic["o"]="A";
	basic["u"]="A";

	basic["ga"]="MOD";
	basic["ge"]="MOD";
	basic["gi"]="MOD";
	basic["go"]="MOD";
	basic["gu"]="MOD";

	basic["ba"]="BA";
	basic["be"]="BA";
	basic["bi"]="BA";
	basic["bo"]="BA";
	basic["bu"]="BA";

	basic["da"]="DA";
	basic["de"]="DA";
	basic["di"]="DA";
	basic["do"]="DA";
	basic["du"]="DA";

	basic["la"]="LA";
	basic["le"]="LA";
	basic["li"]="LA";
	basic["lo"]="LA";
	basic["lu"]="LA";


    bool End=true;
	#ifdef DEBUG
	while(getline(fin,issString)){
    #else
	while(getline(cin,issString)){
    #endif
		if(End){
		  if(issString[0]=='#')
			  break;
		  sentence.clear();
		  if(specialCase(issString)){
			  #ifdef DEBUG
              fout<<"Bad!"<<endl;
			  #else
			  cout<<"Bad!"<<endl;
			  #endif
			  continue;
		  }
		  End=false;
		}
          iss.clear();
		  iss.str(issString);
		while(iss>>word){
		   if(word[word.length()-1]=='.'){
			   End=true;
			   if(word!="."){
			     word.erase(word.begin()+word.length()-1);
			     sentence.push_back(word);
			   }
			   break;
		   }
           sentence.push_back(word);
		}
		if(End){
          for(unsigned int i=0;i<sentence.size();i++)
              translate(i);
		  #ifdef DEBUG
		  if(statement()||predclaim())
			fout<<"Good"<<endl;
		  else
			fout<<"Bad!"<<endl;
		  #else
		  if(statement()||predclaim())
			cout<<"Good"<<endl;
		  else
			cout<<"Bad!"<<endl;
		  #endif
		}
	}

	return 0;
}

