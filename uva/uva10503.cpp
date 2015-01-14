#include <iostream>
#include <string.h>
using namespace std;
class domino{
public:
	int left;
	int right;
};
int N,M;
domino l,r,v[14],a,b;
bool found,used[14];
void search(int last,int n){
	if(found)
		return;
	if(n==N){
		if(last==r.left){
			found=true;
		}
		return;
	}
	for(int i=0;i<M;i++)
		if(!used[i]){
			used[i]=true;
	        if(v[i].left==last){
				search(v[i].right,n+1);
			}
			else if(v[i].right==last){
				search(v[i].left,n+1);
			}
			used[i]=false;
		}
}
int main(){
	while(cin>>N){
		if(!N)
			break;
		cin>>M;
		cin>>l.left>>l.right>>r.left>>r.right;
		for(int i=0;i<M;i++)
			cin>>v[i].left>>v[i].right;
		found=false;
		memset(used,false,sizeof(used));
		search(l.right,0);
		if(!found)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}