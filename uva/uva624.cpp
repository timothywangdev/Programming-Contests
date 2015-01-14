#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<bool> used;
vector<bool> maxUsed;
int N,M,t,maximum,current;

void search(int pos){
	if(current>N)
		return;
	if(pos==M){
		if(current<=N&&current>maximum){
			maxUsed=used;
			maximum=current;
		}
		return;
	}
	search(pos+1);
	used[pos]=true;
	current+=v[pos];
	search(pos+1);
	used[pos]=false;
	current-=v[pos];
}
int main(){
	while(cin>>N>>M){
		v.clear();
		used.clear();
		for(int i=0;i<M;i++){
			cin>>t;
			v.push_back(t);
			used.push_back(false);
		}
		maximum=current=0;
		search(0);
		for(int i=0;i<M;i++)
			if(maxUsed[i])
				cout<<v[i]<<" ";
		cout<<"sum:"<<maximum<<endl;
	}
	return 0;
}