#include <iostream>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva10507.in");
ofstream fout("uva10507.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
string s;
int SleepArea,M;
bool exist[26];
bool active[26];
bool m[26][26];
vector<int> changeList;
bool changed;
int year;
int main(){
	redirect();
	while(cin>>SleepArea>>M){
		memset(exist,false,sizeof(exist));
		memset(active,false,sizeof(active));
		memset(m,false,sizeof(m));
		getline(cin,s);
		getline(cin,s);
		for(int i=0;i<s.size();i++){
			exist[s[i]-'A']=true;
			active[s[i]-'A']=true;
		}
		SleepArea-=(int)s.size();
		for(int i=0;i<M;i++){
			getline(cin,s);
			exist[s[0]-'A']=exist[s[1]-'A']=true;
			m[s[0]-'A'][s[1]-'A']=m[s[1]-'A'][s[0]-'A']=true;
		}
		year=0;
		if(SleepArea>0){
			changed=true;
			for(year=1;changed;year++){
				changed=false;
				for(int i=0;i<26;i++)
					if(exist[i]&&!active[i]){
						int counter=0;
						for(int j=0;j<26;j++)
							if(exist[j]&&active[j]&&m[i][j])
								counter++;
						if(counter>=3)
							changeList.push_back(i);
					}
					if(changeList.size())
						changed=true;
					for(int i=0;i<changeList.size();i++)
						active[changeList[i]]=true;
					SleepArea-=changeList.size();
					changeList.clear();
					if(SleepArea==0)
						break;
			}
		}
		if(SleepArea==0)
			cout<<"WAKE UP IN, "<<year<<", YEARS"<<endl;
		else
			cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
	}
	return 0;
}