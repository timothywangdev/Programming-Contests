#include <iostream>
#include <string>
using namespace std;
bool letter(char ch){
	return ('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z');
}
int main(){
	string s;
	while(getline(cin,s)){
		int count=0;
		bool finished=true;
		for(unsigned int i=0;i<=s.length();i++){
			if((i==s.length())||(!letter(s[i]))){
				if(!finished){
					finished=true;
					count++;
				}
			}
			else if(finished){
				finished=false;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}