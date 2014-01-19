#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#ifdef DEBUG
ifstream cin("uva424.in");
ofstream cout("uva424.out");
#endif
class longint{
public:
	string s;
	longint(string s):s(s){}
	longint operator+(longint &other){
		int maxl=max(s.length(),other.s.length());
        longint tmp("");
		int last=0;
		for(int i=0;i<maxl+1;i++){
            if(i==maxl&&last==0)
				break;
			int a=(i<s.length())?(s[i]-'0'):0;
			int b=(i<other.s.length())?(other.s[i]-'0'):0;
			int rv=a+b+last;
			if(rv>=10){
                tmp.s=tmp.s+(char)(rv%10+'0');
				last=rv/10;
			}
			else{
                tmp.s=tmp.s+(char)(rv+'0');
				last=0;
			}
		}
		return tmp;
	}
};
string reverse(string &s){
     string tmp="";
	 for(unsigned int i=0;i<s.length();i++)
		 tmp=tmp+s[s.length()-i-1];
	 return tmp;
}
string s;
int main(){
	longint sum("");
	while(getline(cin,s)){
        if(s=="0")
			break;
		longint tmp(reverse(s));
        sum=sum+tmp;
	}
	cout<<reverse(sum.s)<<endl;
	return 0;
}