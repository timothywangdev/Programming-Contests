#include <iostream>
#include <string>
using namespace std;
string s;
int pow(int base,int num){
      int rv=1;
	  for(int i=0;i<num;i++)
		  rv*=base;
	  return rv;
}
int main(){
	while(getline(cin,s)){
        if(s=="0")
			break;
		int sum=0;
		for(unsigned int i=0;i<s.length();i++){
           sum+=(int)(s[i]-'0')*(pow(2,s.length()-i)-1);
		}
        cout<<sum<<endl;
	}
	return 0;
}