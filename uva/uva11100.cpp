#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node{
public:
	vector<int> content;
	Node(){}
	Node(int k){
		content.push_back(k);
	}
	int smallest() const{
		return content[0];
	}
	int largest() const{
		return content[content.size() - 1];
	}
};
vector<Node> current, ne;
vector<bool> used;
int N, tmp;
int v[10000];
vector<int> rv[10000];
bool mySort(const Node &a, const Node &b){
	if (a.smallest() < b.smallest()){
		return true;
	}
	else if (a.smallest() == b.smallest()){
		return a.content.size() < b.content.size();
	}
	return false;
}
Node mergeNode(const Node &a, const Node &b){
	Node c;
	c.content = a.content;
	for (int i = 0; i < b.content.size(); i++){
		c.content.push_back(b.content[i]);
	}
	return c;
}
int main(){
	bool first = true;
	while (cin >> N){
		if (!N){
			break;
		}
		if (first){
			first = false;
		}
		else{
			cout << endl;
		}
		current.clear();
		for (int i = 0; i < N; i++){
			cin >> v[i];
		}
		sort(v, v + N);
		int last = -1, maximum = 0, currentLength = 0;
		for (int i = 0; i < N; i++){
			if (v[i] == last){
				currentLength++;
			}
			else{
				last = v[i];
				currentLength = 1;
			}
			maximum = max(maximum, currentLength);
		}
		cout << maximum << endl;
		for (int i = 0; i < maximum; i++){
			rv[i].clear();
		}
		int curr = 0;
		for (int i = 0; i < N; i++){
			rv[curr].push_back(v[i]);
			curr = (curr + 1)%maximum;
		}
		for (int i = 0; i < maximum; i++){
			for (int j = 0; j < rv[i].size(); j++){
				if (j != 0){
					cout << " ";
				}
				cout << rv[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}