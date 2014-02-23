#include <iostream>

using namespace std;

char ch;
char board[100][100],ne[100][100];
int N,R,C,D;
int mo[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void copyOldToNew(){
	for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				ne[i][j]=board[i][j];
}
void copyNewToOld(){
	for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				board[i][j]=ne[i][j];
}
bool kill(char a,char b){
	return (a=='R'&&b=='S')||
		   (a=='S'&&b=='P')||
		   (a=='P'&&b=='R');
}
bool inBoundary(int r,int c){
	return (0<=r&&r<R&&0<=c&&c<C);
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>R>>C>>D;
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				cin>>board[i][j];
		if(i>0)
			cout<<endl;
		for(int d=0;d<D;d++){
			copyOldToNew();
			for(int i=0;i<R;i++)
				for(int j=0;j<C;j++)
					for(int m=0;m<4;m++){
						int r=i+mo[m][0];
						int c=j+mo[m][1];
						if(inBoundary(r,c)&&kill(board[i][j],board[r][c])){
							ne[r][c]=board[i][j];
						}
					}
			copyNewToOld();
		}
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				cout<<board[i][j];
			cout<<endl;
		}
	}
	return 0;
}
