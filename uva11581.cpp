#include <iostream>
#include <string>
#include <string.h>
using namespace std;

bool exist[512];
int pos[512];
int adj[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
string s;
int N,state;
bool getBitByPos(int &state,int pos){
	return (state & (1<<pos))>0;
}
void setBitByPos(int &state,int pos){
	state=state | (1<<pos);
}
bool getBit(int &state,int r,int c){
	return getBitByPos(state,r*3+c);
}
void setBit(int &state,int r,int c){
	setBitByPos(state,r*3+c);
}
void transform(int &state){
	int newState=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			int sum=0;
			for(int k=0;k<4;k++){
				int r=i+adj[k][0];
				int c=j+adj[k][1];
				if(0<=r&&r<3&&0<=c&&c<3)
					sum+=getBit(state,r,c);
			}
			if(sum%2==1)
			 setBit(newState,i,j);
		}
	state=newState;
}
int main(){
	cin>>N;
	getline(cin,s);
	for(int n=0;n<N;n++){
		state=0;
		memset(exist,false,sizeof(exist));
		getline(cin,s);
		for(int i=0;i<3;i++){
			getline(cin,s);
			for(int j=0;j<3;j++){
				if(s[j]=='1')
					setBit(state,i,j);
			}
		}
		int i=0;
		while(true){
			exist[state]=true;
			pos[state]=i;
			transform(state);
			i++;
			if(exist[state]){
				i=pos[state]-1;
				break;
			}
		}
		cout<<i<<endl;
	}
	return 0;
}