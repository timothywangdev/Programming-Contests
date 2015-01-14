#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Query{
public:
	int id;
	int nextTime;
	int interval;
	Query(int id,int interval,int nextTime):id(id),interval(interval),nextTime(nextTime){}
};
class Compare{
public:
	bool operator()(const Query &a,const Query &b){
		if(a.nextTime>b.nextTime)
			return true;
		else if(a.nextTime==b.nextTime&&a.id>b.id)
			return true;
		return false;
	}
};

priority_queue<Query,vector<Query>,Compare> pq;
string tmp;
int a,b,N;
int main(){
	while(true){
		cin>>tmp;
		if(tmp=="#")
			break;
		cin>>a>>b;
		pq.push(Query(a,b,b));
	}
	cin>>N;
	for(int i=0;i<N;i++){
		Query t=pq.top();
		pq.pop();
		cout<<t.id<<endl;
		t.nextTime=t.nextTime+t.interval;
		pq.push(t);
	}
	return 0;
};