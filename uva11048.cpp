#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n,q;
string s;
vector<string> dict;

void check(string s){
  for(int j=0;j<dict.size();j++){
    if(dict[j]==s){
      cout<<s<<" is correct"<<endl;
      return;
    }
  }
  for(int j=0;j<dict.size();j++){
      string d=dict[j];
      int count=0;
      if(d.length()==s.length()){
	for(int k=0;k<d.size();k++){
	  count+=(d[k]!=s[k]);
	}
	if(count==1){
	  cout<<s<<" is a misspelling of "<<d<<endl;
	  return;
	}
	for(int k=0;k<s.size()-1;k++){
	  swap(s[k],s[k+1]);
	  if(s==d){
	    swap(s[k],s[k+1]);
	    cout<<s<<" is a misspelling of "<<d<<endl;
	    return;
	  }
	  swap(s[k],s[k+1]);
	}
      }
      else if(s.length()==d.length()-1){
	for(int k=0;k<d.length();k++){
	  //if((k-1>=0&&d[k-1]==d[k])||(k+1<d.length()&&d[k+1]==d[k])){
	    string tmp=d.substr(0,k)+d.substr(k+1,d.length()-k-1);
	    if(tmp==s){
	      cout<<s<<" is a misspelling of "<<d<<endl;
	      return;
	    }
	    // }
	}
      }
      else if(s.length()==d.length()+1){
	 for(int k=0;k<s.length();k++){
	   // if((k-1>=0&&s[k-1]==s[k])||(k+1<s.length()&&s[k+1]==s[k])){
	    string tmp=s.substr(0,k)+s.substr(k+1,s.length()-k-1);
	    if(tmp==d){
	      cout<<s<<" is a misspelling of "<<d<<endl;
	      return;
	    }
	    // }
	 }
      }
  }
  cout<<s<<" is unknown"<<endl;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s;
    dict.push_back(s);
  }
  cin>>q;
  for(int i=0;i<q;i++){
    cin>>s;
    check(s);
  }
  return 0;
}
