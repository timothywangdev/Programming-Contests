#include <iostream>
#include <vector>
using namespace std;
int price;
int N,B,H,W,p,minimum;
int main(){
	while(cin>>N>>B>>H>>W){
		bool found=false;
		for(int i=0;i<H;i++){
			cin>>price;
			for(int j=0;j<W;j++){
				cin>>p;
				if(p>=N&&price*N<=B){
					if(!found){
						found=true;
						minimum=price*N;
					}
					else if(price*N<minimum){
						minimum=price*N;
					}
				}
			}
		}
		if(!found)
			cout<<"stay home"<<endl;
		else
			cout<<minimum<<endl;
	}
	return 0;
}