#include <iostream>
#include <string>
using namespace std;

int T;
string s;
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>s;
    cout<<"Case "<<t+1<<": ";
    int sum=0;
    int counter=0;
    for(int i=0;i<s.size();i++){
      sum+=(int)(s[i]-'0');
      counter+=((int)(s[i]-'0')%3==0);
    }
    bool possible=false;
    int target;
    for(int i=0;i<s.size();i++){
      if((sum-(int)(s[i]-'0'))%3==0){
	possible=true;
	target=(int)(s[i]-'0');
	break;
      }
    }
    if(sum%3==0){
      if(counter%2==0){
	cout<<"T"<<endl;
      }
      else{
	cout<<"S"<<endl;
      }
    }
    else{
      if(!possible){
	cout<<"T"<<endl;
      }
      else{
	 if(counter%2==0){
	   cout<<"S"<<endl;
	 }
	 else{
	   cout<<"T"<<endl;
	 }
      }
    }
    
  }
  return 0;
}
