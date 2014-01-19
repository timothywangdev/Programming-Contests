//#define DEBUG

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "string.h"
using namespace std;

#ifdef DEBUG
ifstream fin("uva126.in");
ofstream fout("uva126.out");
#endif

int maxExpX,maxExpY;
string p[2];

struct NODE{
     int expX;
	 int expY;
	 int coe;
};

vector<NODE> poly[2],resultPoly;
vector<string> tokens;

void toknenize(string s){
   tokens.clear();
   unsigned int i=0;
   string current;
   while(i<s.length()){
	   if((s[i]=='-'||s[i]=='+')||i==0){
		   if(i==0&&!(s[i]=='-')){
			   i--;
			   current+='+';
		   }
		   else
		       current=s[i];
		   i++;
		   while(!(s[i]=='-'||s[i]=='+')&&i<s.length()){
			   current+=s[i];
			   i++;
		   }
		   tokens.push_back(current);
	   }		   
   }
}

int stringToNum(string s){
	int rv;
    stringstream convert(s);
	convert>>rv;
	return rv;
}

int toNumCoe(string s){
    if(s.length()==0)
		return 0;
	else if(s.length()==1){
        if(s[0]=='-')
		   return -1;
		else if(s[0]=='+')
		   return 1;
		else
		   return (int)(s[0]-'0');
	}
	else{
		if(s[0]=='-'){
			return 0-stringToNum(s.substr(1,s.length()-1));
		}
		else if(s[0]=='+'){
            return stringToNum(s.substr(1,s.length()-1));
		}
		else{
			return stringToNum(s);
		}
	}
}
int toNum(string s){
    if(s.length()==0)
		return 1;
	else if(s.length()==1){
        if(s[0]=='-')
		   return -1;
		else if(s[0]=='+')
		   return 1;
		else
		   return (int)(s[0]-'0');
	}
	else{
		if(s[0]=='-'){
			return 0-stringToNum(s.substr(1,s.length()-1));
		}
		else if(s[0]=='+'){
            return stringToNum(s.substr(1,s.length()-1));
		}
		else{
			return stringToNum(s);
		}
	}
}


string toString(int num){
	  if(abs(num)==1)
		  return "";
      stringstream convert;
	  convert<<abs(num);
	  return convert.str();
}


string toStringKeepOne(int num){
      stringstream convert;
	  convert<<abs(num);
	  return convert.str();
}

string space(int k){
    string s;
	for(int i=0;i<k;i++)
		s+=' ';
	return s;
}
NODE generateNode(string s){
     NODE tmp;
	 tmp.expX=tmp.expY=tmp.coe=-1;
	 string tmps;
	 bool existY,existX;
	 existX=existY=false;
	 unsigned int i=0;
	 while((s[i]=='-'||s[i]=='+'||('0'<=s[i]&&s[i]<='9'))&&(i<s.length())){
         tmps+=s[i];
		 i++;
	 }
	 tmp.coe=toNumCoe(tmps);
	 tmps="";
	 if(i!=s.length()){
		 if(s[i]=='y'){
			 existY=true;
             i++;
			 while(('0'<=s[i]&&s[i]<='9')&&i<s.length()){
                tmps+=s[i];
				i++;
			 }
			 tmp.expY=toNum(tmps);
			 tmps="";
			 if(i!=s.length()){
			    if(s[i]=='x')
                   existX=true;
                i++;
			    while(('0'<=s[i]&&s[i]<='9')&&i<s.length()){
                  tmps+=s[i];
				  i++;
			    }
				tmp.expX=toNum(tmps);
			 }
		 }
		 else if(s[i]=='x'){
			 existX=true;
             i++;
			 while(('0'<=s[i]&&s[i]<='9')&&i<s.length()){
                tmps+=s[i];
				i++;
			 }
			 tmp.expX=toNum(tmps);
			 tmps="";
			 if(i!=s.length()){
			    if(s[i]=='y')
                   existY=true;
                i++;
			    while(('0'<=s[i]&&s[i]<='9')&&i<s.length()){
                  tmps+=s[i];
				  i++;
			    }
				tmp.expY=toNum(tmps);
			 }
		 }
	 }
	 
	 if(existY&&tmp.expY==-1)
		 tmp.expY=1;
	 else if(!existY)
		 tmp.expY=0;

	 if(existX&&tmp.expX==-1)
		 tmp.expX=1;
	 else if(!existX)
		 tmp.expX=0;

     return tmp;
}

