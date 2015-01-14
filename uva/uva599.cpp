#include <iostream>
#include <string>
#include <string.h>
using namespace std;

bool m[26][26];
bool exist[26];
bool searched[26];
int degree[26];
string s;
int N,acrons,trees;
int search(int currentVertex,int &totalPoints){
	searched[currentVertex]=true;
	int totalDegrees=degree[currentVertex];
	totalPoints++;
	for(int i=0;i<26;i++){
		if(exist[i]&&!searched[i]&&m[currentVertex][i]){
			totalDegrees+=search(i,totalPoints);
		}
	}
	return totalDegrees;
}
int main(){
	cin>>N;
	getline(cin,s);
	for(int i=0;i<N;i++){
		acrons=0;
		trees=0;
		memset(m,false,sizeof(m));
		memset(degree,0,sizeof(degree));
		memset(searched,false,sizeof(searched));
		memset(exist,false,sizeof(exist));
		while(getline(cin,s)){
			if(s[0]=='*')
				break;
			m[s[1]-'A'][s[3]-'A']=true;
            m[s[3]-'A'][s[1]-'A']=true;
			degree[s[1]-'A']++;
			degree[s[3]-'A']++;
		}
		getline(cin,s);
		for(int j=0;j<s.size();j+=2){
			exist[s[j]-'A']=true;
		}
		for(int j=0;j<26;j++){
			if(exist[j]&&!searched[j]){
				int totalPoints;
				int totalDegree=search(j,totalPoints);
				int path=totalDegree/2;
				if(path==0)
					acrons++;
				else if(path=totalPoints-1)
					trees++;
			}
		}
		cout<<"There are "<<trees<<" tree(s) and "<<acrons<<" acorn(s)."<<endl;
	}
	return 0;
}