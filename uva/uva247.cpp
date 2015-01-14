#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
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
int N, M,low[25],num[25];
bool m[25][25],visited[25];
map<string, int> toID;
map<int, string> toName;
stack<int> st;
string str1, str2;
int counter = 0;
int ID_counter;
int tarjan_counter;
void output(int target){
	bool first = true;
	while (true){
		int k = st.top();
		visited[k] = false;
		st.pop();
		if (!first){
			cout << ", ";
		}
		else{
			first = false;
		}
		cout << toName[k];
		if (k == target){
			break;
		}
	}
	cout << endl;
}
void tarjanSCC(int index){
	low[index] = num[index] = tarjan_counter++;
	visited[index] = true;
	st.push(index);
	for (int i = 0; i<N; i++){
		if (m[index][i]){
			if (num[i] == -1){
				tarjanSCC(i); 
				low[index] = min(low[index], low[i]);
			}
			else if(visited[i]){
				low[index] = min(low[index], num[i]);
			}
		}
	}
	if (low[index] == num[index]){
		output(index);
	}
}
void addEdge(string a, string b){
	map<string, int>::iterator it = toID.find(a);
	if (it == toID.end()){
		toID[a] = ID_counter;
		toName[ID_counter] = a;
		ID_counter++;
	}
	it = toID.find(b);
	if (it == toID.end()){
		toID[b] = ID_counter;
		toName[ID_counter] = b;
		ID_counter++;
	}
	m[toID[a]][toID[b]] = true;
}
int main(){
	redirect();
	while (cin >> N >> M){
		if (!N&&!M){
			break;
		}
		if (counter > 0){
			cout << endl;
		}
		
		counter++;
		cout << "Calling circles for data set " << counter << ":" << endl;
		memset(m, false, sizeof(m));
		memset(visited, false, sizeof(visited));
		toID.clear();
		toName.clear();
		ID_counter = 0;
		tarjan_counter = 0;
		memset(num, -1, sizeof(num));
		memset(low, 0, sizeof(low));
		for (int i = 0; i < M; i++){
			cin >> str1 >> str2;
			addEdge(str1, str2);
		}
		for (int i = 0; i < N; i++){
			if (num[i] == -1){
				while (st.size()){
					st.pop();
				}
				tarjanSCC(i);
			}
		}
	}
	return 0;
}