#include <iostream>
#include <string.h>
#include <algorithm>
#include <utility>
#include <vector>
#define INF 2147483647
using namespace std;
typedef pair<int,int> ii;
vector<ii> food;
int N;
int counter=0;
char m[10][10];
int mm[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int dp[10][10][1000],cc[10][10][1000];
bool visited[10][10];
bool inRange(int i,int j){
  return 0<=i&&i<N&&0<=j&&j<N;
}
bool chara(char ch){
  return 'A'<=ch&&ch<='Z';
}

void findFood(char ch){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	if(m[i][j]==ch){
	  food.push_back(make_pair(i,j));
	  break;
	}
     }
   } 
}
ii search(ii current,ii dest,int mo,int alp){
  if(visited[current.first][current.second])
    return make_pair(INF,INF);
  visited[current.first][current.second]=true;
  if(current.first==dest.first&&current.second==dest.second){
    visited[current.first][current.second]=false;
    return make_pair(mo,1);
  }
  if(dp[current.first][current.second][mo]!=-1){
    visited[current.first][current.second]=false;
    return make_pair(dp[current.first][current.second][mo],cc[current.first][current.second][mo]);
  }
  int minimum=INF;
  int total=0;
  for(int k=0;k<4;k++){
    int r=current.first+mm[k][0];
    int c=current.second+mm[k][1];
    if(inRange(r,c)&&m[r][c]!='#'&&(!chara(m[r][c])||(chara(m[r][c])&&(int)(m[r][c]-'A')<=alp))){
       ii rv=search(make_pair(r,c),dest,mo+1,alp);
       if(rv.first<minimum){
	 minimum=rv.first;
	 total=rv.second;
       }
       else if(rv.first==minimum){
	 total=(total+rv.second)%20437;
       }
    }
  }
  cc[current.first][current.second][mo]=total;
  dp[current.first][current.second][mo]=minimum;
  visited[current.first][current.second]=false;
  return make_pair(dp[current.first][current.second][mo],cc[current.first][current.second][mo]);
}
  ii getShortest(ii from,ii to,int alp){
   memset(dp,-1,sizeof(dp));
   memset(cc,0,sizeof(cc));
   memset(visited,false,sizeof(visited));
   return search(from,to,0,alp);
}
char maxChara;
int main(){
  while(cin>>N){
    if(!N)break;
    food.clear();
    
    int distance=0;
    int total=1;
    maxChara=0;
    counter++;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	  cin>>m[i][j];
	  if(chara(m[i][j])){
	    maxChara=max(maxChara,m[i][j]);
	    //cout<<maxChara<<endl;
	  }
       }
     }	
    for(char i='A';i<=maxChara;i++){
      findFood(i);
    }
    for(int i=1;i<food.size();i++){
      ii rv=getShortest(food[i-1],food[i],i);
      if(rv.first==INF){
	distance=INF;
	break;
      }
      distance+=rv.first;
      total=(total*rv.second)%20437;
    }
    cout<<"Case "<<counter<<": ";
    if(distance==INF){	
      cout<<"Impossible"<<endl;
    }
    else{
      cout<<distance<<" "<<total<<endl;
    }
  }
  return 0;
}
