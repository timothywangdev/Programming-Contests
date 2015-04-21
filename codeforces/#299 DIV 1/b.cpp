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
typedef long long LL;
#define MAXN 1000001
char P[MAXN+1],T[MAXN+1];
int ne[MAXN+1],Z[MAXN],Z2[MAXN];
LL MOD=(LL)(1e9+7);

void Z_alg(char P[],int m,int Z[]){
   int L = 0, R = 0;
   for (int i = 1; i < m; i++) {
      if (i > R) {
	 L = R = i;
	 while (R <m && P[R-L] == P[R]) R++;
	 Z[i] = R-L; R--;
      } else {
	 int k = i-L;
	 if (Z[k] < R-i+1) Z[i] = Z[k];
	 else {
	    L = i;
	    while (R < m && P[R-L] == P[R]) R++;
	    Z[i] = R-L; R--;
	 }
      }
   }
}

void KMP_preprocess(char P[],int m,int ne[]){
   int i=0,j=-1;
   ne[0]=-1;
   while(i<m){
      while(j>=0&&P[i]!=P[j])j=ne[j];
      i++;j++;
      ne[i]=j;
   }
}

/*
  Transforms ne[i] to be the length of longest proper prefix of P[0..i] which is also a suffix of P[0..i]
*/
void KMP_transform_to_length(char P[],int m,int ne[]){
   F(i,m){
      ne[i]=ne[i+1];
   }
}

/*
  Warning: Need to call KMP_transform_to_length() first !!!

  Transforms KMP prefix array to Z-algorithm array
  ne[i]: length of longest proper prefix of P[0..i] which is also a suffix of P[0..i]
  Z[i]:    length of longest substring starting from P[i] which is also a prefix of P
*/
void prefix_to_Z(int m,int ne[],int Z[]){
   Z[0]=m;
   for(int i=1;i<=m;i++){
      Z[i-ne[i]+1]=ne[i];
   }
}

int N,M,m,a[1000000],b[1000000];
int main(){
   scanf("%d%d",&N,&M);
   scanf("%s",&P[0]);
   F(i,M){
      scanf("%d",&a[i]);
      a[i]--;
   }
   m=strlen(P);
   Z_alg(P,m,Z);
   F(i,M){
      if(i+1<M){
	 if(a[i]+m-1>=a[i+1]){
	    if(Z[a[i+1]-a[i]]!=m-(a[i+1]-a[i])){
	       printf("0\n");
	       return 0;
	    }
	 }
      }
   }
   memset(b,0,sizeof(b));
   F(i,M){
      if(i+1<M){
	 if(a[i]+m-1<a[i+1]){
	    for(int j=a[i];j<=a[i]+m-1;j++){
	       b[j]=1;
	    }
	 }
	 else{
	    for(int j=a[i];j<a[i+1];j++){
	       b[j]=1;
	    }
	 }
      }
      else{
	 for(int j=a[i];j<=min(a[i]+m-1,N-1);j++){
	    b[j]=1;
	 }
      }
   }
   LL rv=1;
   F(i,N){
      if(!b[i]){
	 rv=(rv*26)%MOD;
      }
   }
   cout<<rv<<endl;
   return 0;
}
