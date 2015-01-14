#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char,int> price;
string s;

int N,M,p,sum;
char ch;
map<char,int>::iterator it;
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>M;
		sum=0;
		price.clear();
		for(int j=0;j<M;j++){
			cin>>ch>>p;
			price[ch]=p;
		}
		cin>>M;
		getline(cin,s);
		for(int j=0;j<M;j++){
			getline(cin,s);
			for(int k=0;k<s.length();k++){
				it=price.find(s[k]);
				if(it!=price.end())
				 sum+=it->second;
			}
		}
		int dollar=sum/100;
		int cent=sum-dollar*100;
		cout<<dollar<<".";
		if(cent<10)
			cout<<"0";
		cout<<cent;
		cout<<"$"<<endl;
	}
	return 0;
}