#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <locale>  
using namespace std;

#ifdef DEBUG
ifstream fin("uva123.in");
ofstream fout("uva123.out");
#endif

struct KEY{
	string w;
	int pos;
	int title;
};

istringstream iss;
vector<vector<string> > titles;
vector<KEY> keys;
map<string,bool> ignores;

string tmp,key;
int counter;



KEY *keyptr;
bool comp(KEY a,KEY b){
	return a.w<b.w;
}
string lowercase(string s){
	for(unsigned int i=0;i<s.length();i++)
		s[i]=tolower(s[i]);
	return s;
}
string uppercase(string s){
	for(unsigned int i=0;i<s.length();i++)
		s[i]=toupper(s[i]);
	return s;
}
void display(int k){
	int titleIndex=keys[k].title;
	for(unsigned int i=0;i<titles[titleIndex].size();i++){
		if(i==keys[k].pos){
			cout<<uppercase(titles[titleIndex][i]);
		}
		else{
			cout<<lowercase(titles[titleIndex][i]);
		}
		if(i<titles[titleIndex].size()-1)
			cout<<" ";
		else
			cout<<endl;
	}
}

int main(){
	while(true){
		getline(cin,tmp);
		if(tmp=="::")
			break;
		ignores[lowercase(tmp)]=true;
	}
	while(getline(cin,tmp)){
	   if(!(('a'<=tmp[0]&&tmp[0]<='z')||('A'<=tmp[0]&&tmp[0]<='Z')))
		   break;
		titles.push_back(vector<string>() );
		iss.str(tmp);
		counter=0;
		while(iss>>key){
			titles[titles.size()-1].push_back(key);
			key=lowercase(key);
			if(ignores.find(key)==ignores.end()){
				keyptr=new KEY;
				keyptr->title=titles.size()-1;
				keyptr->w=key;
				keyptr->pos=counter;
				keys.push_back(*keyptr);
			}
			counter++;
		}
		iss.clear();
	}
	stable_sort(keys.begin(),keys.end(),comp);

	for(unsigned int i=0;i<keys.size();i++)
		display(i);
	return 0;
}

