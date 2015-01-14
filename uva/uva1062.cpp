#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<stack<char> > v;
string s;
int counter=0;
int main(){
	while(getline(cin,s)){
		if(s=="end")
			break;
		v.clear();
		counter++;
		cout<<"Case "<<counter<<": ";
	    for(int i=0;i<s.length();i++){
			bool found=false;
			for(int j=0;j<v.size();j++)
				if(v[j].top()>=s[i]){
					found=true;
					v[j].push(s[i]);
					break;
				}
			if(!found){
				stack<char> st;
				st.push(s[i]);
				v.push_back(st);
			}
		}
		cout<<v.size()<<endl;
	}
	return 0;
}