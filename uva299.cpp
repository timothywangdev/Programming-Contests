#include <iostream>
#include <fstream>
#include "string.h"
using namespace std;
#define DEBUG
#ifdef DEBUG
ifstream fin("uva299.in");
ofstream fout("uva299.out");
#endif
int N,n,v[50],m;
bool changed[50][50],good[50];

void search(int c){
	int ok=true;
	for(int i=0;i<n;i++)
		if(!good[i]){
			ok=false;
			break;
		}
	if(ok){
		if(c<m)
			m=c;
		return;
	}
	for(int i=0;i<n-1;i++){
		int j=i+1;
			if(!good[i]&&!good[j]&&!changed[v[i]][v[j]]){
				swap(v[i],v[j]);
				good[i]=(v[i]==i+1);
				good[j]=(v[j]==j+1);
				changed[v[i]][v[j]]=changed[v[j]][v[i]]=true;
				search(c+1);
				changed[v[i]][v[j]]=changed[v[j]][v[i]]=false;
				swap(v[i],v[j]);
				good[i]=(v[i]==i+1);
				good[j]=(v[j]==j+1);
			}
	}
}
int main(){
	fin>>N;
	for(int i=0;i<N;i++){
		memset(changed,false,sizeof(changed));
		memset(good,false,sizeof(good));
		fin>>n;
		m=200000000;
		for(int j=0;j<n;j++){
			fin>>v[j];
			if(v[j]==j+1)
				good[j]=true;
		}
		search(0);
		fout<<m<<endl;
	}
	return 0;
}