#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Pair{
public:
	int c;
	int value;
	Pair(int c,int value):c(c),value(value){}
};
struct row{
	vector<Pair> r;
};
vector<row> v,rv;
row v2;
int R,C,t,t1;
void transpose(int c,int r,int value){
	rv[r].r.push_back(Pair(c+1,-1));
	rv[r].r[rv[r].r.size()-1].value=value;
}
bool myComp(const Pair &a,const Pair &b){
	return a.c<b.c;
}
int main(){
	while(cin>>R>>C){
		v.clear();
		rv.clear();
		for(int i=0;i<R;i++){
			v2.r.clear();
			cin>>t;
			for(int j=0;j<t;j++){
				cin>>t1;
				v2.r.push_back(Pair(t1,-1));
			}
			for(int j=0;j<t;j++){
				cin>>t1;
				v2.r[j].value=t1;
			}
			v.push_back(v2);
		}
		for(int i=0;i<C;i++){
			row rvrow;
			rv.push_back(rvrow);
		}
		for(int i=0;i<R;i++){
			for(int j=0;j<v[i].r.size();j++){
				int r=i;
				int c=v[i].r[j].c-1;
				int value=v[i].r[j].value;
				transpose(r,c,value);
			}
		}
		cout<<C<<" "<<R<<endl;
		for(int i=0;i<C;i++){
			sort(rv[i].r.begin(),rv[i].r.end(),myComp);
			if(rv[i].r.size()==0){
				cout<<"0"<<endl<<endl;
			}
			else{
				int counter=1;
				cout<<rv[i].r.size();
				for(int j=0;j<rv[i].r.size();j++){
					counter++;
					if(counter==80){
						counter=0;
						cout<<endl;
						cout<<rv[i].r[j].c;
					}
					else{
					    cout<<" "<<rv[i].r[j].c;
					}
				}
				if(counter!=0)
					cout<<endl;
				counter=0;
				for(int j=0;j<rv[i].r.size();j++){
					counter++;
					if(counter==80){
						counter=0;
						cout<<endl;
						cout<<rv[i].r[j].value;
					}
					else{
						if(j>0)
							cout<<" ";
					    cout<<rv[i].r[j].value;
					}
				}
				if(counter!=0)
					cout<<endl;
			}
		}
	}
	return 0;
}