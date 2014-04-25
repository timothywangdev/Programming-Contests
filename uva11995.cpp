#include <iostream>
#include <stack>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

priority_queue<int,vector<int>,less<int>> pq;
stack<int> s;
queue<int> q;

int v[1000][2];
int N;
int a,b;
bool testPQ(){
	while(pq.size())
		pq.pop();
	for(int i=0;i<N;i++){
		if(v[i][0]==1)
			pq.push(v[i][1]);
		else{
			if(!pq.size())
				return false;
			int t=pq.top();
			pq.pop();
			if(t!=v[i][1])
				return false;
		}
	}
	return true;
}
bool testQ(){
	while(q.size())
		q.pop();
	for(int i=0;i<N;i++){
		if(v[i][0]==1)
			q.push(v[i][1]);
		else{
			if(!q.size())
				return false;
			int t=q.front();
			q.pop();
			if(t!=v[i][1])
				return false;
		}
	}
	return true;
}
bool testS(){
	while(s.size())
		s.pop();
	for(int i=0;i<N;i++){
		if(v[i][0]==1)
			s.push(v[i][1]);
		else{
			if(!s.size())
				return false;
			int t=s.top();
			s.pop();
			if(t!=v[i][1])
				return false;
		}
	}
	return true;
}
int main(){
	while(cin>>N){
		for(int i=0;i<N;i++){
			cin>>v[i][0]>>v[i][1];
		}
		bool isPQ=testPQ();
		bool isQ=testQ();
		bool isS=testS();
		if(isS&&!isPQ&&!isQ)
			cout<<"stack"<<endl;
		else if(!isS&&isPQ&&!isQ)
			cout<<"priority queue"<<endl;
		else if(!isS&&!isPQ&&isQ)
			cout<<"queue"<<endl;
		else if(!isS&&!isPQ&&!isQ)
			cout<<"impossible"<<endl;
		else
			cout<<"not sure"<<endl;
	}
	return 0;
}