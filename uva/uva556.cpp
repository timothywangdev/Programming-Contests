#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

int R,C;
int counter[100][100];
int move[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
int ri[4]={3,0,1,2};
int c[5];
vector<string> maze;
void mo(int &x,int &y,int dir){
	x+=move[dir][0];
	y+=move[dir][1];
}
bool inBoundary(int x,int y){
	return (0<=x&&x<R&&0<=y&&y<C);
}
class wall{
public:
	bool exist[4];
	bool used[4];
	void set(int x,int y){
		memset(exist,false,sizeof(exist));
		memset(used,false,sizeof(used));
		for(int i=0;i<4;i++){
			int tx=x,ty=y;
			mo(tx,ty,i);
			if(!inBoundary(tx,ty)||maze[tx][ty]=='1'){
				exist[i]=true;
			}
		}
	}
};
wall walls[100][100];
bool viable(int x,int y,int dir){
	mo(x,y,dir);
	if(0<=x&&x<R&&0<=y&&y<C&&maze[x][y]=='0')
		return true;
	return false;
}
string s;

int main(){
	while(cin>>R>>C){
		if(R==0&&C==0)
			break;

		maze.clear();
		for(int i=0;i<R;i++){
			cin>>s;
			maze.push_back(s);
		}
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				walls[i][j].set(i,j);
		memset(counter,0,sizeof(counter));
		int x=R-1,y=0,dir=0;
		bool first=true;
		while(true){

			if(!first&&x==R-1&&y==0)
				break;
			counter[x][y]++;
			if(first)
				first=false;
			if(!walls[x][y].exist[ri[dir]]){
				dir=ri[dir];
				mo(x,y,dir);
				walls[x][y].used[ri[dir]]=true;
				continue;
			}
			if(viable(x,y,dir)){
				mo(x,y,dir);
				continue;
			}

			for(int i=dir+1;i<=dir+3;i++){
				int rdir=i%4;
				if(viable(x,y,rdir)){
					int tx=x,ty=y;
					mo(tx,ty,rdir);
					if(walls[tx][ty].used[ri[rdir]])
						continue;
					walls[tx][ty].used[ri[rdir]]=true;
					x=tx;
					y=ty;
					dir=rdir;
					break;
				}
			}

		}
		memset(c,0,sizeof(c));
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				if(maze[i][j]!='1'&&counter[i][j]<=4)
					c[counter[i][j]]++;
		for(int i=0;i<5;i++)
			cout<<setw(3)<<c[i];
		cout<<endl;
	}

	return 0;
}
