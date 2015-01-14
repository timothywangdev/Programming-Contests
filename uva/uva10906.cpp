#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Exp;
map<string,int> toid;
vector<Exp> exps;

class Exp{
public:
  string name;
  string op;
  int l;
  int r;
  string left;
  string right;
  int ref;
  Exp(string name,string left, string op, string right):name(name),left(left),right(right),op(op),ref(0){}
  void init(){
    if(toid.find(left)!=toid.end()){
      l=toid[left];
      exps[l].ref++;
    }
    else{
      l=-1;
    }
    if(toid.find(right)!=toid.end()){
      r=toid[right];
      exps[r].ref++;
    }
    else{
      r=-1;
    }
  }
};



int T,N;
string data[50][5];

string evaluate(int i){
  string rv;
  if(i==-1)return rv;
  string left=evaluate(exps[i].l);
  string right=evaluate(exps[i].r);
  if(left==""){
    left=exps[i].left;
  }
  if(right==""){
    right=exps[i].right;
  }
  if(exps[i].op=="+"){
    rv=rv+left;
    rv=rv+exps[i].op; 
    if(exps[i].r==-1||exps[exps[i].r].op=="*"){
      rv=rv+right;
    }
    else{
      rv=rv+"("+right+")";
    }
  }
  else{
    if(exps[i].l==-1||exps[exps[i].l].op=="*"){
      rv=rv+left;
    }
    else{
      rv=rv+"("+left+")";
    }
    rv=rv+exps[i].op;
    if(exps[i].r==-1){
      rv=rv+right;
    }
    else{
      rv=rv+"("+right+")";
    }
  }
  return rv;
}
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>N;
    toid.clear();
    exps.clear();
    for(int i=0;i<N;i++){
      for(int k=0;k<5;k++){
	cin>>data[i][k];
      }
      toid[data[i][0]]=exps.size();
      exps.push_back(Exp(data[i][0],data[i][2],data[i][3],data[i][4]));		 
    }
    for(int i=0;i<N;i++){
      exps[i].init();
    }
    int root=-1;
    for(int i=0;i<N;i++){
      if(exps[i].ref==0){
	root=i;
	break;
      }
    }
    cout<<"Expression #"<<t+1<<": "<<evaluate(root)<<endl;
  }
  return 0;
}
