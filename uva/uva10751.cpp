#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>
using namespace std;
typedef pair<int,int> ii;
int mo[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
double maximum;
int dd1,dd2,N;
bool used[100][100];
vector<ii> rv,curr;
bool inRange(int i,int j){
  return 0<=i&&i<N&&0<=j&&j<N;
}
double getD(int d1,int d2){
  return d1+d2*sqrt(0.5)*2;
}
void search(int r,int c,int d1,int d2,int n){
  if(r==0&&c==0&&n==N*N+1){
    double D=getD(d1,d2);
    if(D>maximum){
      maximum=D;
      dd1=d1;
      dd2=d2;
      rv=curr;
    }
  }
  if(r==0&&c==0&&n!=1)return;
  // if(getD(d1,d2)<=maximum)return;
  used[r][c]=true;
  curr.push_back(make_pair(r,c));
  for(int i=0;i<8;i++){
    int rr=r+mo[i][0];
    int cc=c+mo[i][1];
    if(inRange(rr,cc)&&(!used[rr][cc]||(used[rr][cc]&&rr==0&&cc==0&&n==N*N))){
      if(i<4){
	search(rr,cc,d1+1,d2,n+1);
      }
      else{
	int r1=r+mo[i][0];
	int c1=c;
	int r2=r;
	int c2=c+mo[i][1];
	if(!(used[r1][c1]&&used[r2][c2])){
	  search(rr,cc,d1,d2+1,n+1);
	}
      }
    }
  }
  curr.pop_back();
  used[r][c]=false;
}

void cal(int n){
  memset(used,false,sizeof(used));
  N=n;
  maximum=0;
  search(0,0,0,0,1);
  cout<<n<<"X"<<n<<" "<<maximum<<" 1: "<<dd1<<" 1.414: "<<dd2<<endl;
  /*
  cout<<"Path :"<<endl;
  for(int i=0;i<rv.size();i++){
    cout<<rv[i].first<<" "<<rv[i].second<<endl;
  }
  */
}
int T;
int main(){
  /*
  for(int i=1;i<=10;i++){
    cal(i);
  }
  */
  cin>>T;
  for(int t=0;t<T;t++){
    if(t>0)cout<<endl;
    cin>>N;
    int d1=4*N-4;
    int d2=N*N-d1;
    if(N==1)d2=0;
    cout<<fixed<<setprecision(3)<<getD(d1,d2)<<endl;
  }
  return 0;
}
