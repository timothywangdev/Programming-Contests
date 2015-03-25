#include <bits/stdc++.h>
using namespace std;

string a[1000][2];
int q;
int counter=0;
string s1,s2;
map<string,int> mm;
int main(){
  cin>>q;
  for(int i=0;i<q;i++){
    cin>>s1>>s2;
    map<string,int>::iterator it_2=mm.find(s1);
    if(it_2==mm.end()){
      a[counter][0]=s1;
      a[counter][1]=s2;
      mm[s2]=counter;
      counter++;
    }
    else{
      int idx=it_2->second;
      a[idx][1]=s2;
      mm.erase(it_2);
      mm[s2]=idx;
    }
  }
  cout<<counter<<endl;
  for(int i=0;i<counter;i++){
    cout<<a[i][0]<<" "<<a[i][1]<<endl;
  }
  return 0;
}
