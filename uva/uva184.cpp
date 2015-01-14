#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "string.h"
#include <vector>
using namespace std;
//#decine DEBUG
#ifdef DEBUG
ifstream cin("uva184.in");
ofstream cout("uva184.out");
#endif
struct p{
	int x;
	int y;
};

p ps[300];
bool used[300][300];
int N=0;
int x,y;
bool comp(const p &a,const p &b){
	if(a.x<b.x)
		return true;
	else if(a.x==b.x&&a.y<b.y)
		return true;
	return false;
}
bool parallel(int a,int b,int c){
	return (ps[b].x-ps[a].x)*(ps[c].y-ps[a].y)-(ps[c].x-ps[a].x)*(ps[b].y-ps[a].y)==0;
}
void display(int index){
	cout<<'('<<setw(4)<<ps[index].x<<','<<setw(4)<<ps[index].y<<')';
}
void process(){
	memset(used,false,sizeof(used));
	sort(ps,ps+N,comp);
	vector<int> usedNodes;
	bool foundOne=false;
	for(int first=0;first<N-2;first++)
		for(int second=first+1;second<N-1;second++){
			if(used[first][second]||used[second][first])
				continue;
			else{
				usedNodes.push_back(first);
				usedNodes.push_back(second);
			}
			bool found=false;
			for(int i=second+1;i<N;i++)
				if(parallel(first,second,i)){
					usedNodes.push_back(i);
					if(!found){
						found=true;
						if(!foundOne){
							cout<<"The following lines were found:"<<endl;
							foundOne=true;
						}
						display(first);
						display(second);
				    }
					display(i);
			 }
				if(found)
					cout<<endl;
			for(unsigned int j=0;j<usedNodes.size()-1;j++)
				for(unsigned int k=j+1;k<usedNodes.size();k++){
                   used[usedNodes[j]][usedNodes[k]]=used[usedNodes[k]][usedNodes[j]]=true;
				}
			usedNodes.clear();
		}
		if(!foundOne)
			cout<<"No lines were found"<<endl;
}
int main(){
	while(cin>>x>>y){
		if(x==0&&y==0){
			if(N==0)
				break;
			else{
				process();
				N=0;
			}
		}
		else{
			ps[N].x=x;
			ps[N].y=y;
			N++;
		}
	}
	return 0;
}