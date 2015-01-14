#include <queue>
#include <string.h>
#include <iostream>
#include <utility>
using namespace std;

int L,U,N;
int v[10];
bool visited[10000];
queue<pair<int,int> > q;
int counter=0;
int trim(int k){
	if(k<=9999){
		return k;
	}
	else{
       return k-10000;
	}
}
int bfs(){
	while(q.size()){
		pair<int,int> front=q.front();
		q.pop();
		if(front.first==U){
			return front.second;
		}
		for(int i=0;i<N;i++){
			int k=trim(front.first+v[i]);
			if(!visited[k]){
				visited[k]=true;
				q.push(make_pair(k,front.second+1));
			}
		}
	}
	return -1;
}
int main(){
    while(cin>>L>>U>>N){
    	if(!L&&!U&&!N){
    		break;
    	}
    	for(int i=0;i<N;i++){
    		cin>>v[i];
    	}
    	counter++;
    	memset(visited,false,sizeof(visited));
    	visited[L]=true;
    	q.push(make_pair(L,0));
    	int k=bfs();
    	cout<<"Case "<<counter<<": ";
    	if(k==-1){
    		cout<<"Permanently Locked"<<endl;
    	}
    	else{
    		cout<<k<<endl;
    	}
    	while(q.size()){
    		q.pop();
    	}
    }
	return 0;
}
