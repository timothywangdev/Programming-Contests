#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>
using namespace std;

struct Cor{
	int x;
	int y;
	Cor(){}
	Cor(int x, int y) :x(x), y(y){}
};
int T, x, y;
string s;
Cor hangar;
int N;
vector<int> edge[200];
double sum;

double getDist(Cor a, Cor b){
	return  sqrt((double) ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}
void process(string s){

	istringstream iss(s);
	Cor a, b;
	iss >> a.x >> a.y >> b.x >> b.y;
	/*
	addNode(a);
	addNode(b);
	addEdge(toId[a], toId[b]);
	addEdge(toId[a], toId[b]);
	*/
	sum += (2 * getDist(a, b)) / 20000;
}
int roundToInt(double x){
	if (x + 0.5 >= (int) (x) +1){
		return (int) x + 1;
	}
	else{
		return (int) x;
	}
}
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		if (t>0)cout << endl;
		N = 0;
		sum = 0.0;
		cin >> hangar.x >> hangar.y;
		getline(cin, s);
		while (getline(cin, s)){
			if (s == ""){
				break;
			}
			process(s);
		}
		int hh = sum;
		int mm = roundToInt((sum - (double) hh) * 60);
		if (mm == 60){
			hh++;
			mm = 0;
		}
		if (mm > 10){
			cout << hh << ":" << mm << endl;
		}
		else{
			cout << hh << ":0" << mm << endl;
		}
	}
	return 0;
}