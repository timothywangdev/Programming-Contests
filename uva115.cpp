//#define DEBUG
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;
#ifdef DEBUG
ifstream fin("uva115.in");
ofstream fout("uva115.out");
#endif

struct Node{
	string name;
	int Nparents;
	int parent[300];
	int Nchilds;
	int child[300];
};

Node t[300];
int N=0,D1,D2;
map<string,int> toNode;
string child,parent,p1,p2;
map<string,int>::iterator childPtr,parentPtr;
void addChild(string child,int parent){
	t[N].Nchilds=0;
	t[N].Nparents=0;
	t[N].name=child;
	t[N].parent[t[N].Nparents]=parent;
	t[N].Nparents++;

	toNode[child]=N;
	t[parent].child[t[parent].Nchilds]=N;
	t[parent].Nchilds++;
	N++;
}

void addChild(int child,int parent){
	// Check if child's name exists  May be deleted!
	for(int i=0;i<t[parent].Nchilds;i++)
		if(t[t[parent].child[i]].name==t[child].name)
			return;

	t[child].parent[t[child].Nparents]=parent;
    t[child].Nparents++;
	t[parent].child[t[parent].Nchilds]=child;
	t[parent].Nchilds++;
}

void addChild(int child,string parent){
    t[N].Nchilds=0;
	t[N].Nparents=0;
	t[N].name=parent;
	toNode[parent]=N;
    N++;
    addChild(child,N-1);
}

void addNewTree(string child,string parent){
	t[N].Nchilds=0;
	t[N].Nparents=0;
	t[N].name=parent;
	toNode[parent]=N;
    N++;
	addChild(child,N-1);
}
int findpos(string name){
	map<string,int>::iterator it=toNode.find(name);
	if(it!=toNode.end())
		return it->second;
	return -1;
}

int existChild(string target,int current,int depth){
	if(target==t[current].name)
		return depth;

	int d;
	for(int i=0;i<t[current].Nchilds;i++){
		d=existChild(target,t[current].child[i],depth+1);
		if(d!=-1)
			return d;
	}
	return -1;
}
void displayChild(int depth){
    #ifdef DEBUG
	if(depth==1)
		fout<<"child"<<endl;
	else if(depth==2)
		fout<<"grand child"<<endl;
	else{
		for(int i=0;i<depth-2;i++)
			fout<<"great ";
		fout<<"grand child"<<endl;
	}
    #else
	if(depth==1)
		cout<<"child"<<endl;
	else if(depth==2)
		cout<<"grand child"<<endl;
	else{
		for(int i=0;i<depth-2;i++)
			cout<<"great ";
		cout<<"grand child"<<endl;
	}
    #endif
}
void displayParent(int depth){
	#ifdef DEBUG
	if(depth==1)
		fout<<"parent"<<endl;
	else if(depth==2)
		fout<<"grand parent"<<endl;
	else{
		for(int i=0;i<depth-2;i++)
			fout<<"great ";
		fout<<"grand parent"<<endl;
	}
	#else
	if(depth==1)
		cout<<"parent"<<endl;
	else if(depth==2)
		cout<<"grand parent"<<endl;
	else{
		for(int i=0;i<depth-2;i++)
			cout<<"great ";
		cout<<"grand parent"<<endl;
	}
	#endif
}
void displayCousin(int depth1,int depth2){
	int minDepth=min(depth1,depth2);
	int removed=abs(depth1-depth2);

	#ifdef DEBUG
	if(minDepth==1&&removed==0)
		fout<<"sibling"<<endl;
	else{
		fout<<minDepth-1<<" cousin";
		if(removed!=0)
			fout<<" removed "<<removed<<endl;
		else
			fout<<endl;

	}
	#else
	if(minDepth==1&&removed==0)
		cout<<"sibling"<<endl;
	else{
		cout<<minDepth-1<<" cousin";
		if(removed!=0)
			cout<<" removed "<<removed<<endl;
		else
			cout<<endl;
	}
	#endif
}
// 0: are cousins
// 1: is parent
// -1: not found
int cousinOrParent(string target,int current,int last,int depth){
	if(target==t[current].name){
		displayParent(depth);
		return 1;
	}
	int d;
	if(depth!=0)
		for(int i=0;i<t[current].Nchilds;i++)
			if(t[current].child[i]!=last){
				d=existChild(target,t[current].child[i],1);
				if(d!=-1){
					D1=d;
					D2=depth;
					return 0;
				}
			}
	int rv;
	for(int i=0;i<t[current].Nparents;i++){
        rv=cousinOrParent(target,t[current].parent[i],current,depth+1);
		if(rv!=-1)
			return rv;
	}
    return -1;
}
void checkRelationship(string p1,string p2){
	int pos1=findpos(p1);
	int pos2=findpos(p2);
	int depth,rv;
	if(pos1==-1||pos2==-1){
		#ifdef DEBUG
		fout<<"no relation"<<endl;
        #else
		cout<<"no relation"<<endl;
        #endif
		return;
	}

	depth=existChild(p1,pos2,0);
	if(depth!=-1){
		displayChild(depth);
		return;
	}
	rv=cousinOrParent(p1,pos2,-1,0);
	if(rv==-1){
		#ifdef DEBUG
		fout<<"no relation"<<endl;
        #else
		cout<<"no relation"<<endl;
        #endif
	}
	else if(rv==0)
		displayCousin(D1,D2);
}
int main(){
	while(true){
		#ifdef DEBUG
		fin>>child>>parent;
		#else
		cin>>child>>parent;
		#endif
		if(child=="no.child"&&parent=="no.parent")
			break;
        childPtr=toNode.find(child);
		parentPtr=toNode.find(parent);

		//Pair exists
		if(childPtr!=toNode.end()&&parentPtr!=toNode.end()){
			addChild(childPtr->second,parentPtr->second);
		}
		else if(childPtr==toNode.end()&&parentPtr!=toNode.end()){
			addChild(child,parentPtr->second);
		}
		else if(childPtr!=toNode.end()&&parentPtr==toNode.end()){
			addChild(childPtr->second,parent);
		}
		else if(childPtr==toNode.end()&&parentPtr==toNode.end()){
			addNewTree(child,parent);
		}
		
	}
	#ifdef DEBUG
	while(fin>>p1>>p2)
    #else
	while(cin>>p1>>p2)
    #endif
		checkRelationship(p1,p2);

	return 0;
}