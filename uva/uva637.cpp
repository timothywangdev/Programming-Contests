#include <iostream>

using namespace std;

int n;
int main(){
	while(cin>>n){
		if(!n)
			break;
		cout<<"Printing order for "<<n<<" pages:"<<endl;
		int dest=(n%4!=0)?n+4-n%4:n;
		int start=dest-n;
		int counter=1;
		for(int i=1;i<=dest/2&&counter<=n;i++){
			int page=(i%2==0)?i/2:i/2+1;
			cout<<"Sheet "<<page<<", ";
			if(i%2==1)
				cout<<"front: ";
			else
				cout<<"back : ";
			int right=-1,left=-1;
			if(i%2==1){
				right=i;
				if(i>start)
					left=dest+1-right;
			}
			else{
				left=i;
				if(i>start)
					right=dest+1-left;
			}
			if(left!=-1){
				cout<<left<<", ";
				counter++;
			}
			else
				cout<<"Blank, ";
			if(right!=-1){
				cout<<right<<endl;
				counter++;
			}
			else
				cout<<"Blank"<<endl;
		}
	}

	return 0;
}