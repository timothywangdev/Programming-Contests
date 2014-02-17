#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <sstream>
using namespace std;
struct content{
	int count[26];
};
vector<string> dict,ori;
vector<int> rv;
vector<content> dict_count;
string tmp;
content current_content;
bool sort_f(const string s1,const string s2){
	return s1<s2;
}
bool allZero(){
	for(int i=0;i<26;i++)
		if(current_content.count[i]>=1)
			return false;
	return true;
}
bool viable(int k){
    for(int i=0;i<26;i++)
    	if(current_content.count[i]-dict_count[k].count[i]<0)
    		return false;
    return true;
}
void decrease(int k){
    for(int i=0;i<26;i++)
    	current_content.count[i]-=dict_count[k].count[i];
}
void increase(int k){
    for(int i=0;i<26;i++)
    	current_content.count[i]+=dict_count[k].count[i];
}
bool findInOri(string s){
	for(int i=0;i<ori.size();i++){
        if(ori[i]==s)
		 return true;
	}
	return false;
}
void output(){
	string s;
	for(int i=0;i<rv.size();i++){
		if(i!=0)
		 s=s+" ";
		s=s+dict[rv[i]];
		if(findInOri(dict[rv[i]]))
			return;
	}
	cout<<tmp<<" = "<<s<<endl;
}
void search(int index){
	if(allZero()){
		output();
		return;
	}
    for(int i=index+1;i<dict_count.size();i++){
        if(viable(i)){
        	decrease(i);
        	rv.push_back(i);
        	search(i);
        	rv.pop_back();
        	increase(i);
        }
    }
}
content generateContent(string s){
	content tmp;
	memset(tmp.count,0,sizeof(tmp.count));
	for(int i=0;i<s.size();i++){
		 if('A'<=s[i]&&s[i]<='Z')
	  		 tmp.count[s[i]-'A']++;
	}
    return tmp;
}
void generateOriVector(){
    istringstream iss(tmp);
    string s;
    while(iss>>s){
    	ori.push_back(s);
    }
}

int count[26];
int main(){
  while(getline(cin,tmp)){
	  if(tmp=="#")
		  break;
	  dict.push_back(tmp);
	  dict_count.push_back(generateContent(tmp));
  }
  sort(dict.begin(),dict.end(),sort_f);
  while(getline(cin,tmp)){
  	  if(tmp=="#")
  		  break;
   	  memset(current_content.count,0,sizeof(current_content.count));
   	  current_content=generateContent(tmp);
   	  ori.clear();
   	  generateOriVector();
  	  rv.clear();
  	  search(-1);
    }
  return 0;
}
