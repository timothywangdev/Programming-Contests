#include <bits/stdc++.h>

using namespace std;
#define MT make_tuple
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(b);i>=(a);i--)
#define F(i,n) for(int i=0;i<(n);i++)
#define FR(i,n) for(int i=(n)-1;i>=0;i--)
#define R(a,i,b) (a<=i&&i<=b)
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef long long LL;

char a[2000][2000];
int deg[2000][2000];
bool used[2000][2000];
int n,m;
int mo[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void draw(int i,int j,int ii,int jj){
  if(i==ii){
    if(j<jj){
      a[i][j]='<';
      a[ii][jj]='>';
    }
    else{
      a[i][j]='>';
      a[ii][jj]='<';
    }
  }
  else{
    if(i<ii){
      a[i][j]='^';
      a[ii][jj]='v';
    }
    else{
      a[i][j]='v';
      a[ii][jj]='^';
    }
  }
}
int main(){
  memset(deg,0,sizeof(deg));
  memset(used,false,sizeof(used));
scanf("%d%d",&n,&m);
char ch;
scanf("%c",&ch);
F(i,n)scanf("%s",&a[i]);
  F(i,n)F(j,m)F(k,4){
    if(a[i][j]=='.'){
      int ii=i+mo[k][0];
      int jj=j+mo[k][1];
      if(R(0,ii,n-1)&&R(0,jj,m-1)&&a[ii][jj]=='.'){
	deg[i][j]++;
      }
    }
    else{
      used[i][j]=true;
    }
  }
  queue<PII> q;
  F(i,n)F(j,m)if(deg[i][j]==1){
    q.push(MP(i,j));
  }
  while(!q.empty()){
    PII front=q.front();
    q.pop();
    int i=front.first,j=front.second;
    if(used[i][j])continue;
    deg[i][j]--;
    F(k,4){
      int ii=i+mo[k][0];
      int jj=j+mo[k][1];
      if(R(0,ii,n-1)&&R(0,jj,m-1)&&!used[ii][jj]){
	deg[ii][jj]=0;
        used[ii][jj]=true;
        used[i][j]=true;
	F(kk,4){
	  int iii=ii+mo[kk][0];
	  int jjj=jj+mo[kk][1];
	  if(R(0,iii,n-1)&&R(0,jjj,m-1)&&!used[iii][jjj]){
	    deg[iii][jjj]--;
	    if(deg[iii][jjj]==1)q.push(MP(iii,jjj));
	  }
	}
	draw(i,j,ii,jj);
	break;
      }
    }
  }

  F(i,n)F(j,m)if(!used[i][j]){
    printf("Not unique");
    return 0;
  }

  F(i,n){
   F(j,m)printf("%c",a[i][j]);
   printf("\n");
  }
  return 0;
}
