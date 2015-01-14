#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#define INF 2147483647
using namespace std;
typedef pair<int,int> ii;

int T,N,E,L,M,a,b,c;
vector<pair<int,int> > edge[100];
int Dijkstra(){
	vector<int> dist(N,INF);
	dist[E-1]=0;
	priority_queue<ii,vector<ii>,greater<ii> >pq;
	pq.push(ii(0,E-1));
	while(pq.size()){
		ii front = pq.top();
		pq.pop();
		int d=front.first;
		int u=front.second;
		if(dist[u]<d) continue;
		for(int i=0;i<edge[u].size();i++){
			ii v=edge[u][i];
			if(dist[v.second]>dist[u]+v.first){
				dist[v.second]=dist[u]+v.first;
				pq.push(ii(dist[v.second],v.second));
			}
		}
	}
	int sum=0;
	for(int i=0;i<N;i++){
		if(dist[i]<=L){
			sum++;
		}
	}
	return sum;
}
int main(){
	cin>>T;
	for(int t=0;t<T;t++){
		if(t>0){
			cout<<endl;
		}
		cin>>N>>E>>L>>M;
		for(int i=0;i<N;i++){
			edge[i].clear();
		}
		for(int i=0;i<M;i++){
			cin>>a>>b>>c;
			a--;
			b--;
			edge[b].push_back(ii(c,a));
		}
		cout<<Dijkstra()<<endl;
	}
	return 0;
}
