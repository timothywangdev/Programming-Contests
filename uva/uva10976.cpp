#include <iostream>
#include <algorithm>
using namespace std;

int n;
int gcd(int a,int b){
	if(a<b)
		swap(a,b);
	if(b==0)
		return a;
	return gcd(b,a%b);
}
void printLine(int left,int right1,int right2){
	cout<<"1/"<<left<<" = "<<"1/"<<right1<<" + "<<"1/"<<right2<<endl;
}
int main(){
	int counter;
	while(cin>>n){
		counter=0;
		for(int i=2*n;i-n>=1;i--){
			int upper=i-n;
			int lower=i*n;
			int k=gcd(upper,lower);
			if(k==upper){
				counter++;
			}
		}
		cout<<counter<<endl;
		for(int i=1+n;i<=2*n;i++){
			int upper=i-n;
			int lower=i*n;
			int k=gcd(upper,lower);
			if(k==upper){
				printLine(n,lower/k,i);
			}
		}
	}
	return 0;
}