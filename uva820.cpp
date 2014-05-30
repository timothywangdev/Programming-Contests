#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

class MaxFlow{
private:
	vector<int> edge[100];
	int h[100];
	int f[100][100];
	int e[100];
	int cf[100][100];
	int c[100][100];
	bool l[100];
	int Source;
	int Sink;
	int N;
public:
	void init(int n,int s,int t){
		N=n;
		Source=s;
		Sink=t;
		memset(c,-1,sizeof(c));
		for(int i=0;i<N;i++){
			edge[i].clear();
		}
	}
	void addEdge(int u,int v,int ca){
		// Special Case
		if(c[u][v]!=-1){
			c[u][v]+=ca;
			return;
		}
		edge[u].push_back(v);
		c[u][v]=ca;
	}
	void relabel(int u){
		int tmp=-1;
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i];
			if(cf[u][v]>0){
				if(tmp==-1||tmp>h[v]){
					tmp=h[v];
				}
			}
		}
		h[u]=tmp+1;
	}
	void push(int u,int v){
		int delta=min(e[u],cf[u][v]);
		f[u][v]+=delta;
		f[v][u]=-f[u][v];
		e[u]-=delta;
		e[v]+=delta;
		cf[u][v]=c[u][v]-f[u][v];
		cf[v][u]=c[v][u]-f[v][u];
	}
	void init_preflow(){
		memset(h,0,sizeof(h));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
        h[Source]=N;
        for(int i=0;i<edge[Source].size();i++){
            int v=edge[Source][i];
            f[Source][v]=c[Source][v];
            f[v][Source]=-c[Source][v];
            e[v]=c[Source][v];
            e[Source]-=c[Source][v];
        }
        for(int i=0;i<N;i++){
        	for(int j=0;j<N;j++){
        		if(i!=j){
        			cf[i][j]=c[i][j]-f[i][j];
        			cf[j][i]=c[j][i]-f[j][i];
        		}
        	}
        }
	}
	int maxflow(){
		init_preflow();
        queue<int> q;
        memset(l,false,sizeof(l));
        for(int i=0;i<edge[Source].size();i++){
        	if(edge[Source][i]!=Sink){
        		q.push(edge[Source][i]);
        		l[edge[Source][i]]=true;
        	}
        }
        while(q.size()){
        	int u=q.front();
        	int m=-1;
        	for(int i=0;i<edge[u].size()&&e[u]>0;i++){
               int v=edge[u][i];
               if(cf[u][v]>0){
            	   if(h[u]>h[v]){
            		   push(u,v);
            		   if(!l[v]&&v!=Source&&v!=Sink){
            			   l[v]=true;
            			   q.push(v);
            		   }
            	   }
            	   else if(m==-1){
            		   m=h[v];
            	   }
            	   else{
            		   m=min(m,h[v]);
            	   }
               }
        	}
        	if(e[u]!=0){
        		h[u]=1+m;
        	}
        	else{
        		l[u]=0;
        		q.pop();
        	}
        }
        return e[Sink];
	}

};
MaxFlow mf;
int counter=0;
int n,m,s,t,a,b,c;
int main(){
 while(cin>>n){
	 if(!n){
		 break;
	 }
	 counter++;
	 cin>>s>>t>>m;
	 mf.init(n,s-1,t-1);
	 for(int i=0;i<m;i++){
		 cin>>a>>b>>c;
         mf.addEdge(a-1,b-1,c);
         mf.addEdge(b-1,a-1,c);
	 }
	 cout<<"Network "<<counter<<endl;
	 cout<<"The bandwidth is "<<mf.maxflow()<<"."<<endl<<endl;
 }
 return 0;
}
