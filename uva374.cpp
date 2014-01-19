#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva374.in");
ofstream fout("uva374.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
vector<int> pattern;
vector<int> pre;
bool exist[46341];
int pos[46341];
long long B,P,M;

void findPattern(){
	pattern.clear();
	pre.clear();
	memset(exist,false,sizeof(exist));
	exist[1]=true;
	pattern.push_back(1);
	long long rv=1;
	while(true){
		rv=(rv%M*B%M)%M;
		if(exist[rv])
			break;
		exist[rv]=true;
		pos[rv]=pattern.size();
		pattern.push_back(rv);
	}
	int fpos=pos[rv];
	if(fpos>0){
	 pre.assign(pattern.begin(),pattern.begin()+fpos);
	 pattern.erase(pattern.begin(),pattern.begin()+fpos);
	}

}
int main(){
	redirect();
	while(cin>>B>>P>>M){
		if(B==0){
			cout<<"0"<<endl;
			continue;
		}
		findPattern();
		int presize=0;
		presize=pre.size();

		if(P<presize){
			cout<<pre[P]<<endl;
		}
		else{
		    cout<<pattern[(P-presize)%pattern.size()]<<endl;
		}
	}
	return 0;
}
