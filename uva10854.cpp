#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
int T;
string s;
vector<string> v;
LL cal(LL start,LL end){
  if(start>end)return 1;
  int index=-1;
  int counter=0;
  int endindex=-1;
  for(LL i=start;i<=end;i++){
    if(v[i]=="IF"){
      counter+=2;
    }
    if(v[i]=="ELSE"){
      counter--;
    }
    if(v[i]=="END_IF"){
      counter--;
    }
    if(v[i]=="ELSE"&&counter==1){
      index=i;
    }
    if(v[i]=="END_IF"&&counter==0){
      endindex=i;
      break;
    }
  }
  if(end-endindex<3){
    return cal(start+1,index-1)+cal(index+1,endindex-1);
  }
  else{
    return (cal(start+1,index-1)+cal(index+1,endindex-1))*cal(endindex+1,end);
  }
}
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    v.clear();
    while(cin>>s){
      if(s=="ENDPROGRAM")break;
      if(s!="S"){
	v.push_back(s);
      }
    }
    cout<<cal(0,v.size()-1)<<endl;
  }
  return 0;
}
