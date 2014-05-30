#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
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
class Link{
public:
	int a;
	int b;
	Link(int x, int y){
		if (x <= y){
			a = x;
			b = y;
		}
		else{
			a = y;
			b = x;
		}
	}
};
vector< vector<int> >edges;
vector<Link> links;
int N, a, b;
string s;
int sum, counter, root, rootCount;
vector<int> low, num, parent;
bool first=true;
int getValue(string s){
	string ss = s.substr(1, s.size() - 2);
	istringstream iss(ss);
	int k;
	iss >> k;
	return k;
}
void addEdges(string s){
	istringstream iss(s);
	iss >> a;
	int tmp;
	string str;
	iss >> str;
	tmp = getValue(str);
	if (tmp == 0){
		return;
	}
	while (iss >> b){
		edges[a].push_back(b);
	}
}
void findArticulationPoints(int index){
	low[index] = num[index] = counter++;
	for (int i = 0; i < edges[index].size(); i++){
		if (num[edges[index][i]] == -1){
			parent[edges[index][i]] = index;
			findArticulationPoints(edges[index][i]);
			if (low[edges[index][i]] > num[index]){
				links.push_back(Link(index, edges[index][i]));
			}
			low[index] = min(low[index], low[edges[index][i]]);
		}
		else if (parent[index] != edges[index][i]){
			low[index] = min(low[index], num[edges[index][i]]);
		}
	}
}
bool myFunc(const Link &a, const Link &b){
	if (a.a < b.a){
		return true;
	}
	else if (a.a == b.a){
		return a.b < b.b;
	}
	return false;
}
int main(){
	redirect();
	while (cin >> N){
		/*
		if (first){
			first = false;
		}
		else{
			cout << endl;
		}
		*/
		links.clear();
		edges.clear();
		parent.clear();
		num.clear();
		low.clear();
		counter = 0;
		for (int i = 0; i < N; i++){
			vector<int> v;
			edges.push_back(v);
			parent.push_back(0);
			num.push_back(-1);
			low.push_back(0);
		}
		getline(cin, s);
		for (int i = 0; i < N; i++){
			getline(cin, s);
			addEdges(s);
		}
		for (int i = 0; i < N; i++){
			if (num[i] == -1){
				findArticulationPoints(i);
			}
		}
		cout << links.size() << " critical links" << endl;
		sort(links.begin(), links.end(), myFunc);
		for (int i = 0; i < links.size(); i++){
			cout << links[i].a << " - " << links[i].b << endl;
		}
		cout << endl;
	}
	return 0;
}