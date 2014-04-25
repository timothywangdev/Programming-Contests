#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
int N,t;
int main(){
    while(cin>>N){
		if(!N)
			break;
		while(pq.size())
			pq.pop();
		for(int i=0;i<N;i++){
			cin>>t;
			pq.push(t);
		}
		int cost=0;
		while(pq.size()>=2){
			int small=pq.top();
			pq.pop();
			int secondSmall=pq.top();
			pq.pop();
			cost+=small+secondSmall;
			pq.push(small+secondSmall);
		}
		cout<<cost<<endl;
	}
	return 0;
};