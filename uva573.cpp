#include <iostream>

using namespace std;

double H,D,U,F,diff;
int main(){

	while(cin>>H>>U>>D>>F){
		if(H==0)
			break;
		double height=0;
		int day=0;
		diff=U*(F/100);
		while(true){
			day++;
			if(U>=0)
			 height+=U;
			U-=diff;
			if(height>H){
				cout<<"success on day "<<day<<endl;
				break;
			}
			height-=D;
			if(height<0){
				cout<<"failure on day "<<day<<endl;
				break;
			}
		}
	}
	return 0;
}