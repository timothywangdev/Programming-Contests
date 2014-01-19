#include <iostream>
#include <fstream>
#include "string.h"
#include <vector>
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva193.in");
ofstream fout("uva193.out");
#endif
bool map[100][100];
bool used[100];
bool color[100];
vector<int> rv;
int N,n,k,a,b;
int sum,tmpSum;
void search(int index){
	if(index==n){
		if(tmpSum>sum){
		   sum=tmpSum;
           rv.clear();
		   for(int i=0;i<n;i++)
			   if(color[i])
				   rv.push_back(i+1);
		}
		return;
	}
	if(used[index])
		search(index+1);
	used[index]=true;

	// Check possibility
	bool blackPossible=true;
	for(int i=0;i<n;i++){
		if(map[index][i]&&used[i]&&color[i]==true){
			blackPossible=false;
			break;
		}
	}
	if(blackPossible){
		tmpSum++;
		color[index]=true;
		for(int i=0;i<n;i++){
			if(map[index][i]&&!used[i]){
				used[i]=true;
				color[i]=false;
			}
		}
		search(index+1);
	}

	color[index]=false;
	if(blackPossible)
       tmpSum--;
	search(index+1);
	used[index]=false;
}
void process(){
	tmpSum=0;
	sum=0;
	search(0);
	cout<<sum<<endl;
	for(unsigned int i=0;i<rv.size()-1;i++)
		cout<<rv[i]<<" ";
	cout<<rv[rv.size()-1]<<endl;
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		memset(map,false,sizeof(map));
		memset(used,false,sizeof(used));
		memset(color,false,sizeof(color));
		cin>>n>>k;
		for(int i=0;i<k;i++){
			cin>>a>>b;
			a--;
			b--;
			map[a][b]=map[b][a]=true;
		}
		process();
	}

	return 0;
}