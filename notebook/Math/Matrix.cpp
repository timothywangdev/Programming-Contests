#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(b);i>=(a);i--)
#define F(i,n) for(int i=0;i<(n);i++)
#define FR(i,n) for(int i=(n)-1;i>=0;i--)
typedef long long LL;

template <class DataType>
class Matrix{
public:
  vector<vector<DataType> > matrix;
  int r,c;
  bool modulo_flag;
  LL mod;
  Matrix(int r,int c):r(r),c(c),modulo_flag(false){
    matrix=vector<vector<DataType> >(r,vector<DataType>(c,0));
  }
  void set_modulo(LL mod){
    modulo_flag=true;
    this->mod=mod;
  }
  void unset_modulo(){
    modulo_flag=false;
  }
  DataType &operator()(int r,int c){return matrix[r][c];} const
  Matrix operator=(Matrix other){
    matrix=other.matrix;
    return *this;
  }
  Matrix operator*(Matrix &other){
    assert(c==other.r);
    Matrix rv(r,other.c);
    F(i,r)F(j,other.c)F(k,c){
      if(modulo_flag){rv(i,j)=(rv(i,j)+(matrix[i][k]*other(k,j))%mod)%mod;}
      else{rv(i,j)+=matrix[i][k]*other(k,j);}
    }
    return rv;
  }
  Matrix operator^(LL p){
    assert(r==c);
    Matrix rv(r,c),base(r,c);
    base=(*this);
    F(i,r)rv(i,i)=1;
    while(p){
      if(p&1)rv=rv*base;
      base=base*base;
      p>>=1;
    }
    return rv;
  }
  template <class T>
  friend ostream &operator<<(ostream &os,Matrix<T> &m);
};

template <class DataType>
ostream &operator<<(ostream &os,Matrix<DataType> &m){
  F(i,m.r){F(j,m.c){cout<<m(i,j)<<" ";}cout<<endl;}
  return os;
}


int main(){
  Matrix<int> m(2,2);
  m(0,0)=1;
  m(0,1)=2;
  m(1,0)=3;
  m(1,1)=4;
  cout<<m<<endl;
  m=m^10;
  cout<<m;
  return 0;
}
