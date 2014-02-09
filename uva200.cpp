#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva200.in");
ofstream fout("uva200.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}

vector<string> ss;
int inDegree[26];
vector<int> ne[26];
bool exist[26];
bool notexist(int i,int k){
    for(int j=0;j<ne[i].size();j++)
		if(ne[i][j]==k)
			return false;
	return true;
}
void diff(string s1,string s2){
	int minL=min(s1.size(),s2.size());
	for(int i=0;i<minL;i++){
       if(s1[i]!=s2[i]){
    	 if(notexist((int)(s1[i]-'A'),(int)(s2[i]-'A'))){
           ne[s1[i]-'A'].push_back((int)(s2[i]-'A'));
		 }
         break;
       }
	}
}
bool f(const int &a,const int &b){
	//cout<<(char)(a+'A')<<"<"<<(char)(b+'A');
	for(int i=0;i<ne[a].size();i++)
		if(ne[a][i]==b){
			//cout<<" true"<<endl;
			return true;
		}
	//cout<<" false"<<endl;
	return false;
}
int main(){
	redirect();
	string s;
	memset(inDegree,0,sizeof(inDegree));
	memset(exist,false,sizeof(exist));
    while(cin>>s){
    	if(s=="#")
    		break;
      ss.push_back(s);
      for(int i=0;i<s.size();i++)
    	  exist[s[i]-'A']=true;
      if(ss.size()>=2){
    	  for(int i=0;i<ss.size()-1;i++)
    	    diff(ss[i],ss[ss.size()-1]);
      }
    }
	for(int i=0;i<26;i++)
    	if(exist[i]){
			int oldSize=ne[i].size();
			for(int j=0;j<oldSize;j++){
				for(int k=0;k<ne[ne[i][j]].size();k++)
					ne[i].push_back(ne[ne[i][j]][k]);
			}
		}
    vector<int> e;
    for(int i=0;i<26;i++)
    	if(exist[i])
    		e.push_back(i);
    sort(e.begin(),e.end(),f);
    for(int i=0;i<e.size();i++)
    	cout<<(char)(e[i]+'A');
    cout<<endl;
	return 0;
}
