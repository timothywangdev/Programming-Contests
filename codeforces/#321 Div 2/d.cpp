#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(b);i>=(a);i--)
#define F(i,n) for(int i=0;i<(n);i++)
#define FR(i,n) for(int i=(n)-1;i>=0;i--)
#define R(a,i,b) (a<=i&&i<=b)
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef unsigned long long LL;

const uint64_t m1  = 0x5555555555555555; //binary: 0101...
const uint64_t m2  = 0x3333333333333333; //binary: 00110011..
const uint64_t m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
const uint64_t m8  = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
const uint64_t m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
const uint64_t m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones
const uint64_t hff = 0xffffffffffffffff; //binary: all ones
const uint64_t h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...

LL f[18][1<<18];
LL rule[18][18];
LL sat[18];
LL n,m,k,x,y,c,idx;
vector<LL> _m[18];
int popcount(uint64_t x) {
    x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
    x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
    x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits 
    return (x * h01)>>56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ... 
}

void g(int pos,LL mask,LL rem){
   if(pos>17&&rem==0){
      _m[idx].pb(mask);
      return;
   }
   if(rem>0){
     g(pos+1,mask|(1<<pos),rem-1);
   }
   if(rem<=17-pos)
      g(pos+1,mask,rem);
}
int main(){
   
   F(i,18){
      idx=i;
      g(0,0,i+1);
   }
   memset(f,0,sizeof(f));
   memset(rule,0,sizeof(rule));
   cin>>n>>m>>k;
   F(i,n){
      cin>>sat[i];
   }
   F(i,k){
      cin>>x>>y>>c;
      rule[x-1][y-1]=c;
   }
   LL rv=0;
   for(int step=0;step<m;step++){
      for(int u=0;u<n;u++){
	 if(step==0){
	    f[u][1<<u]=sat[u];
	    if(step==m-1){
	       rv=max(rv,f[u][1<<u]);
	    }
	    continue;
	 }
	 for(int v=0;v<n;v++){
	    if(u!=v){
	       for(int j=0;j<_m[step-1].size();j++){
		  LL mask=_m[step-1][j];
		  if((popcount(mask)==step)&&(((1<<v)&mask)>0)&&
		     (((1<<u)&mask)==0)){
		     f[u][mask|(1<<u)]=max(f[u][mask|(1<<u)],sat[u]+rule[u][v]+f[v][mask]);
		     if(step==m-1){
			rv=max(rv,f[u][mask|(1<<u)]);
		     }
		  }
	       }
	    }
	 }
      }
   }
   cout<<rv<<endl;
   return 0;
}
