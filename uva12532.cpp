#include <iostream>
using namespace std;
#define INFINITY 2147483647
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva12532.in");
ofstream fout("uva12532.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
int v[100000];
int N,K,a,b;
char ch;
class SegmentTree{
private:
	short st[400001];
	int left(int p){return p<<1;}
	int right(int p){return (p<<1)+1;};
	void build(int p,int L,int R){
		if(L==R){
			if(v[L]>0)
			 st[p]=1;
			else if(v[L]<0)
			 st[p]=-1;
			else
			 st[p]=0;
		}
		else{
			build(left(p),L,(L+R)/2);
			build(right(p),(L+R)/2+1,R);
			int l=st[left(p)];
			int r=st[right(p)];
			st[p]=l*r;
		}
	}
	int rmq(int p,int L,int R,int i,int j){
		if(i>R||j<L)
			return -INFINITY;
		if(i<=L&&R<=j){
			return st[p];
		}
		int l=rmq(left(p),L,(L+R)/2,i,j);
		int r=rmq(right(p),(L+R)/2+1,R,i,j);
		if(l==-INFINITY)return r;
		if(r==-INFINITY)return l;
		return l*r;
	}
public:
	char query(int i,int j){
		int k=rmq(1,0,N-1,i,j);
		if(k>0)
			return '+';
		else if(k<0)
			return '-';
		else
			return '0';
	}
	void update(int p,int L,int R,int i){
		if(!(L<=i&&i<=R))
			return;
		if(L==R){
			if(v[L]>0)
			 st[p]=1;
			else if(v[L]<0)
			 st[p]=-1;
			else
			 st[p]=0;
			return;
		}
		update(left(p),L,(L+R)/2,i);
		update(right(p),(L+R)/2+1,R,i);
		st[p]=st[left(p)]*st[right(p)];
	}
	void buildTree(){
		build(1,0,N-1);
	}
};
SegmentTree st;
int main(){
	redirect();
	while(cin>>N>>K){
		for(int i=0;i<N;i++)
			cin>>v[i];
		st.buildTree();
		for(int i=0;i<K;i++){
			cin>>ch>>a>>b;
			if(ch=='C'){
				v[a-1]=b;
				st.update(1,0,N-1,a-1);
			}
			else{
				cout<<st.query(a-1,b-1);
			}
		}
		cout<<endl;
	}
	return 0;
}