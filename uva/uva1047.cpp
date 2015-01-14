#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int P,N,M,t,n,maximum;
vector<int> tower,intersection[10],current,maxTower;
int value[10];
void copy(){
	maxTower.clear();
	for(int i=0;i<N;i++){
		maxTower.push_back(current[i]);
	}
}
bool inSet(int index,int &num){
	num=0;
	for(int j=0;j<N;j++){
		for(int i=0;i<intersection[index].size();i++){
			if(current[j]==intersection[index][i])
				num++;
		}
	}
	if(num!=0)
	 num--;
	return true;
}
int getTotal(){
	int sum=0;
	for(int i=0;i<N;i++){
		sum+=tower[current[i]];
	}
	int num;
	for(int i=0;i<M;i++){
		if(inSet(i,num)){
			sum-=num*value[i];
		}
	}
	return sum;
}
void search(int last,int pos){
	if(pos==N){
		int k=getTotal();
		if(k>maximum){
			maximum=k;
			copy();
		}
		return;
	}
	for(int i=last+1;i<P;i++){
		current.push_back(i);
		search(i,pos+1);
		current.pop_back();
	}
}
int counter=0;
int main(){
	while(cin>>P>>N){
		if(!P&&!N)
			break;
		tower.clear();
		for(int i=0;i<P;i++){
			cin>>t;
			tower.push_back(t);
		}
		cin>>M;
		for(int i=0;i<M;i++){
			intersection[i].clear();
			cin>>n;
			for(int j=0;j<n;j++){
				cin>>t;
				intersection[i].push_back(t-1);
			}
			sort(intersection[i].begin(),intersection[i].end());
			cin>>value[i];
		}
		maximum=0;
		current.clear();
		search(-1,0);
		counter++;
		
		cout<<"Case Number  "<<counter<<endl;
		cout<<"Number of Customers: "<<maximum<<endl;
		cout<<"Locations recommended:";
		for(int i=0;i<N;i++){
			cout<<" "<<maxTower[i]+1;
		}
		cout<<endl<<endl;
	}
	return 0;
}