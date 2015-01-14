#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

//#define DEBUG
#ifdef DEBUG
ifstream fin("uva401.in");
ofstream fout("uva401.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}

char mapch[26]={'A','\0','\0','\0','3','\0','\0','H','I','L',
                '\0','J','M','\0','O','\0','\0','\0','2','T',
                'U','V','W','X','Y'},
	mapnum[10]={'\0','1','S','E','\0','Z','\0','\0','8','\0'};

bool pa(string s){
	for(unsigned int i=0;i<s.length()/2;i++)
		if(s[i]!=s[s.length()-i-1])
			return false;
	return true;
}
bool letter(char ch){
	return ('A'<=ch&&ch<='Z');
}
bool number(char ch){
	return ('1'<=ch&&ch<='9');
}
string reverse(string s){
	for(unsigned int i=0;i<s.length()/2;i++)
		swap(s[i],s[s.length()-i-1]);
	return s;
}
bool mirror(string s){
	string ori=s;
	for(unsigned int i=0;i<s.length();i++){
		if(letter(s[i])){
			if(mapch[s[i]-'A']!='\0')
				s[i]=mapch[s[i]-'A'];
			else
				return false;
		}
		else if(number(s[i])){
			if(mapnum[s[i]-'0']!='\0')
				s[i]=mapnum[s[i]-'0'];
			else
				return false;
		}
	}
	if(reverse(s)==ori)
		return true;
	else
		return false;
}
int main(){ 
	redirect();
	string s;
	bool p,m;
	while(cin>>s){
		p=pa(s);
		m=mirror(s);
		cout<<s<<" -- ";
		if(!p&&!m)
			cout<<"is not a palindrome."<<endl;
		else if(p&&!m)
			cout<<"is a regular palindrome."<<endl;
		else if(!p&&m)
			cout<<"is a mirrored string."<<endl;
		else
			cout<<"is a mirrored palindrome."<<endl;
		cout<<endl;

	}
	return 0;
}