#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

int  N, M;
bool vis[244];
int match[244];
vector<vector<int> > edge;
map<int, char> toChar;
int gg;
int all;
int Aug(int l){
	if (vis[l]) return 0;
	vis[l] = 1;
	for (int j = 0; j < edge[l].size(); j++){
		int r = edge[l][j];
		if (match[r] == -1 || Aug(match[r])){
			match[r] = l;
			return 1;
		}
	}
	return 0;
}
int findMCBM(){
	memset(match, -1, sizeof(match));
	int MCBM = 0;
	for (int i = 0; i < gg; i++){
		memset(vis, false, sizeof(bool)*gg);
		MCBM += Aug(i);
	}
	return MCBM;
}
string s;

int main(){
	while (!cin.eof()){
		edge = vector<vector<int> >(234, vector<int>());
		toChar.clear();
		all = gg=0;
		while (getline(cin, s)){
			if (s == "")break;
			char A = s[0];
			int n = (int)(s[1] - '0');
			all += n;
			for (int i = 0; i < n; i++){
				toChar[gg] = A;
				if (s.size() >= 4){
					for (int j = 3; j < s.size() - 1; j++){
						edge[gg].push_back((int)(s[j] - '0') + 234);
					}
				}
				gg++;
			}
		}
		int total = findMCBM();
		if (total != all){
			cout << "!" << endl;
		}
		else{
			for (int i = 0; i <= 9; i++){
				if (match[i + 234] == -1){
					cout << "_";
					continue;
				}
				cout << toChar[match[i + 234]];
			}
			cout << endl;
		}
	}
	return 0;
}