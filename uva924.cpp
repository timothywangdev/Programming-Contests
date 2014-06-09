#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N,T,n,tmp;
vector<int> edge[2500];
bool used[2500];
void bfs(int index){
	memset(used,false,sizeof(used));
	vector<int> today,nextDay;
	used[index]=true;
	today.push_back(index);
	int firstDay=-1,maximum=0;
	for(int day=1;;day++){
		for(int i=0;i<today.size();i++){
			for(int j=0;j<edge[today[i]].size();j++){
				int k=edge[today[i]][j];
				if(!used[k]){
					used[k]=true;
					nextDay.push_back(k);
				}
			}
		}
		today=nextDay;
		nextDay.clear();
		if(today.size()>maximum){
			maximum=today.size();
			firstDay=day;
		}
		if(today.size()==0){
			break;
		}
	}
    if(firstDay==-1){
    	cout<<"0"<<endl;
    }
    else{
    	cout<<maximum<<" "<<firstDay<<endl;
    }
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>n;
		edge[i].clear();
		for(int j=0;j<n;j++){
			cin>>tmp;
			edge[i].push_back(tmp);
		}
	}
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>tmp;
		bfs(tmp);
	}
	return 0;
}
