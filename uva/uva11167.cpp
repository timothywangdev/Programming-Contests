#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
#include <fstream>
#define INFINITY 2147483647
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
typedef int LL;

int N, M, v, a, b,totalInterval;
struct Inter{
	int start;
	int end;
	Inter(int start, int end) :start(start), end(end){}
	Inter(){}
};
map<Inter, int> toId;
map<int, int> toPos;
vector<vector<Inter> > output;
struct Edge {
	int from, to, cap, flow, index;
	Edge(int from, int to, int cap, int flow, int index) :
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

bool operator<(const Inter &a, const Inter &b){
	if (a.start < b.start){
		return true;
	}
	else if (a.start == b.start){
		return a.end < b.end;
	}
	return false;
}
struct PushRelabel {
	int N;
	vector<vector<Edge> > G;
	vector<LL> excess;
	vector<int> dist, active, count;
	queue<int> Q;

	PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2 * N) {}

	void AddEdge(int from, int to, int cap) {
		G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
		if (from == to) G[from].back().index++;
		G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
	}

	void Enqueue(int v) {
		if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); }
	}

	void Push(Edge &e) {
		int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
		if (dist[e.from] <= dist[e.to] || amt == 0) return;
		e.flow += amt;
		G[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		Enqueue(e.to);
	}

	void Gap(int k) {
		for (int v = 0; v < N; v++) {
			if (dist[v] < k) continue;
			count[dist[v]]--;
			dist[v] = max(dist[v], N + 1);
			count[dist[v]]++;
			Enqueue(v);
		}
	}

	void Relabel(int v) {
		count[dist[v]]--;
		dist[v] = 2 * N;
		for (int i = 0; i < G[v].size(); i++)
		if (G[v][i].cap - G[v][i].flow > 0)
			dist[v] = min(dist[v], dist[G[v][i].to] + 1);
		count[dist[v]]++;
		Enqueue(v);
	}

	void Discharge(int v) {
		for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
		if (excess[v] > 0) {
			if (count[dist[v]] == 1)
				Gap(dist[v]);
			else
				Relabel(v);
		}
	}

	LL GetMaxFlow(int s, int t) {
		count[0] = N - 1;
		count[N] = 1;
		dist[s] = N;
		active[s] = active[t] = true;
		for (int i = 0; i < G[s].size(); i++) {
			excess[s] += G[s][i].cap;
			Push(G[s][i]);
		}

		while (!Q.empty()) {
			int v = Q.front();
			Q.pop();
			active[v] = false;
			Discharge(v);
		}

		LL totflow = 0;
		for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
		return totflow;
	}
};
struct Interval{
	int start;
	int end;
	vector<int> assignment;
	Interval(int start, int end, int assign) :start(start), end(end){
		assignment.push_back(assign);
	}
	Interval(int start, int end, vector<int> assign) :start(start), end(end), assignment(assign){}
};
vector<Interval> intervals;
vector<int> monkey_cap;


void addInterval(Interval interval){
	queue<Interval> need_process;
	vector<Interval> tmp;
	need_process.push(interval);
	if (intervals.size() == 0){
		intervals.push_back(interval);
		return;
	}
	while (need_process.size()){
		Interval current = need_process.front();
		need_process.pop();
		bool conflict = false;
		for (int j = 0; j < intervals.size(); j++){
			Interval target = intervals[j];

			//  |----|
			//     |----|
			if (target.start < current.end&&current.end < target.end&&current.start<target.start){
				need_process.push(Interval(current.start, target.start, current.assignment));
				vector<int> t = target.assignment;
				t.push_back(current.assignment[0]);
				tmp.push_back(Interval(target.start, current.end, t));
				intervals[j].start = current.end;
				conflict = true;
			}
			//    |----|
			//  |----|
			else if (target.start < current.start&&current.start < target.end&&current.end>target.end){
				need_process.push(Interval(target.end, current.end, current.assignment));
				vector<int> t = target.assignment;
				t.push_back(current.assignment[0]);
				tmp.push_back(Interval(current.start, target.end, t));
				intervals[j].end = current.start;
				conflict = true;
			}
			//    |----|
			//  |---------|
			else if (target.start < current.start&&current.start < target.end&&target.start < current.end&&current.end < target.end){
				vector<int> t = target.assignment;
				t.push_back(current.assignment[0]);
				tmp.push_back(Interval(current.start, current.end, t));
				tmp.push_back(Interval(current.end, target.end, target.assignment));
				intervals[j].end = current.start;
				conflict = true;
			}

			//  |---------|
			//    |----|		
			else if (current.start < target.start&&target.start <current.end&&current.start < target.end&&target.end < current.end){
				intervals[j].assignment.push_back(current.assignment[0]);
				need_process.push(Interval(current.start, target.start, current.assignment));
				need_process.push(Interval(target.end, current.end,current.assignment));
				conflict = true;
			}

			//  |----|
			//  |-------|
			else if (current.start == target.start&&current.end<target.end){
				vector<int> t = target.assignment;
				t.push_back(current.assignment[0]);
				tmp.push_back(Interval(current.start, current.end, t));
				intervals[j].start = current.end;
				conflict = true;
			}

			//     |----|
			//  |-------|
			else if (current.end == target.end&&current.start>target.start){
				vector<int> t = target.assignment;
				t.push_back(current.assignment[0]);
				tmp.push_back(Interval(current.start, current.end, t));
				intervals[j].end = current.start;
				conflict = true;
			}

			//  |-------|
			//  |---|
			else if (current.start == target.start&&current.end>target.end){
				intervals[j].assignment.push_back(current.assignment[0]);
				need_process.push(Interval(target.end, current.end, current.assignment));
				conflict = true;
			}

			//  |-------|
			//      |---|
			else if (current.end == target.end&&current.start<target.start){
				intervals[j].assignment.push_back(current.assignment[0]);
				need_process.push(Interval(current.start, target.start, current.assignment));
				conflict = true;
			}

			//  |---|
			//  |---|
			else if (current.end == target.end&&current.start == target.start){
				intervals[j].assignment.push_back(current.assignment[0]);
				conflict = true;
			}
			else if(!(current.end<=target.start||current.start>=target.end)){
				cout << "should not happen"<<endl;
			}
			if (conflict)break;
		}
		if (!conflict){
			intervals.push_back(current);
		}
		else{
			for (int k = 0; k < tmp.size(); k++){
				intervals.push_back(tmp[k]);
			}
			tmp.clear();
		}
	}
}

