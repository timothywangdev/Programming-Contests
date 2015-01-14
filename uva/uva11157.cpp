#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> v;
int T, N, D;
int s,tmp;
char ch;
string str;
int rv;
int getMin(int s, int e){
	int minimum = -1;
	int pre = s;
	for (int i = 0; i < v.size(); i += 2){
		minimum = max(minimum, v[i] - pre);
		pre = v[i];
	}
	minimum = max(minimum, e - pre);
	pre = s;
	for (int i = 1; i < v.size(); i += 2){
		minimum = max(minimum, v[i] - pre);
		pre = v[i];
	}
	minimum = max(minimum, e - pre);
	return minimum;
}
void process(){
	ch = str[0];
	string num = str.substr(2, str.size() - 2);
	istringstream iss(num);
	iss >> tmp;
}
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N >> D;
		s = 0;
		rv = 0;
		for (int i = 0; i <= N; i++){
			if (i == N){
				tmp = D;
				ch = 'B';
			}
			else{
				cin >> str;
				process();
			}
			if (ch == 'B'){
				if (v.size() >= 2){
					rv = max(rv, getMin(s, tmp));	
				}
				else{
					rv = max(rv, tmp - s);
				}
				v.clear();
				s = tmp;
			}
			else{
				v.push_back(tmp);
			}
		}
		cout <<"Case "<<t+1<<": "<< rv << endl;
	}
	return 0;
}