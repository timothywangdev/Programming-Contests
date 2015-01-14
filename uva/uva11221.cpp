#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva11221.in");
ofstream fout("uva11221.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
string s,pa,vertical;
int N;
bool pal;
bool chara(char ch){
	return ('a'<=ch&&ch<='z');
}
bool pali(string ss){
	for(int i=0;i<ss.length()/2;i++){
		if(ss[i]!=ss[ss.length()-i-1]){
			return false;
		}
	}
	return true;
}
int main(){
	redirect();
	cin>>N;
	getline(cin,s);
	for(int i=0;i<N;i++){
		getline(cin,s);
		pa.clear();
		vertical.clear();
		pal=false;
		for(int j=0;j<s.length();j++){
			if(chara(s[j]))
				pa.push_back(s[j]);
		}
		int l=pa.length();
		int k=sqrt(l);
		if(k*k==l&&pali(pa)){
			for(int c=0;c<k;c++)
				for(int r=0;r<k;r++)
					vertical.push_back(pa[k*r+c]);
			if(pali(vertical))
				pal=true;
		}
		cout<<"Case #"<<i+1<<":"<<endl;
		if(pal)
			cout<<k<<endl;
		else
			cout<<"No magic :("<<endl;
	}
	return 0;
}