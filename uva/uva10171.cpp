#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define INF 842150450
using namespace std;

int my[26][26], mm[26][26];
bool ty[26][26];

int N;
char aty, rty, a, b;
int t;
vector<char> rv;
int main(){
	while (cin >> N){
		if (!N){
			break;
		}
		rv.clear();
		memset(my, 50, sizeof(my));
		memset(mm, 50, sizeof(mm));
		for (int i = 0; i < N; i++){
			cin >> aty >> rty >> a >> b >> t;
			if (aty == 'M'){
				mm[a - 'A'][b - 'A'] = t;
			}
			else{
				my[a - 'A'][b - 'A'] = t;
			}
			if (rty == 'B'){
				if (aty == 'M'){
					mm[b - 'A'][a - 'A'] = t;
				}
				else{
					my[b - 'A'][a - 'A'] = t;
				}
			}
		}
		for (int i = 0; i < 26; i++){
			my[i][i] = mm[i][i] = 0;
		}
		for (int k = 0; k < 26; k++){
			for (int i = 0; i < 26; i++){
				for (int j = 0; j < 26; j++){
					if (i != j&&j != k&&i != k){
						my[i][j] = min(my[i][j], my[i][k] + my[k][j]);
						mm[i][j] = min(mm[i][j], mm[i][k] + mm[k][j]);
					}
				}
			}
		}
		cin >> a >> b;
		int minimum = INF;
		if (a == b){
			minimum = 0;
			rv.push_back(a);
		}

		
		for (int k = 0; k < 26; k++){
			if (my[a - 'A'][k] + mm[b - 'A'][k] < minimum){
				minimum = my[a - 'A'][k] + mm[b - 'A'][k];
				rv.clear();
				if (find(rv.begin(), rv.end(), (char)(k + 'A')) == rv.end()){
					rv.push_back((char)(k + 'A'));
				}
			}
			else if (my[a - 'A'][k] + mm[b - 'A'][k] == minimum&&minimum != INF){
				if (find(rv.begin(), rv.end(), (char)(k + 'A')) == rv.end()){
					rv.push_back((char)(k + 'A'));
				}
			}
		}
		if (rv.size() == 0){
			cout << "You will never meet." << endl;
		}
		else{
			cout << minimum;
			for (int i = 0; i < rv.size(); i++){
				cout << " " << rv[i];
			}
			cout << endl;
		}
	}

	return 0;
}