#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

bool m[50][50];
bool used[50][50][4];
int mo[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int entity[4][2]={{0,0},{-1,0},{0,-1},{-1,-1}};
int N,M,sr,sc,dr,dc,dir;
string s;
struct Cor{
	int r;
	int c;
	int dir;
	int time;
	Cor(){}
	Cor(int r,int c,int dir,int time):r(r),c(c),dir(dir),time(time){}
};

bool inRange(int r,int c){
	return 0<=r&&r<N&&0<=c&&c<M;
}
bool possible(Cor &u){
	for(int i=0;i<4;i++){
		int r=u.r+entity[i][0];
		int c=u.c+entity[i][1];
		if(!inRange(r,c)||m[r][c]){
		  return false;
		}
	}
	return true;
}
void moveRobot(Cor &u,int distance){
	for(int i=0;i<distance;i++){
		u.r=u.r+mo[u.dir][0];
		u.c=u.c+mo[u.dir][1];
		if(!possible(u)){
			u.r=-1;
			u.c=-1;
			return;
		}
	}
}
int bfs(){
	memset(used,false,sizeof(used));
	queue<Cor> q;
	q.push(Cor(sr,sc,dir,0));
	used[sr][sc][dir]=true;
	while(q.size()){
		Cor u=q.front();
		q.pop();
		if(u.r==dr&&u.c==dc){
			return u.time;
		}
		Cor next=u;
		next.time++;
		next.dir=(u.dir+1)%4;
		if(!used[next.r][next.c][next.dir]){
			q.push(next);
			used[next.r][next.c][next.dir]=true;
			//cout<<"from: "<<u.r<<" "<<u.c<<"  to  "<<next.r<<" "<<next.c<<endl;
		}
		next.dir=u.dir-1;
		if(next.dir==-1){
			next.dir=3;
		}
		if(!used[next.r][next.c][next.dir]){
			q.push(next);
			used[next.r][next.c][next.dir]=true;
			//cout<<"from: "<<u.r<<" "<<u.c<<"  to  "<<next.r<<" "<<next.c<<endl;
		}
		for(int i=1;i<=3;i++){
			next=u;
			next.time++;
			moveRobot(next,i);
			if(possible(next)&&!used[next.r][next.c][next.dir]){
				q.push(next);
				used[next.r][next.c][next.dir]=true;
				//cout<<"from: "<<u.r<<" "<<u.c<<"  to  "<<next.r<<" "<<next.c<<endl;
			}
		}
	}
	return -1;
}
int main(){
	while(cin>>N>>M){
		if(!N&&!M){
			break;
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin>>m[i][j];
			}
		}
		cin>>sr>>sc>>dr>>dc>>s;
		if(s=="north"){
			dir=0;
		}
		else if(s=="east"){
			dir=1;
		}
		else if(s=="south"){
			dir=2;
		}
		else if(s=="west"){
			dir=3;
		}
		cout<<bfs()<<endl;
	}
	return 0;
}
