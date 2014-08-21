#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

// High Dimensional Point
class P{
public:
  vector<LL> pos;
  LL dim;
  P(vector<LL> pos):pos(pos),dim(pos.size()){}
  P(){}
};

// High Dimensional Cube
class Cube{
public:
  P cor;
  vector<LL> len;
  LL dim;
  Cube(vector<LL> len, P cor):len(len),cor(cor),dim(len.size()){}
  Cube(){}
  LL volume(){
    LL rv=1;
    for(LL i=0;i<dim;i++){
      rv*=len[i];
    }
    return rv;
  }
  bool intersect_line(LL len_1,LL cor_1,LL len_2,LL cor_2,LL &len_intersect,LL &cor_intersect){
    if(cor_1>cor_2){
      swap(cor_1,cor_2);
      swap(len_1,len_2);
    }
    // Not intersected
    if(cor_1+len_1<=cor_2){
      len_intersect=cor_intersect=0;
      return false;
    }
    cor_intersect=cor_2;
    len_intersect=min(cor_1+len_1,cor_2+len_2)-cor_2;
    return true;
  }
  bool intersect(Cube &other, Cube &rv){
    rv.dim=dim;
    rv.len=len;
    rv.cor=cor;
    for(int i=0;i<dim;i++){
      if(!intersect_line(len[i],cor.pos[i],other.len[i],other.cor.pos[i],rv.len[i],rv.cor.pos[i])){
	return false;
      }
    }
    return true;
  }
};

LL N,l,x,y,z;
vector<LL> len;
P cor;
int main(){
  while(cin>>N){
    if(!N)break;
    len.clear();
    cor.pos.clear();
    cor.dim=3;
    cin>>x>>y>>z>>l;
    cor.pos.push_back(x);
    cor.pos.push_back(y);
    cor.pos.push_back(z);
    len.push_back(l);
    len.push_back(l);
    len.push_back(l);
    bool intersected=true;
    Cube intersection=Cube(len,cor);
    for(LL i=1;i<N;i++){
      len.clear();
      cor.pos.clear();
      cor.dim=3;
      cin>>x>>y>>z>>l;
      cor.pos.push_back(x);
      cor.pos.push_back(y);
      cor.pos.push_back(z);
      len.push_back(l);
      len.push_back(l);
      len.push_back(l);
      Cube current=Cube(len,cor);
      Cube next_intersection;
      if(intersected&&intersection.intersect(current,next_intersection)){
	intersection=next_intersection;
      }
      else{
	intersected=false;
      }
    }
    if(intersected){
      cout<<intersection.volume()<<endl;
    }
    else{
      cout<<"0"<<endl;
    }
  }
  return 0;
}
