#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int N;
class test{
	public:
	string l;
	string r;
	string word;
	test(string l,string r,string word):l(l),r(r),word(word)
	{	
	}
};
vector<test*> tests;
string l,r,w;
char target=0;
string weight;
bool compare(const test* a,const test* b){
	if(a->word=="even"&&b->word!="even")
		return true;
	return false;
}
bool check(char ch,bool light){
	for(int i=0;i<3;i++){
		if(tests[i]->l.find(ch)!=string::npos){
			if(tests[i]->word=="even")
				return false;
			else if((tests[i]->word=="up"&&light)||(tests[i]->word=="down"&&!light)){
				return false;
			}
		}
		else if(tests[i]->r.find(ch)!=string::npos){
			if(tests[i]->word=="even")
				return false;
			else if((tests[i]->word=="down"&&light)||(tests[i]->word=="up"&&!light)){
				return false;
			}
		}
		else if(tests[i]->word!="even")
			return false;
	}
	return true;
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int i=0;i<tests.size();i++)
			delete tests[i];
		tests.clear();
		for(int j=0;j<3;j++){
		  cin>>l>>r>>w;
		  tests.push_back(new test(l,r,w));
		}
		for(int i=0;i<12;i++){
			char ch=(char)(i+'A');
			if(check(ch,true)){
				target=ch;
				weight="light";
				break;
			}
			else if(check(ch,false)){
				target=ch;
				weight="heavy";
				break;
			}
		}
		cout<<target<<" is the counterfeit coin and it is "<<weight<<"."<<endl;
	}
	return 0;
}