#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
using namespace std;
int N;
int sig[31];
int num[31];
bool visited[31][31][6001];
int used[6001];
void f(int pos,int open,int val){

  if(visited[pos][open][val+3000])return;
  visited[pos][open][val+3000]=true;
  if(pos==N){
    used[val+3000]=true;
    return;
  }
  int nval=val+sig[pos]*num[pos]*((open%2==0)?1:-1);
  if(sig[pos]==-1){
    f(pos+1,open+1,nval);
  }
  if(open>0){
    f(pos+1,open-1,nval);
  }
  f(pos+1,open,nval);
}

string s;

void process(){
  istringstream iss(s);
  sig[0]=1;
  iss>>num[0];
  N=1;
  string str;
  while(iss>>str>>num[N]){
    if(str=="-"){
      sig[N]=-1;
    }
    else{
      sig[N]=1;
    }
    N++;
  }
}
int main(){
  while(getline(cin,s)){
    memset(visited,false,sizeof(visited));
    memset(used,false,sizeof(used));
    process();
    f(0,0,0);
    int counter=0;
    for(int i=0;i<=6000;i++){
      counter+=used[i];
    }
    cout<<counter<<endl;
  }
  return 0;
}
