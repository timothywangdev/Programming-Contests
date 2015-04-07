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

int n,m;
char a[2000][2000];
bool vis[2000][2000];
int mo[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
int re[4][3][2]={{{0,-1},{-1,-1},{-1,0}},{{-1,0},{-1,1},{0,1}},{{0,-1},{1,-1},{1,0}},{{1,0},{1,1},{0,1}}};
bool check(int r,int c){
   if(R(0,r,n-1)&&R(0,c,m-1)){
      if(a[r][c]!='*')return false;
      F(k,4){
	 bool ok=true;
	 F(j,3){
	    int rr=r+re[k][j][0];
	    int cc=c+re[k][j][1];
	    if(!(R(0,rr,n-1)&&R(0,cc,m-1)&&a[rr][cc]=='.')){
	       ok=false;
	       break;
	    }
	 }
	 if(ok){
	    return true;
	 }
      }
   }
   return false;
}
queue<PII> q;
int main(){
   memset(vis,false,sizeof(vis));
   scanf("%d%d",&n,&m);
   char ch;
   scanf("%c",&ch);
   F(i,n){
      F(j,m){
	 scanf("%c",&a[i][j]);
      }
      scanf("%c",&ch);
   }
   F(i,n){
      F(j,m){
	 if(check(i,j)){
	    q.push(mp(i,j));
	    vis[i][j]=true;
	 }
      }
   }
   int sum=q.size();
   while(q.size()){
      PII front=q.front();q.pop();
      a[front.first][front.second]='.';
      F(k,8){
	 int ii=front.first+mo[k][0];
	 int jj=front.second+mo[k][1];
	 if(check(ii,jj)&&!vis[ii][jj]){
	    vis[ii][jj]=true;
	    q.push(mp(ii,jj));
	    sum++;
	 }
      }
   }
   //if(sum>n*m){
   // printf("%d\n",sum);
   // }
   F(i,n){
      F(j,m){
	 printf("%c",a[i][j]);
      }
      printf("\n");
   }
   return 0;
}
