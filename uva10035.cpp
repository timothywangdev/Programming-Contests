#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a,b;
int main(){
	while(cin>>a>>b){
		if(a=="0"&&b=="0")
			break;
		if(a.length()>b.length())
			swap(a,b);
		int count=0,last=0;
		for(int i=0;i<b.length();i++){
			int na;
			if(i<a.length())
			  na=a[a.length()-i-1]-'0';
			else
			  na=0;
			int nb=b[b.length()-i-1]-'0';
			int rv=na+nb+last;
			if(rv>=10){
				count++;
				last=1;
			}
			else
				last=0;
		}
		if(count==0)
			cout<<"No carry operation."<<endl;
		else if(count==1)
		    cout<<count<<" carry operation."<<endl;
		else
            cout<<count<<" carry operations."<<endl;
	}
	return 0;
}