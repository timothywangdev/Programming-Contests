#include <iostream>

using namespace std;

int counter=0;
int a,b;
int main(){
  while(cin>>a>>b){
    if(!a&&!b)break;
    counter++;
    cout<<"Case "<<counter<<": ";
    if(a<=b){
      cout<<"0"<<endl;
    }
    else{
      int k=(a-b)%b==0?(a-b)/b:(a-b)/b+1;
      if(k<=26){
	cout<<k<<endl;
      }
      else{
	cout<<"impossible"<<endl;
      }
    }
  }
  return 0;
}
