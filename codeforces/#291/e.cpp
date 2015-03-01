#include <bits/stdc++.h>
#define MAXN 101
using namespace std;
typedef long long LL;
#define MOD 1000000007

template <class DataType>
class Matrix{
public:
  DataType matrix[MAXN][MAXN];
  int r,c;
  Matrix(int r,int c):r(r),c(c){memset(matrix,0,sizeof(matrix));}
  Matrix operator=(Matrix other){
    r=other.r;c=other.c;
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
	matrix[i][j]=other.matrix[i][j];
      }
    }
    return *this;
  }
  Matrix operator*(Matrix other){
    assert(c==other.r);
    Matrix rv(r,other.c);
    for(int i=0;i<r;i++){
      for(int j=0;j<other.c;j++){
	for(int k=0;k<c;k++){
	  rv.matrix[i][j]+=matrix[i][k]*other.matrix[k][j];
	}
      }
    }
    return rv;
  }
  Matrix operator^(LL p){
    assert(r==c);
    Matrix rv(r,c),base(r,c);
    base=(*this);
    for(int i=0;i<r;i++){
      rv.matrix[i][i]=1;
    }
    while(p){
      if(p&1)rv=rv*base;
      base=base*base;
      p>>=1;
    }
    return rv;
  }
  Matrix modulo_multi(Matrix other,LL mod){
    assert(c==other.r);
    Matrix rv(r,other.c);
    for(int i=0;i<r;i++){
      for(int j=0;j<other.c;j++){
	for(int k=0;k<c;k++){
	  rv.matrix[i][j]+=(matrix[i][k]*other.matrix[k][j])%mod;
	  rv.matrix[i][j]%=mod;
	}
      }
    }
    return rv;
  }
  Matrix modulo_pow(LL p,LL mod){
    assert(r==c);
    Matrix rv(r,c),base(r,c);
    base=(*this);
    for(int i=0;i<r;i++){
      rv.matrix[i][i]=1;
    }
    while(p){
      if(p&1)rv=rv.modulo_multi(base,mod);
      base=base.modulo_multi(base,mod);
      p>>=1;
    }
    return rv;
  }
};

int n;
LL x,t;
LL child[101];
LL f[100];
int main(){
  memset(child,0,sizeof(child));
  memset(f,0,sizeof(f));
  cin>>n>>x;
  for(int i=0;i<n;i++){
    cin>>t;
    child[t]++;
  }
  f[0]=1;
  for(LL i=1;i<=min(x,(LL)100);i++){
    for(int j=1;j<=100;j++){
      if(i-j>=0){
	f[i]=(f[i]+(child[j]*f[i-j])%MOD)%MOD;
      }
    }
  }
  LL sum=0;
  for(LL i=0;i<=min(x-1,(LL)99);i++){
    sum=(sum+f[i])%MOD;
  }
  if(x<=100){
    cout<<(sum+f[x])%MOD<<endl;
    return 0;
  }
  Matrix<LL> m(101,101);
  for(int i=1;i<=100;i++){
    m.matrix[0][i-1]=child[i];
  }
  for(int i=1;i<=99;i++){
    m.matrix[i][i-1]=1;
  }
  Matrix<LL> init_vector(101,1);
  for(int i=0;i<100;i++){
    init_vector.matrix[i][0]=f[100-i];
  }
  init_vector.matrix[100][0]=sum;
  m.matrix[100][0]=m.matrix[100][100]=1;
  m=m.modulo_pow(x-100,MOD);
  m=m.modulo_multi(init_vector,MOD);
  cout<<(m.matrix[100][0]+m.matrix[0][0])%MOD<<endl;
  /* Test
  Matrix<LL> test(2,2);
  test.matrix[0][0]=1;
  test.matrix[0][1]=2;
  test.matrix[1][0]=3;
  test.matrix[1][1]=4;
  test=test^1;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      cout<<test.matrix[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  return 0;
}
