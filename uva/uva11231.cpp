#include <iostream>

using namespace std;

long long n,m,c;
int main(){
  while(cin>>n>>m>>c){
    if(!n&&!m&&!c)break;
    long long a=(n-8+1);
    long long b=(m-8+1);
    if(a%2==1&&b%2==1){
      if(c==1){
	cout<<(a*b)/2+1<<endl;
      }
      else{
	cout<<(a*b)/2<<endl;
      }
    }
    else{
      cout<<(a*b)/2<<endl;
    }
  }
  return 0;
}
