#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
ifstream fin("uva201.in");
ofstream fout("uva201.out");
#endif
void redirect(){
#ifdef DEBUG
std::streambuf *cinbuf = std::cin.rdbuf();
std::cin.rdbuf(fin.rdbuf());
//std::streambuf *coutbuf = std::cout.rdbuf();
//std::cout.rdbuf(fout.rdbuf());
#endif
}

bool connected[9][9][9][9],first=true;
int N,M,a,b,pcount=0;
int count[10];
char ch;
void dp(){
	for(int i=0;i<N;i++)
		for(int s=0;s<N-1;s++)
			for(int e=s+1;e<N;e++)
			  if(e-s>1){
			   connected[i][s][i][e]=connected[i][s][i][e-1]&&connected[i][e-1][i][e];
			   connected[s][i][e][i]=connected[s][i][e-1][i]&&connected[e-1][i][e][i];
			  }

}
bool exist(int size,int r,int c){
	if(r+size>=N||c+size>=N)
		return false;
	return connected[r][c][r][c+size]&&connected[r+size][c][r+size][c+size]&&
			connected[r][c][r+size][c]&&connected[r][c+size][r+size][c+size];
}
int main(){
	redirect();
    while(cin>>N>>M){
    	if(!first)
    	    		cout<<endl<<"**********************************"<<endl<<endl;
    	if(first)
    		first=false;
    	memset(connected,false,sizeof(connected));
    	memset(count,0,sizeof(count));
    	for(int i=0;i<M;i++){
    		cin>>ch>>a>>b;
    		a--;
    		b--;
    		if(ch=='H'){
    			connected[a][b][a][b+1]=true;
    		}
    		else{
    			connected[b][a][b+1][a]=true;
    		}
    	}
    	dp();
    	for(int size=1;size<N;size++){
    		for(int r=0;r<N;r++)
    			for(int c=0;c<N;c++)
    				if(exist(size,r,c))
    					count[size]++;
    	}
    	pcount++;
    	cout<<"Problem #"<<pcount<<endl<<endl;
    	bool existRec=false;
    	for(int i=1;i<N;i++){
    		if(count[i]>=1){
    			existRec=true;
    			cout<<count[i]<<" square (s) of size "<<i<<endl;
    		}
    	}
    	if(!existRec)
    		cout<<"No completed squares can be found."<<endl;
    }
	return 0;
}
