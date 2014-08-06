#include <iostream>
#include <string>
using namespace std;
int T;
string s;
int counter(string k){
  int sum=0;
  int last=s.length()-1;
  while(last>=0){
    bool correct=true;
    for(int i=k.length()-1;i>=0;i--){
      if(last<0||k[i]!=s[last]){
	correct=false;
	break;
      }
      last--;
    }
    if(correct){
      sum++;
    }
    else{
      break;
    }
  }
  return sum;
}
void output(string k){
  for(int i=0;i<8;i++){
    cout<<k[i%k.length()];
  }
  cout<<"..."<<endl;
}
string rv;
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>s;
    for(int i=0;i<s.size();i++){
      string k=s.substr(s.length()-i-1,i+1);
      if(counter(k)==2){
	rv=k;
      }
    }
    output(rv);
  }
  return 0;
}
