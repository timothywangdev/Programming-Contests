#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
string s,pa;
bool chara(char ch){
	return ('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z');
}
int main(){

	while(getline(cin,s)){
		if(s=="DONE")
			break;
		pa.clear();
		for(int i=0;i<s.length();i++){
			if(chara(s[i]))
				pa.push_back(tolower(s[i]));
		}
		bool pal=true;
		for(int i=0;i<pa.length()/2;i++){
			if(pa[i]!=pa[pa.length()-i-1]){
				pal=false;
				break;
			}
		}
		if(pal)
			cout<<"You won't be eaten!"<<endl;
		else
			cout<<"Uh oh.."<<endl;
	}
	return 0;
}