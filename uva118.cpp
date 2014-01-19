#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "string.h"
using namespace std;
#ifdef DEBUG
ifstream fin("uva118.in");
ofstream fout("uva118.out");
#endif
// 0: N 1: E 2: S 3: W
int movement[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
map<char,int> toMove;
map<int,char> toDir;
bool g[52][52];
int rx,ry,X,Y;
char rd;
string inst;
void process(int x,int y,int d,int pos){
	if(pos==inst.length()){
		cout<<x<<" "<<y<<" "<<toDir[d]<<endl;
		return;
	}
	int newx=x,newy=y;
	if(inst[pos]=='F'){
		newx+=movement[d][0];
		newy+=movement[d][1];
		if(newx>X||newx<0||newy>Y||newy<0){
			if(g[x][y]){
			  process(x,y,d,pos+1);
			}
			else{
			  g[x][y]=true;
			  cout<<x<<" "<<y<<" "<<toDir[d]<<" LOST"<<endl;
			}
		}
		else{
			process(newx,newy,d,pos+1);
		}
	}
	else{
		if(inst[pos]=='R')
			d=(d+1)%4;
		else
			d=(d+3)%4;
	    process(x,y,d,pos+1);
	}
}
int main(){
	memset(g,false,sizeof(g));
	toDir[0]='N';
	toDir[1]='E';
	toDir[2]='S';
	toDir[3]='W';

	toMove['N']=0;
	toMove['E']=1;
	toMove['S']=2;
	toMove['W']=3;
	cin>>X>>Y;
	while(cin>>rx>>ry>>rd){
		cin>>inst;
		process(rx,ry,toMove[rd],0);
	}
	return 0;
}