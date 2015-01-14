#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int T,V,E,a,b;
bool m[200][200];
int color[200];
queue<int> q;
int maximum;
int checkBipartite(int index){
	q.push(index);
	color[index]=0;
	int sum=0;
	bool isBipartite=true;
	int totalV=1;
	while(q.size()&&isBipartite){
		int k=q.front();
		q.pop();
		for(int j=0;j<V;j++){
			if(m[k][j]){
				if(color[j]==-1){
					color[j]=1-color[k];
					sum+=color[j];
					q.push(j);
					totalV++;
				}
				else if(color[j]==color[k]){
					isBipartite=false;
					break;
				}
			}
		}
	}
	if(isBipartite){
		return max(1,min(sum,totalV-sum));
	}
	else{
		return -1;
	}
}
int main(){
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>V>>E;
		memset(m,false,sizeof(m));
		for(int j=0;j<E;j++){
			cin>>a>>b;
			m[a][b]=m[b][a]=true;
		}
		memset(color,-1,sizeof(color));
		while(q.size()){
			q.pop();
		}
		maximum=0;
		for(int j=0;j<V;j++){
			if(color[j]==-1){
				int k=checkBipartite(j);
				if(k==-1){
					maximum=-1;
					break;
				}
				else{
					maximum+=k;
				}
			}
		}
		cout<<maximum<<endl;
	}
	return 0;
}
