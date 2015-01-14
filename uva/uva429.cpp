#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <string.h>
#include <utility>
using namespace std;

string s,v[2000];
bool used[2000];
int T,N;
map<string,int> toid;
bool differByOne(string a,string b){
	if(a.size()!=b.size()){
		return false;
	}
	int sum=0;
	for(int i=0;i<a.length();i++){
		if(a[i]!=b[i]){
			sum++;
		}
	}
	return sum==1;
}
void process(string s){
	istringstream iss(s);
	string from,to;
	iss>>from>>to;
	queue<pair<string,int> > q;
    memset(used,false,sizeof(used));
    q.push(make_pair(from,0));
    used[toid[from]]=true;
    bool found=false;
    while(q.size()){
    	pair<string,int> front=q.front();
    	q.pop();
    	if(front.first==to){
    		cout<<from<<" "<<to<<" "<<front.second<<endl;
    		return;
    	}
    	for(int i=0;i<N;i++){
    		if(!used[i]&&differByOne(front.first,v[i])){
    			used[toid[front.first]]=true;
    			q.push(make_pair(v[i],front.second+1));
    		}
    	}
    }
}
int main(){
    cin>>T;
    getline(cin,s);
    getline(cin,s);
    for(int t=0;t<T;t++){
    	if(t>0){
    		cout<<endl;
    	}
    	toid.clear();
    	while(getline(cin,s)){
           if(s=="*"){
              break;
           }
           else{
        	   toid[s]=N;
        	   v[N]=s;
        	   N++;
           }
    	}
    	while(getline(cin,s)){
    		if(s==""){
    			break;
    		}
    		process(s);
    	}
    }
	return 0;
}
