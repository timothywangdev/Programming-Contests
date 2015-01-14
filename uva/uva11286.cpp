#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<vector<int>,int> m;
map<vector<int>,int>::iterator maxit;
int N,t,maximum;
int main(){
	while(cin>>N){
	   if(!N)
		   break;
	   m.clear();
	   maximum=0;
	   for(int i=0;i<N;i++){
		   vector<int> v;
		   for(int j=0;j<5;j++){
			   cin>>t;
			   v.push_back(t);
		   }
		   sort(v.begin(),v.end());
		   map<vector<int>,int>::iterator it=m.find(v);
		   if(it!=m.end()){
			   it->second++;
		   }
		   else{
			   m[v]=1;
		   }
		   int p=m[v];
		   if(p>maximum){
			   maximum=p;
			   maxit=it;
		   }
	   }
	   int sum=0;
	   for(map<vector<int>,int>::iterator it=m.begin();it!=m.end();it++){
		   if(it->second==maximum){
			   sum+=it->second;
		   }
	   }
	   cout<<sum<<endl;
	}
	return 0;
}