#include <iostream>

using namespace std;

unsigned int N, L, U,rv;

bool getBit(unsigned int num, int pos){
	return ((num&(1 << pos)) !=0);
}
void turnOn(unsigned int &num, int pos){
	num |= (1 << pos);
}
void turnOff(unsigned int &num, int pos){
	num &= ~(1 << pos);
}
unsigned int getMax(int start){
	unsigned int k = 0;
	turnOn(k, start + 1);
	return k - 1;
}
int main(){
	while (cin >> N >> L >> U){
		rv = 0;
		for (int i = 31; i >= 0; i--){
			if (!getBit(N, i)){
				turnOn(rv, i);
				if (rv > U){
					turnOff(rv, i);
				}
			}
			else{
				if (rv+getMax(i - 1) < L){
					turnOn(rv, i);
				}
			}
		}
		cout << rv << endl;
	}
	return 0;
}