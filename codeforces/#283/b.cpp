#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int n;
//string s;
char s[1000];
char s1[1000];
char minimum[1000];

void getMaximum(){
  for(int i=0;i<n;i++){
    minimum[i]='9';
  }
}
void shift(int k){
  for(int i=0;i<n;i++){
    if(s1[(i+k)%n]<minimum[i]){
      for(int j=0;j<n;j++){
	minimum[j]=s1[(j+k)%n];
      }
      return;
    }
    else if(s1[(i+k)%n]>minimum[i]){
      return;
    }
  }
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  getMaximum();
  for(int i=0;i<=9;i++){
    for(int j=0;j<n;j++){
      int k=(int)(s[j]-'0');
      k=(k+i)%10;
      s1[j]=(char)('0'+k);
    }
    for(int j=0;j<n;j++){
      shift(j);
    }
  }
  for(int i=0;i<n;i++){
    cout<<minimum[i];
  }
  cout<<endl;
  return 0;
}