void generatePoly(int k){
    toknenize(p[k]);
    for(unsigned int i=0;i<tokens.size();i++)
		poly[k].push_back(generateNode(tokens[i]));
}
int findFactor(int expX,int expY){
      for(unsigned i=0;i<resultPoly.size();i++)
		  if(resultPoly[i].expX==expX&&resultPoly[i].expY==expY)
			  return i;
	  return -1;
}
void addPoly(int coe,int expX,int expY){
    int pos=findFactor(expX,expY);
	if(pos!=-1){
		resultPoly[pos].coe+=coe;
	}
	else{
       NODE newPoly;
	   newPoly.coe=coe;
	   newPoly.expX=expX;
	   newPoly.expY=expY;
	   resultPoly.push_back(newPoly);
	}
}
void multiply(){
   int newExpX,newExpY,newCoe;
   for(unsigned i=0;i<poly[0].size();i++)
	   for(unsigned j=0;j<poly[1].size();j++){
		   newExpX=poly[0][i].expX+poly[1][j].expX;
		   newExpY=poly[0][i].expY+poly[1][j].expY;
		   newCoe=poly[0][i].coe*poly[1][j].coe;
		   maxExpX=max(maxExpX,newExpX);
	       maxExpY=max(maxExpY,newExpY);
		   addPoly(newCoe,newExpX,newExpY);
	   }
}
bool comp(NODE a,NODE b){
	if(a.expX>b.expX)
		return true;
	else if(a.expX==b.expX && a.expY<b.expY)
		return true;
	else
		return false;
}
void display(){
   string up,down,tmp;
   if(resultPoly[0].coe!=0){
     if(resultPoly[0].coe<0){
	     if(resultPoly[0].expX||resultPoly[0].expY)
	       tmp=toString(resultPoly[0].coe);
	     else
	       tmp=toStringKeepOne(resultPoly[0].coe);

	       up=up+" "+space(tmp.size());
	       down=down+'-'+tmp;
	 }
     else{
         if(resultPoly[0].expX||resultPoly[0].expY)
	       tmp=toString(resultPoly[0].coe);
	     else
	       tmp=toStringKeepOne(resultPoly[0].coe);

	       up=up+space(tmp.size());
	       down=down+tmp;;
     }
   if(resultPoly[0].expX>0){
       tmp=toString(resultPoly[0].expX);
	   if(tmp.length()!=0){
         up=up+" "+tmp;
	     down=down+"x"+space(tmp.length());
	   }
   }
   if(resultPoly[0].expY>0){
       tmp=toString(resultPoly[0].expY);
	   if(tmp.length()!=0){
         up=up+" "+tmp;
	     down=down+"y"+space(tmp.length());
	   }
   }
   }

   for(unsigned int i=1;i<resultPoly.size();i++){
      if(resultPoly[i].coe==0) continue;
      if(resultPoly[i].expX>0||resultPoly[i].expY>0)
	     tmp=toString(resultPoly[i].coe);
	   else
	     tmp=toStringKeepOne(resultPoly[i].coe);

	  if(resultPoly[i].coe<0){
	    up=up+"   ";
	    down=down+" - ";
	  }
	  else{
	    up+="   ";
	    down=down+" + ";
	  }
	  up=up+space(tmp.length());
	  down=down+tmp;

      if(resultPoly[i].expX>0){
       tmp=toString(resultPoly[i].expX);
       //if(tmp.length()!=0){
         up=up+" "+tmp;
	     down=down+"x"+space(tmp.length());
	   //}
      }
	  if(resultPoly[i].expY>0){
       tmp=toString(resultPoly[i].expY);
       //if(tmp.length()!=0){
         up=up+" "+tmp;
	     down=down+"y"+space(tmp.length());
	  // }
      }
   }
#ifdef DEBUG
   fout<<up<<endl<<down<<endl;
#else
   cout<<up<<endl<<down<<endl;
#endif
}
int main(){
	#ifdef DEBUG
	while(fin>>p[0]){
		if(p[0]=="#")
			break;
		else
			fin>>p[1];
    #else
	while(cin>>p[0]){
		if(p[0]=="#")
			break;
		else
			cin>>p[1];
    #endif
		maxExpX=maxExpY=0;
		poly[0].clear();
		poly[1].clear();
		resultPoly.clear();
        generatePoly(0);
		generatePoly(1);
		multiply();
		sort(resultPoly.begin(),resultPoly.end(),comp);
		display();
	}
	return 0;
}
