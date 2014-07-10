#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int T;
string table[6];

char addDigit(char &rv,char &a,char &b){
  if(a>b)swap(a,b);
  if(a=='*'){
    rv=b;
    return '*';
  }
  if(b=='*'){
    rv=a;
    return '*';
  }
  if(a=='C'){
    if(b=='C'){
      rv='V';
      return 'U';
    }
    if(b=='D'){
      rv='U';
      return 'U';
    }
    if(b=='U'){
      rv='D';
      return '*';
    }
    if(b=='V'){
      rv='C';
      return '*';
    }
  }
   if(a=='D'){
    if(b=='D'){
      rv='C';
      return 'U';
    }
    if(b=='U'){
      rv='V';
      return 'U';
    }
    if(b=='V'){
      rv='D';
      return '*';
    }
  }
   if(a=='U'){
    if(b=='U'){
      rv='C';
      return '*';
    }
    if(b=='V'){
      rv='U';
      return '*';
    }
  }
   if(a=='V'){
     if(b=='V'){
       rv='V';
       return '*';
     }
   }
}
void toArray(string &s,char dest[]){
  int counter=7;
  for(int i=0;i<8;i++){
    dest[i]='*';
  }
  for(int i=s.length()-1;i>=0;i--){
    dest[counter]=s[i];
    counter--;
  }
}
string add(string s1,string s2){
  char rr[8],r1[8],r2[8];
  toArray(s1,r1);
  toArray(s2,r2);
  char tmp;
  char carry='V',carry1,carry2;
  for(int i=7;i>=0;i--){
    rr[i]=carry;
    carry1=addDigit(tmp,r1[i],r2[i]);
    carry2=addDigit(rr[i],tmp,rr[i]);
    tmp=addDigit(carry,carry1,carry2);
  }
  for(int i=0;i<8;i++){
    if(rr[i]!='*'){
      string r="";
      for(int j=i;j<8;j++){
	r=r+rr[j];
      }
      return r;
    }
  }
}
string s;
bool check(string s,string target){
  int counter=target.size()-1;
  for(int i=s.size()-1;i>=0;i--){
    if(s[i]!=target[counter])return false;
    counter--;
  }
  return true;			
}
int main(){
  cin>>T;
  getline(cin,s);
  cout<<"COWCULATIONS OUTPUT"<<endl;
  for(int t=0;t<T;t++){
    for(int i=0;i<6;i++){
      getline(cin,table[i]);
    }
    string curr=table[1];
    for(int i=2;i<=4;i++){
      if(table[i][0]=='A'){
	curr=add(table[0],curr);
      }
      else if(table[i][0]=='R'){
	curr='V'+curr.substr(0,curr.length()-1);
      }
      else if(table[i][0]=='L'){
	curr=curr+'V';
      }
    }
    if(check(curr,table[5])){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  cout<<"END OF OUTPUT"<<endl;
  return 0;
}
