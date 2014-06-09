#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;

 int N,M;
 short x,y,maxX,minX,maxY,minY;
struct Cor{
	short x;
	short y;
	short dist;
	Cor(){}
	Cor(short x,short y,short dist):x(x),y(y),dist(dist){}
};
short mo[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
queue<Cor> q;
bool dest[2001][2001],visited[2001][2001];
bool inRange(short &x,short &y){
	return minX<=x&&x<=maxX&&minY<=y&&y<=maxY;
}
int bfs(){
	short xx,yy;
	Cor front;
	while(q.size()){
		front=q.front();
		q.pop();
		if(dest[front.x][front.y]){
			return front.dist;
		}
		for(short i=0;i<4;i++){
			xx=front.x+mo[i][0];
			yy=front.y+mo[i][1];
			if(inRange(xx,yy)){
				if(!visited[xx][yy]){
					visited[xx][yy]=true;
					q.push(Cor(xx,yy,front.dist+1));
				}
			}
		}
	}
}
int main(){
	while(scanf("%d",&N)){
		if(!N){
			break;
		}
		maxX=-32767;
		maxY=-32767;
		minX=32767;
		minY=32767;
		memset(visited,false,sizeof(visited));
		memset(dest,false,sizeof(visited));
		for(int i=0;i<N;i++){
			scanf("%hd %hd",&x,&y);
			maxX=max(maxX,x);
			minX=min(minX,x);
			maxY=max(maxY,y);
			minY=min(minY,y);
			q.push(Cor(x,y,0));
			visited[x][y]=true;
		}
		scanf("%d",&M);
		for(int i=0;i<M;i++){
			scanf("%hd %hd",&x,&y);
			maxX=max(maxX,x);
			minX=min(minX,x);
			maxY=max(maxY,y);
			minY=min(minY,y);
			dest[x][y]=true;
		}
		printf("%d\n",bfs());
		while(q.size()){
			q.pop();
		}
	}
	return 0;
}
