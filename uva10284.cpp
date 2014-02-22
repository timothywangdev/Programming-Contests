#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva10284.in");
ofstream fout("uva10284.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
struct P{
	char r;
	char c;
};
char opposite[8]={2,3,0,1,6,7,4,5};
char board[8][8];
char queenMove[8][2]={{-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};
int knightMove[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
bool searched[8][8][8];
bool pawnSide[32];
bool attacked[8][8];
P v[32];
int vSize,cr,cc,r,c,counter;
string s;
bool number(char ch){
	return ('0'<=ch&&ch<='9');
}
bool upper(char ch){
	return ('A'<=ch&&ch<='Z');
}
int main(){
	redirect();
	while(getline(cin,s)){
		memset(board,0,sizeof(board));
		memset(searched,false,sizeof(searched));
		memset(attacked,false,sizeof(attacked));
		memset(pawnSide,false,sizeof(pawnSide));
		cr=cc=0;
		vSize=0;
		counter=32;
		for(int i=0;i<s.length();i++){
			if(s[i]=='/'){
				continue;
			}
			if(!number(s[i])){
				board[cr][cc]=tolower(s[i]);
				v[vSize].r=cr;
				v[vSize].c=cc;
				if(upper(s[i]))
					pawnSide[vSize]=true;
				vSize++;
				cc++;
			}
			else{
				cc+=(int)(s[i]-'0');
			}
			if(cc==8){
				cr++;
				cc=0;
			}
		}
		for(int i=0;i<vSize;i++){
			if(board[v[i].r][v[i].c]=='r'){
				for(int j=0;j<4;j++){
					if(!searched[v[i].r][v[i].c][j]){
						r=v[i].r;
						c=v[i].c;
						while((0<=r&&r<8)&&(0<=c&&c<8)){
							r+=queenMove[j][0];
							c+=queenMove[j][1];
							if(!((0<=r&&r<8)&&(0<=c&&c<8)))
								break;
							if(board[r][c]==0&&!attacked[r][c]){
								attacked[r][c]=true;
								counter--;
							}
							else if(board[r][c]!=0){
								searched[r][c][opposite[j]]=false;
								break;
							}
						}
					}
				}
			}
			else if(board[v[i].r][v[i].c]=='q'){
				for(int j=0;j<8;j++){
					if(!searched[v[i].r][v[i].c][j]){
						r=v[i].r;
						c=v[i].c;
						while((0<=r&&r<8)&&(0<=c&&c<8)){
							r+=queenMove[j][0];
							c+=queenMove[j][1];
							if(!((0<=r&&r<8)&&(0<=c&&c<8)))
								break;
							if(board[r][c]==0&&!attacked[r][c]){
								attacked[r][c]=true;
								counter--;
							}
							else if(board[r][c]!=0){
								searched[r][c][opposite[j]]=false;
								break;
							}
						}
					}
				}
			}
			else if(board[v[i].r][v[i].c]=='k'){
				for(int j=0;j<8;j++){
					if(!searched[v[i].r][v[i].c][j]){
						r=v[i].r;
						c=v[i].c;
						r+=queenMove[j][0];
						c+=queenMove[j][1];
						if(!((0<=r&&r<8)&&(0<=c&&c<8)))
								continue;
						if(board[r][c]==0&&!attacked[r][c]){
							attacked[r][c]=true;
							counter--;
						}
						else if(board[r][c]!=0){
							searched[r][c][opposite[j]]=false;
						}
					}
				}
			}
			else if(board[v[i].r][v[i].c]=='n'){
				for(int j=0;j<8;j++){
					if(!searched[v[i].r][v[i].c][j]){
						r=v[i].r;
						c=v[i].c;
						r+=knightMove[j][0];
						c+=knightMove[j][1];
						if(!((0<=r&&r<8)&&(0<=c&&c<8)))
								continue;
						if(board[r][c]==0&&!attacked[r][c]){
							attacked[r][c]=true;
							counter--;
						}
					}
				}
			}
			else if(board[v[i].r][v[i].c]=='b'){
				for(int j=4;j<8;j++){
					if(!searched[v[i].r][v[i].c][j]){
						r=v[i].r;
						c=v[i].c;
						while((0<=r&&r<8)&&(0<=c&&c<8)){
							r+=queenMove[j][0];
							c+=queenMove[j][1];
							if(!((0<=r&&r<8)&&(0<=c&&c<8)))
								break;
							if(board[r][c]==0&&!attacked[r][c]){
								attacked[r][c]=true;
								counter--;
							}
							else if(board[r][c]!=0){
								searched[r][c][opposite[j]]=false;
								break;
							}
						}
					}
				}
			}
			else if(board[v[i].r][v[i].c]=='p'){
				if(!pawnSide[i]){
					for(int j=5;j<=6;j++){
						if(!searched[v[i].r][v[i].c][j]){
							r=v[i].r;
							c=v[i].c;
							r+=queenMove[j][0];
							c+=queenMove[j][1];
							if(!((0<=r&&r<8)&&(0<=c&&c<8)))
								continue;
							if(board[r][c]==0&&!attacked[r][c]){
								attacked[r][c]=true;
								counter--;
							}
						}
					}
				}
				else{
					for(int j=4;j<=7;j=j+3){
						if(!searched[v[i].r][v[i].c][j]){
							r=v[i].r;
							c=v[i].c;
							r+=queenMove[j][0];
							c+=queenMove[j][1];
							if(!((0<=r&&r<8)&&(0<=c&&c<8)))
								continue;
							if(board[r][c]==0&&!attacked[r][c]){
								attacked[r][c]=true;
								counter--;
							}
						}
					}
				}
			}

		}
		counter=0;
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				if(!attacked[i][j]&&board[i][j]==0)
					counter++;
        cout<<counter<<endl;
	}
	return 0;
}