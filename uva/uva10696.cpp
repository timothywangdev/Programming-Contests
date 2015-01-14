#include <iostream>
using namespace std;

int n;
int f(int k){
    if(k>=101)
		return k-10;
	else
		return f(f(k+11));
}
int main(){
	while(cin>>n){
		if(n==0)
			break;
       cout<<"f91("<<n<<") = "<<f(n)<<endl;
	}
	return 0;
}