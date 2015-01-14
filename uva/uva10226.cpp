#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva10226.in");
ofstream fout("uva10226.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
map<string,int> m;
int N,counter;
string s;
struct t{
	string s;
	int count;
};
vector<t> v;
bool sortf(const t &a,const t &b){
	return a.s<b.s;
}
int main(){
	redirect();
	cin>>N;
	getline(cin,s);
	getline(cin,s);
	for(int i=0;i<N;i++){
		m.clear();
		v.clear();
		counter=0;
		if(i>0)
			cout<<endl;
		while(getline(cin,s)){
			if(s=="")
				break;
			counter++;
			map<string,int>::iterator it=m.find(s);
			if(it==m.end()){
				m[s]=1;
			}
			else{
				it->second++;
			}
		}
		for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
			t newT={it->first,it->second};
			v.push_back(newT);
		}
		sort(v.begin(),v.end(),sortf);
		for(int i=0;i<v.size();i++){
			cout<<v[i].s<<" ";
			cout<<setprecision(4)<<fixed<<(float)(v[i].count*100)/(float)counter<<endl;
		}
	}
	return 0;
}