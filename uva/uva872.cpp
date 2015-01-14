#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

vector<int> outEdges[26];
int inde[26];
bool exist[26];
bool used[26];
int T;
string s;
vector<int> dis;
bool outputed;
void display(){
   for(int i=0;i<dis.size();i++){
	   if(i>0){
		   cout<<" ";
	   }
	   cout<<(char)(dis[i]+'A');
   }
   cout<<endl;
   outputed=true;
}
void changeDegree(int index,int offset){
	for(int i=0;i<outEdges[index].size();i++){
		inde[outEdges[index][i]]+=offset;
	}
}
void search(){
	bool found=true;
	for(int i=0;i<26;i++){
		if(exist[i]&&!used[i]){
			found=false;
		}
	}
	if(found){
       display();
	}
	for(int i=0;i<26;i++){
       if(exist[i]&&!used[i]&&inde[i]==0){
           used[i]=true;
           changeDegree(i,-1);
           dis.push_back(i);
           search();
           dis.pop_back();
           changeDegree(i,1);
           used[i]=false;
       }
	}
}
void setVar(string s){
  istringstream iss(s);
  char ch;
  while(iss>>ch){
	  exist[ch-'A']=true;
  }
}
void generateGraph(string s){
	istringstream iss(s);
	string ss;
	while(iss>>ss){
       outEdges[ss[0]-'A'].push_back((int)(ss[2]-'A'));
       inde[(int)(ss[2]-'A')]++;
	}
}
int main(){
    cin>>T;
    getline(cin,s);
    for(int i=0;i<T;i++){
    	if(i>0){
    		cout<<endl;
    	}
    	outputed=false;
        memset(inde,0,sizeof(inde));
        memset(exist,false,sizeof(exist));
        memset(used,false,sizeof(used));
        for(int i=0;i<26;i++){
        	outEdges[i].clear();
        }
        getline(cin,s);
        getline(cin,s);
        setVar(s);
        getline(cin,s);
        generateGraph(s);
        search();
        if(!outputed){
        	cout<<"NO"<<endl;
        }
    }
	return 0;
}

