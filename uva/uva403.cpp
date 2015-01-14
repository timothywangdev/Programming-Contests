#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva403.in");
ofstream fout("uva403.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
bool chara[27][5][6]={
{{0,1,1,1,0,0},
{1,0,0,0,1,0},
{1,1,1,1,1,0},
{1,0,0,0,1,0},
{1,0,0,0,1,0}},
{{1,1,1,1,0,0},
{1,0,0,0,1,0},
{1,1,1,1,0,0},
{1,0,0,0,1,0},
{1,1,1,1,0,0}},
{{0,1,1,1,1,0},
{1,0,0,0,1,0},
{1,0,0,0,0,0},
{1,0,0,0,0,0},
{0,1,1,1,1,0}},
{{1,1,1,1,0,0},
{1,0,0,0,1,0},
{1,0,0,0,1,0},
{1,0,0,0,1,0},
{1,1,1,1,0,0}},
{{1,1,1,1,1,0},
{1,0,0,0,0,0},
{1,1,1,0,0,0},
{1,0,0,0,0,0},
{1,1,1,1,1,0}},
{{1,1,1,1,1,0},
{1,0,0,0,0,0},
{1,1,1,0,0,0},
{1,0,0,0,0,0},
{1,0,0,0,0,0}},
{{0,1,1,1,1,0},
{1,0,0,0,0,0},
{1,0,0,1,1,0},
{1,0,0,0,1,0},
{0,1,1,1,0,0}},
{{1,0,0,0,1,0},
{1,0,0,0,1,0},
{1,1,1,1,1,0},
{1,0,0,0,1,0},
{1,0,0,0,1,0}},
{{1,1,1,1,1,0},
{0,0,1,0,0,0},
{0,0,1,0,0,0},
{0,0,1,0,0,0},
{1,1,1,1,1,0}},
{{0,0,1,1,1,0},
{0,0,0,1,0,0},
{0,0,0,1,0,0},
{1,0,0,1,0,0},
{0,1,1,0,0,0}},
{{1,0,0,0,1,0},
{1,0,0,1,0,0},
{1,1,1,0,0,0},
{1,0,0,1,0,0},
{1,0,0,0,1,0}},
{{1,0,0,0,0,0},
{1,0,0,0,0,0},
{1,0,0,0,0,0},
{1,0,0,0,0,0},
{1,1,1,1,1,0}},
{{1,0,0,0,1,0},
{1,1,0,1,1,0},
{1,0,1,0,1,0},
{1,0,0,0,1,0},
{1,0,0,0,1,0}},
{{1,0,0,0,1,0},
{1,1,0,0,1,0},
{1,0,1,0,1,0},
{1,0,0,1,1,0},
{1,0,0,0,1,0}},
{{0,1,1,1,0,0},
{1,0,0,0,1,0},
{1,0,0,0,1,0},
{1,0,0,0,1,0},
{0,1,1,1,0,0}},
{{1,1,1,1,0,0},
{1,0,0,0,1,0},
{1,1,1,1,0,0},
{1,0,0,0,0,0},
{1,0,0,0,0,0}},
{{0,1,1,1,0,0},
{1,0,0,0,1,0},
{1,0,0,0,1,0},
{1,0,0,1,1,0},
{0,1,1,1,1,0}},
{{1,1,1,1,0,0},
{1,0,0,0,1,0},
{1,1,1,1,0,0},
{1,0,0,1,0,0},
{1,0,0,0,1,0}},
{{0,1,1,1,1,0},
{1,0,0,0,0,0},
{0,1,1,1,0,0},
{0,0,0,0,1,0},
{1,1,1,1,0,0}},
{{1,1,1,1,1,0},
{1,0,1,0,1,0},
{0,0,1,0,0,0},
{0,0,1,0,0,0},
{0,1,1,1,0,0}},
{{1,0,0,0,1,0},
{1,0,0,0,1,0},
{1,0,0,0,1,0},
{1,0,0,0,1,0},
{0,1,1,1,0,0}},
{{1,0,0,0,1,0},
{1,0,0,0,1,0},
{0,1,0,1,0,0},
{0,1,0,1,0,0},
{0,0,1,0,0,0}},
{{1,0,0,0,1,0},
{1,0,0,0,1,0},
{1,0,1,0,1,0},
{1,1,0,1,1,0},
{1,0,0,0,1,0}},
{{1,0,0,0,1,0},
{0,1,0,1,0,0},
{0,0,1,0,0,0},
{0,1,0,1,0,0},
{1,0,0,0,1,0}},
{{1,0,0,0,1,0},
{0,1,0,1,0,0},
{0,0,1,0,0,0},
{0,0,1,0,0,0},
{0,0,1,0,0,0}},
{{1,1,1,1,1,0},
{0,0,0,1,0,0},
{0,0,1,0,0,0},
{0,1,0,0,0,0},
{1,1,1,1,1,0}},
{{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0}}
};

void setChar(char ch,int index,int row,int col){
	if(ch=='.')
		chara[index][row][col]=false;
	else
		chara[index][row][col]=true;
}
void print(){
	for(int i=0;i<27;i++){
		cout<<"{";
		for(int j=0;j<5;j++){
			cout<<"{";
			for(int k=0;k<6;k++){
               cout<<chara[i][j][k];
			   if(k<5)
				   cout<<",";
			}
			cout<<"}";
		    if(j<4)
			  cout<<","<<endl;
		}
		cout<<"}";
		if(i<26)
			cout<<","<<endl;
	}
}
void printFormat(){
	string s;
	int start=0;
	for(int n=0;n<3;n++){
		for(int i=0;i<5;i++){
			getline(cin,s);
			for(int j=0;j<9;j++)
				for(int k=0;k<6;k++){
					setChar(s[6*j+k],start+j,i,k);
				}
		}
		start+=9;
	}
	print();
}

string s;
char grid[60][60];
void setGrid(int r,int c,char ch){
	if(0<=r&&r<60&&0<=c&&c<60){
	   if(ch!=' ')
	    grid[r][c]=ch;
	}
}
char getChara(bool b){
	return b?'*':'.';
}
void writeStr(int r,int c,string size,string s){
	if(size=="C1"){
		for(int i=0;i<s.length();i++)
			setGrid(r,c+i,s[i]);
	}
	else{
		for(int i=0;i<s.length();i++){
			int index;
			if(s[i]==' ')
				index=26;
			else
				index=(int)(s[i]-'A');
			for(int row=0;row<5;row++)
				for(int col=0;col<6;col++)
					setGrid(r+row,c+col+i*6,getChara(chara[index][row][col]));
		}
	}
}
string getSubStr(string s,int start,int end){
	string newStr;
	for(int i=start;i<=end;i++)
		newStr.push_back(s[i]);
	return newStr;
}
int getStartingCol(string command,string size,int strSize){
	if(size=="C1"){
		if(command==".L"){
			return 0;
		}
		else if(command==".R"){
			return 60-strSize;
		}
		else if(command==".C"){
			if(strSize%2==1){
				return 30-strSize/2;
			}
			else{
				return 29-strSize/2+1;
			}
		}
	}
	else{
		if(command==".L"){
			return 0;
		}
		else if(command==".R"){
			return 60-strSize*6;
		}
		else if(command==".C"){
			return 30-strSize*3;
		}
	}
}
void processLine(string s){
	string command,size;
	int startingCol=-1,startingRow;
	istringstream iss(s);
	iss>>command>>size>>startingRow;
	startingRow--;
	if(command==".P"){
		iss>>startingCol;
		startingCol--;
	}
	int start=-1,end=-1;
	for(int i=0;i<s.length();i++){
		if(s[i]=='|'){
			if(start==-1){
			  start=i;
			}
			else{
			  end=i;
			  break;
			}
		}
	}
	string substr=getSubStr(s,start+1,end-1);
	if(startingCol==-1)
	  startingCol=getStartingCol(command,size,substr.size());
	writeStr(startingRow,startingCol,size,substr);
}
void printGrid(){
	for(int i=0;i<60;i++){
		for(int j=0;j<60;j++)
			cout<<grid[i][j];
		cout<<endl;
	}
	cout<<endl<<"------------------------------------------------------------"<<endl<<endl;
}
void initGrid(){
	for(int i=0;i<60;i++)
		for(int j=0;j<60;j++)
			grid[i][j]='.';
}
int main(){
	redirect();
	initGrid();
	while(getline(cin,s)){
		if(s==".EOP"){
			printGrid();
			initGrid();
		}
		else
		    processLine(s);
	}
	return 0;
}