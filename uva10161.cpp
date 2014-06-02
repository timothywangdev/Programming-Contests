#include <iostream>
#include <cmath>
using namespace std;
long long N;
long long f(long long n){
	return 2 + (n - 2)*n;
}
int main(){
	while (cin >> N){
		if (!N){
			break;
		}
		long long n = (int)sqrt((double)(N - 1)) + 1;
		long long an = f(n);
		long long an_1 = f(n + 1);
		long long p = (an_1 - an + 1) / 2;
		long long delta = N - an;
		if (n % 2 == 1){
			if (delta < p){
				cout << n << " " << delta + 1 << endl;
			}
			else{
				cout << n - delta + p - 1 << " " << n << endl;
			}
		}
		else{
			if (delta < p){
				cout << delta + 1 << " " <<n << endl;
			}
			else{
				cout << n<<" "<<n - delta + p - 1 << endl;
			}
		}
	}
	return 0;
}