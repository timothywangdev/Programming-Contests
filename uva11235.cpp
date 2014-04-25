#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ori,freq;
int N,Q,t;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva11235.in");
ofstream fout("uva11235.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
class SegmentTree{
private:
	int st[800001];
	int left(int p){return p<<1;}
	int right(int p){return (p<<1)+1;};
	void build(int p,int L,int R){
		if(L==R){
			st[p]=L;
		}
		else{
			build(left(p),L,(L+R)/2);
			build(right(p),(L+R)/2+1,R);
			int l=st[left(p)];
			int r=st[right(p)];
			st[p]=(freq[l]<=freq[r])?r:l;
		}
	}
	int rmq(int p,int L,int R,int i,int j){
		if(i>R||j<L)
			return -1;
		if(i<=L&&R<=j){
			return st[p];
		}
		int l=rmq(left(p),L,(L+R)/2,i,j);
		int r=rmq(right(p),(L+R)/2+1,R,i,j);
		if(l==-1)return r;
		if(r==-1)return l;
		return (freq[l]<=freq[r])?r:l;
	}
	bool checkBoundary(int targetPos,int result,bool left){
		if(left){
			if(targetPos-1>=0)
				return ori[targetPos-1]!=result;
			else
				return false;
		}
		else{
			if(targetPos+1<freq.size())
				return ori[targetPos+1]!=result;
			else
				return false;
		}

	}
public:
	void buildTree(){
		build(1,0,freq.size()-1);
	}
	int query(int left,int right){
		if(left==right)
			return 1;
		int pos=rmq(1,0,freq.size()-1,left,right);
		int k=freq[pos];
		int leftCount=0;
		int rightCount=0;
		if(!checkBoundary(left,ori[pos],true)){
			for(int i=left;i<=right;i++){
				if(ori[i]!=ori[pos]){
					break;
				}
				else{
					leftCount++;
				}
			}
		}
		if(!checkBoundary(right,ori[pos],false)){
			for(int i=right;i>=left;i--){
				if(ori[i]!=ori[pos]){
					break;
				}
				else{
					rightCount++;
				}
			}
		}
		if(leftCount&&rightCount){
			return right-left+1;
		}
		else if(leftCount&&!rightCount){
			if(leftCount==right-left+1)
				return leftCount;
			return max(leftCount,query(left+leftCount,right));
		}
		else if(!leftCount&&rightCount){
			if(rightCount==right-left+1)
				return rightCount;
			return max(query(left,right-rightCount),rightCount);
		}
		else{
			return k;
		}
	}
};
SegmentTree st;
int a,b;
void pushToFreq(int frequence){
	for(int i=0;i<frequence;i++)
		freq.push_back(frequence);
}
void translateToFreq(){
	int last=0;
	int count=0;
	bool first=true;
	for(int i=0;i<ori.size();i++){
		if(first){
          last=ori[i];
			count=1;
			first=false;
			continue;
		}
		if(last==ori[i]){
		   count++;
		}
		else{
			pushToFreq(count);
			last=ori[i];
			count=1;
		}
	}
	pushToFreq(count);
}
int main(){
	redirect();
	while(cin>>N){
		if(!N)
			break;
		cin>>Q;
		ori.clear();
		freq.clear();
		for(int i=0;i<N;i++){
			cin>>t;
			ori.push_back(t);
		}
		translateToFreq();
		st.buildTree();
		for(int j=0;j<Q;j++){
			cin>>a>>b;
			cout<<st.query(a-1,b-1)<<endl;
		}
	}
	return 0;
}