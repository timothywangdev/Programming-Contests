#include <iostream>
#include <string.h>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva278.in");
ofstream fout("uva278.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
int N,R,C,maximum,current;
char ch;
bool board[10][10];
int movek[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
bool inBoundary(int r,int c){
	return (0<=r&&r<R)&&(0<=c&&c<C);
}
bool checkk(int r,int c){
	int a,b;
	for(int i=0;i<8;i++){
		a=r+movek[i][0];
		b=c+movek[i][1];
		if(inBoundary(a,b))
			if(board[a][b])
				return false;
	}
	return true;
}
void searchk(int r,int c){
	if(r==R)
		return;
	if(checkk(r,c)){
		board[r][c]=true;
		current++;
		if(current>maximum)
			maximum=current;
		if(c+1<C)
			searchk(r,c+1);
		else
			searchk(r+1,0);
		board[r][c]=false;
		current--;
	}
	if(c+1<C)
		searchk(r,c+1);
	else
		searchk(r+1,0);
}
bool checkQ(int r,int c){
	for(int i=0;i<r;i++){
		if(board[i][c])
			return false;
		int offset=r-i;
		if(inBoundary(r-offset,c-offset)&&board[r-offset][c-offset])
			return false;
		if(inBoundary(r-offset,c+offset)&&board[r-offset][c+offset])
			return false;
	}
	return true;
}
void searchQ(int r){
	if(r==R)
		return;
	for(int i=0;i<C;i++){
		if(checkQ(r,i)){
			board[r][i]=true;
		    current++;
			if(current>maximum)
			  maximum=current;
			searchQ(r+1);
			board[r][i]=false;
		    current--;
		}
	}
}
int main(){
	redirect();
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>ch>>R>>C;
		memset(board,false,sizeof(board));
		maximum=current=0;
		if(ch=='r')
			cout<<min(R,C)<<endl;
		else{
			if(ch=='k'){
				int odd,even,oddL,evenL;
				if(C%2==0){
					odd=even=C/2;
				}
				else{
					even=(C+1)/2;
					odd=even-1;
				}
				if(R%2==1){
					oddL=(R+1)/2;
					evenL=oddL-1;
				}
				else{
					oddL=evenL=R/2;
				}
				maximum=max(odd*oddL+even*evenL,even*oddL+odd*evenL);
			}			
			else if(ch=='Q'){
				maximum=min(R,C);
			}
			else if(ch=='K'){
				int m=(R%2==0)?R/2:(R+1)/2;
				int n=(C%2==0)?C/2:(C+1)/2;
				maximum=m*n;
			}
			cout<<maximum<<endl;
		}
	}

	return 0;
}