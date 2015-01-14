//#define DEBUG
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#ifdef DEBUG
ifstream fin("uva110.in");
ofstream fout("uva110.out");
#endif
string w[8]={"a","b","c","d","e","f","g","h"};
int N,M;
string space(int n){
  string tmp="";
  /*
  for(int i=0;i<n;i++)
	  tmp+=' ';
  */
  return tmp;
}

string putAfter(string s,int target,int after){
     if(after==s.length()-1)
		 return s+w[target];
	 else if(after==-1)
		 return w[target]+s;
	 else{
         s.insert(after+1,w[target]);
		 return s;
	 }
}

string printS(string s){
    string tmp="";
	if(s.length()==1){
       tmp=s[0];
	   return tmp;
	}
	for(int i=0;i<(int)s.length()-1;i++)
		tmp=tmp+s[i]+',';
	tmp=tmp+s[s.length()-1];
	return tmp;
}
void print(string s,int current){
	if(current<N){
		  #ifdef DEBUG
		  fout<<space(current)<<"if "<<s[s.length()-1]<<" < "<<w[current]<<" then"<<endl;
          #else
          cout<<space(current)<<"if "<<s[s.length()-1]<<" < "<<w[current]<<" then"<<endl;
          #endif
          print(putAfter(s,current,s.length()-1),current+1);
          
		  for(int i=(int)s.length()-2;i>=0;i--){
             #ifdef DEBUG
             fout<<space(current)<<"else if "<<s[i]<<" < "<<w[current]<<" then"<<endl;
			 #else
		     cout<<space(current)<<"else if "<<s[i]<<" < "<<w[current]<<" then"<<endl;
			 #endif
             print(putAfter(s,current,i),current+1);
		  }
          #ifdef DEBUG
		  fout<<space(current)<<"else "<<endl;
          #else
          cout<<space(current)<<"else "<<endl;
		  #endif
          print(putAfter(s,current,-1),current+1);  
		  
	}
	else{
		  #ifdef DEBUG
          fout<<space(current)<<"writeln("<<printS(s)<<")"<<endl;
          #else
		  cout<<space(current)<<"writeln("<<printS(s)<<")"<<endl;
		  #endif
	}
}

void process(int n){
	string s=w[0],variables;
	#ifdef DEBUG
	fout<<"program sort(input,output);"<<endl;
	fout<<"var"<<endl;
	for(int i=0;i<n;i++)
		variables=variables+w[i];
	fout<<printS(variables)<<" : integer;"<<endl;
	fout<<"begin"<<endl;
	fout<<"  readln("<<printS(variables)<<");"<<endl;
    #else
	cout<<"program sort(input,output);"<<endl;
	cout<<"var"<<endl;
	for(int i=0;i<n;i++)
		variables=variables+w[i];
	cout<<printS(variables)<<" : integer;"<<endl;
	cout<<"begin"<<endl;
	cout<<"  readln("<<printS(variables)<<");"<<endl;
    #endif

	if(n>=2){
     print(s,1);
	}
	else
	 #ifdef DEBUG
	 fout<<"writeln(a)"<<endl;
	 #else
	 cout<<"writeln(a)"<<endl;
     #endif

	#ifdef DEBUG
	fout<<"end."<<endl;
	#else
    cout<<"end."<<endl;
	#endif
}
int main(){
	#ifdef DEBUG
    fin>>M;
	#else
    cin>>M;
	#endif
	for(int i=0;i<M-1;i++){
	 #ifdef DEBUG
	 fin>>N;
	 #else
	 cin>>N;
	 #endif
     process(N);
	 #ifdef DEBUG
	 fout<<endl;
	 #else
	 cout<<endl;
	 #endif
	}
    #ifdef DEBUG
	fin>>N;
	#else
	cin>>N;
	#endif
    process(N);
	return 0;
}