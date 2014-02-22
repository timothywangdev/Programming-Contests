#include <iostream>
#include <vector>
using namespace std;

int N,P,S,D,a,b;
int ne[110];
vector<int> p;
bool finished;
int main(){
    cin>>N;
	for(int i=0;i<N;i++){
		p.clear();
		cin>>P>>S>>D;
		finished=false;
		for(int i=0;i<P;i++)
			p.push_back(1);
		for(int i=1;i<=100;i++)
			ne[i]=i;
		for(int i=0;i<S;i++){
			cin>>a>>b;
			ne[a]=b;
		}
		for(int i=0;i<D;i++){
			cin>>a;
			if(finished)
				continue;
			p[i%P]=p[i%P]+a;
			if(p[i%P]>100)
				p[i%P]=100;
			p[i%P]=ne[p[i%P]];
			if(p[i%P]==100)
				finished=true;
		}
		for(int i=0;i<P;i++){
			cout<<"Position of player "<<i+1<<" is "<<p[i]<<"."<<endl;
		}
	}
	return 0;
}