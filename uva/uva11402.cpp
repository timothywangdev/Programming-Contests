#include <iostream>
#include <string>
#include <vector>
#define SET 1
#define CLEAR 2
#define FLIP 3
using namespace std;

//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva11402.in");
ofstream fout("uva11402.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}

bool pirates[40960010];
int U[4096001];
int position[10240000];
int N;
vector<int> changeList;
class SegmentTree{
private:
	int st[4096001];
	int left(int p){return p<<1;}
	int right(int p){return (p<<1)+1;};
	void build(int p,int L,int R){
		U[p]=0;
		if(L==R){
			st[p]=pirates[L];
		}
		else{
			build(left(p),L,(L+R)/2);
			build(right(p),(L+R)/2+1,R);
			int l=st[left(p)];
			int r=st[right(p)];
			st[p]=l+r;
		}
	}
	int rmq(int p,int L,int R,int i,int j){
		if(i>R||j<L)
			return -1;
		propagate(p,L,R);
		if(i<=L&&R<=j){
			return st[p];
		}
		int l=rmq(left(p),L,(L+R)/2,i,j);
		int r=rmq(right(p),(L+R)/2+1,R,i,j);
		if(l==-1)return r;
		if(r==-1)return l;
		return l+r;
	}
	int flip(int sign){
		if(sign==SET)
			return CLEAR;
		if(sign==CLEAR)
			return SET;
		if(sign==FLIP)
			return 0;
		if(sign==0)
			return FLIP;
	}
	void propagate(int p,int L,int R){
		if(U[p]==SET){
			st[p]=R-L+1;
			if(L!=R){
				U[left(p)]=SET;
				U[right(p)]=SET;
			}
		}
		else if(U[p]==CLEAR){
			st[p]=0;
			if(L!=R){
				U[left(p)]=CLEAR;
				U[right(p)]=CLEAR;
			}
		}
		else if(U[p]==FLIP){
			st[p]=R-L+1-st[p];
			if(L!=R){
				U[left(p)]=flip(U[left(p)]);
				U[right(p)]=flip(U[right(p)]);
			}
		}

		U[p]=0;
	}
public:
	void rangeSet(int p,int L,int R,int i,int j){
		propagate(p,L,R);
		if(R<i||L>j)
			return;
		if(L==R){
			st[p]=1;
			return;
		}
		if(i<=L&&R<=j){
			st[p]=R-L+1;
			U[left(p)]=SET;
			U[right(p)]=SET;
			return;
		}
		rangeSet(left(p),L,(L+R)/2,i,j);
		rangeSet(right(p),(L+R)/2+1,R,i,j);
		st[p]=st[left(p)]+st[right(p)];
	}
	void rangeClear(int p,int L,int R,int i,int j){
		propagate(p,L,R);
		if(R<i||L>j)
			return;
		if(L==R){
			st[p]=0;
			U[p]=0;
			return;
		}
		if(i<=L&&R<=j){
			st[p]=0;
			U[left(p)]=CLEAR;
			U[right(p)]=CLEAR;
			return;
		}
		rangeClear(left(p),L,(L+R)/2,i,j);
		rangeClear(right(p),(L+R)/2+1,R,i,j);
		st[p]=st[left(p)]+st[right(p)];
	}
	void rangeFlip(int p,int L,int R,int i,int j){
		propagate(p,L,R);
		if(R<i||L>j)
			return;
		if(L==R){
			st[p]=(st[p]==1)?0:1;
			return;
		}
		if(i<=L&&R<=j){
			st[p]=R-L+1-st[p];
			U[left(p)]=flip(U[left(p)]);
			U[right(p)]=flip(U[right(p)]);
			return;
		}
		rangeFlip(left(p),L,(L+R)/2,i,j);
		rangeFlip(right(p),(L+R)/2+1,R,i,j);
		st[p]=st[left(p)]+st[right(p)];
	}

	void buildTree(){
		build(1,0,N-1);
	}
	int query(int left,int right){
		return rmq(1,0,N-1,left,right);	
	}
};
SegmentTree st;
int T,P,M,a,b;
char ch;
string s;
void concatenate(int n,string s){
	for(int i=0;i<n;i++)
		for(int j=0;j<s.size();j++){
			N++;
			pirates[N]=(s[j]=='1');
		}
}
void toBuccaneer(int left,int right){
	//for(int i=left;i<=right;i++){
	//if(!pirates[i])
	//	changeList.push_back(i);
	//pirates[i]=true;
	//}
	st.rangeSet(1,0,N-1,left,right);
}
void toBarbary(int left,int right){
	//for(int i=left;i<=right;i++){
	//if(pirates[i])
	//	changeList.push_back(i);
	//pirates[i]=false;
	//}
	st.rangeClear(1,0,N-1,left,right);
}
void inverse(int left,int right){
	//for(int i=left;i<=right;i++){
	//changeList.push_back(i);
	//	pirates[i]=1-pirates[i];
	//}
	st.rangeFlip(1,0,N-1,left,right);
}
int main(){
	redirect();
	cin>>T;
	for(int t=0;t<T;t++){
		N=-1;
		cout<<"Case "<<t+1<<":"<<endl;
		cin>>P;
		for(int i=0;i<P;i++){
			cin>>a>>s;
			concatenate(a,s);
		}
		N++;
		st.buildTree();
		cin>>M;
		int counter=0;
		for(int i=0;i<M;i++){
			cin>>ch>>a>>b;
			if(ch=='F')
				toBuccaneer(a,b);
			else if(ch=='E')
				toBarbary(a,b);
			else if(ch=='I')
				inverse(a,b);
			else{
				counter++;
				cout<<"Q"<<counter<<": "<<st.query(a,b)<<endl;
			}
		}
	}
	return 0;
}