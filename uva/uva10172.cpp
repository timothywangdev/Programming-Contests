#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<int> car;
queue<int> s[100];
int N,S,Q,n,t,SET,counter;
int main(){
	cin>>SET;
	for(int k=0;k<SET;k++){
		cin>>N>>S>>Q;
		counter=0;
		for(int i=0;i<N;i++){
			cin>>n;
			for(int j=0;j<n;j++){
				cin>>t;
				s[i].push(t);
			}
			counter+=n;
		}
		int pos=0;
		int T=0;
		while(counter){
			while(car.size()){
				if(car.top()==pos+1){
					car.pop();
					counter--;
					T++;
				}
				else{
					if(s[pos].size()==Q)
						break;
					s[pos].push(car.top());
					car.pop();
					T++;
				}
			}
			while(s[pos].size()){
				if(car.size()==S)
					break;
				car.push(s[pos].front());
				s[pos].pop();
				T++;
			}
			pos=(pos+1)%N;
			if(counter)
			 T+=2;
		}
		cout<<T<<endl;
	}
	return 0;
}