void addNode(int pos,Interval i){
	Inter ii(i.start, i.end);
	if (toId.find(ii) == toId.end()){
		toId[ii] = totalInterval;
		toPos[totalInterval] = pos;
		totalInterval++;
	}
}
struct output_struct{
	vector<int> v;
	int last;
	int start;
	int end;
	output_struct(int start, int end) :start(start), end(end){
		v = vector<int>(end-start, M);
		last=0;
	}
	vector<Inter> getInterval(int flow){
		vector<Inter> rv;
		int l = last;
		int index = last;
		for (int i = 0; flow > 0; i++){
			v[index]--;
			flow--;
			if (flow == 0){
				rv.push_back(Inter(start + l, start + index+1));
				break;
			}
			index++;
			if (index == v.size()){
				rv.push_back(Inter(start + l, start + v.size()));
				index = 0;
				l = 0;
			}
		}
		last = (index + 1) % v.size();
		return rv;
	}
};
vector<output_struct> outputs;
vector<Inter> getInterval(int flow, int to){
	int pos = toPos[to];
	return outputs[pos].getInterval(flow);
}



void output_init(){
	outputs.clear();
	for (int i = 0; i < intervals.size(); i++){
		outputs.push_back(output_struct(intervals[i].start,intervals[i].end));
	}
}
int counter = 0;

int main(){
	redirect();
	while (cin >> N){
		if (!N)break;
		counter++;
		cin >> M;
		toId.clear();
		intervals.clear();
		toPos.clear();
		output = vector<vector<Inter> >(N, vector<Inter>());
		monkey_cap = vector<int>(N, 0);
		totalInterval = 0;
		for (int i = 0; i < N; i++){
			cin >> monkey_cap[i] >> a >> b;
			addInterval(Interval(a, b, i));
		}
		for (int i = 0; i < intervals.size(); i++){
			addNode(i,intervals[i]);
		}
		//   totalInterval     N   Source 1  Sink 1
		// |-----------------|---|---------|-------|
		PushRelabel mf(totalInterval + N + 2);
		// intervals -> sink
		for (map<Inter, int>::iterator it = toId.begin(); it != toId.end(); it++){
			int id = it->second;
			Inter inter = it->first;
			int cap = (inter.end - inter.start)*M;
			mf.AddEdge(id, totalInterval + N + 1, cap);
			//cout << "add edge: " << id << " -> " << totalInterval + N + 1 << " cap: " << cap << endl;
		}
		// monkeys -> intervals
		for (int i = 0; i < intervals.size(); i++){
			int id = toId[Inter(intervals[i].start, intervals[i].end)];
			int cap = (intervals[i].end - intervals[i].start);
			for (int j = 0; j < intervals[i].assignment.size(); j++){
				mf.AddEdge(intervals[i].assignment[j] + totalInterval, id, cap);
				//cout << "add edge: " << intervals[i].assignment[j] + totalInterval << " -> " << id << " cap: " << cap << endl;
			}
		}
		// source -> monkeys
		for (int i = 0; i < N; i++){
			mf.AddEdge(totalInterval + N, i+totalInterval, monkey_cap[i]);
			//cout << "add edge: " << totalInterval + N << " -> " << i + totalInterval << " cap: " << monkey_cap[i] << endl;
		}
		int totalExcess = 0;
		for (int i = 0; i < N; i++){
			totalExcess+=monkey_cap[i];
		}
		mf.excess[totalInterval + N] = totalExcess;
		int maxflow = mf.GetMaxFlow(totalInterval + N, totalInterval + N + 1);
		cout << "Case " << counter << ": ";
		if (maxflow != totalExcess){
			cout << "No" << endl;
		}
		else{
			output_init();
			cout <<  "Yes" << endl;
			for (int i = 0; i < N; i++){
				//cout << i << endl;
				//if (i == 7){
				//	cout << "fuck" << endl;
				//}
				for (int j = 0; j < mf.G[i + totalInterval].size(); j++){
					Edge e = mf.G[i + totalInterval][j];
					// Non-residual edge
					if (e.cap>0&&e.flow>0){
						vector<Inter> rv = getInterval(e.flow, e.to);
						for (int p = 0; p < rv.size(); p++){
							output[i].push_back(rv[p]);
						}
						
					}
				}
			}
			for (int i = 0; i < N; i++){
				
				sort(output[i].begin(), output[i].end());
				vector<Inter> tmp;
				int last = 0;
				for (int j = 1; j <= output[i].size(); j++){
					if (j == output[i].size()||output[i][j].start != output[i][j - 1].end){
						tmp.push_back(Inter(output[i][last].start, output[i][j - 1].end));
						last = j;
					}
				}
				cout << tmp.size();
				for (int j = 0; j < tmp.size(); j++){
					cout << " (" << tmp[j].start << "," << tmp[j].end << ")";
				}
				cout << endl;
			}
		}
	}
	return 0;
}