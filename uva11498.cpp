#include <iostream>

using namespace std;
int n,ox,oy,x,y;
int getQuadrant(int x,int y){
	if(x<0&&y>0)
		return 1;
	else if(x>0&&y>0)
		return 2;
	else if(x>0&&y<0)
		return 3;
	else if(x<0&&y<0)
		return 4;
	else
		return 5;
}
int main(){
	while(cin>>n){
		if(n==0)
			break;
		cin>>ox>>oy;
		for(int i=0;i<n;i++){
			cin>>x>>y;
			x-=ox;
			y-=oy;
			int k=getQuadrant(x,y);
			if(k==1)
				cout<<"NO"<<endl;
			else if(k==2)
				cout<<"NE"<<endl;
			else if(k==3)
				cout<<"SE"<<endl;
			else if(k==4)
				cout<<"SO"<<endl;
			else
				cout<<"divisa"<<endl;
		}
	}
	return 0;
}