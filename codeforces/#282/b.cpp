#include <iostream>
#include <cmath>
using namespace std;

int a,b;
int main(){
  cin>>a>>b;
  if(a<b){
    cout<<"0"<<endl;
  }
  else if(a==b){
    cout<<"infinity"<<endl;
  }
  else{
    int sum=0;
    int k=a-b;
    for(int i=1;i*i<=k;i++){
      if(k%i==0){
	if(i>b)sum++;
	int j=k/i;
	if(j!=i&&j>b)sum++;
      }
    }
    cout<<sum<<endl;
  }
  return 0;
}
