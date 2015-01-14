#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
#include <fstream>
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("test.in");
ofstream fout("test.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(fin.rdbuf());
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(fout.rdbuf());
#endif
}
map<string, int > toid;
map<int, string> toname;
int N, n,gg;
string s1,s2;
bool m[1000][1000];

struct KVP{
	string a;
	string b;
	KVP(string a, string b) :a(a), b(b){}
};
vector<KVP> rv;
void addNode(string s){
	if (toid.find(s) == toid.end()){
		toid[s] = gg;
		toname[gg] = s;
		gg++;
	}
}
void addEdge(string a, string b){
	addNode(a);
	addNode(b);
	m[toid[a]][toid[b]] = true;
}
int main(){
	redirect();
	int counter = 0;
	while (cin >> N){
		if (!N){
			break;
		}
		gg = 0;
		toid.clear();
		toname.clear();
		counter++;
		memset(m, false, sizeof(m));
		rv.clear();
		for (int i = 0; i < N; i++){
			cin >> n;
			for (int j = 0; j < n; j++){
				cin >> s2;
				addNode(s2);
				if (j>0){
					addEdge(s1, s2);
				}
				s1 = s2;
			}
		}
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> s1 >> s2;
			addEdge(s1, s2);
		}
		for (int k = 0; k < gg; k++){
			for (int i = 0; i < gg; i++){
				for (int j = 0; j < gg; j++){
					m[i][j] = m[i][j] || (m[i][k] && m[k][j]);
				}
			}
		}
		for (int i = 0; i < gg-1; i++){
			for (int j = i+1; j < gg; j++){
				if (!m[i][j] && !m[j][i]){
					rv.push_back(KVP(toname[i], toname[j]));
				}
			}
		}
		if (rv.size()>0){
			cout << "Case " << counter << ", " << rv.size() << " concurrent events:" << endl;
			if (rv.size() == 1){
				cout << "(" << rv[0].a << "," << rv[0].b << ") ";
			}
			else{
				for (int i = 0; i < 2; i++){
					cout << "(" << rv[i].a << "," << rv[i].b << ") ";
				}
			}
			cout << endl;
		}
		else{
			cout << "Case " << counter << ", no concurrent events." << endl;
		}
	}
	return 0;
}