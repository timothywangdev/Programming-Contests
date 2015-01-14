#include <iostream>
#include <algorithm>
using namespace std;

int n,a,b;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		int y=(a+b)/2;
		int x=a-y;
		if(x<0||y<0||y*2!=(a+b))
			cout<<"impossible"<<endl;
		else{
			if(x<y)
				swap(x,y);
			cout<<x<<" "<<y<<endl;
		}
	}
	return 0;
}