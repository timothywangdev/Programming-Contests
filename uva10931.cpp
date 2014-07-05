#include <iostream>
#include <bitset>
#include <string>
using namespace std;

unsigned long long  N;
int main(){
  while(cin>>N){
    if(!N)break;
    bitset<32> b(N);
    string s=b.to_string();
    int counter=0;
    int index=-1;
    for(int i=0;i<s.size();i++){
      counter+=(s[i]=='1');
      if(s[i]=='1'&&index==-1){
	index=i;
      }
    }
    s=s.substr(index,s.length()-index);
    cout<<"The parity of "<<s<<" is "<<counter<<" (mod 2)."<<endl;
  }
  return 0;
}
