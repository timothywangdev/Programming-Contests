#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<vector<int> > edge;
vector<int> dia, tt,tttt, ri, le;
bool exist[2500][2500];
int degree[2500], dd[2500];
int rv[5];
int ddd[2];
bool visited[2500], existNode[2500];
int T, N, tmp[2500], a, b, furthest, iii;
void findFurthest(int u, int dist){
	visited[u] = true;
	tt.push_back(u);
	for (int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i];
		if (!visited[v]&&exist[u][v]){
			findFurthest(v, dist + 1);
		}
	}
	if (furthest < dist){
		furthest = dist;
		tttt = tt;
		iii = u;
	}
	visited[u] = false;
	tt.pop_back();
}
int getDia(int startingPoint,int &d,int &center,bool update){
	furthest = -1;
	iii = -1;
	findFurthest(startingPoint, 0);
	furthest = -1;
	findFurthest(iii, 0);
	center = tttt[furthest / 2];
	if (update){
		dia = tttt;
	}
	d = furthest / 2+(furthest%2==1);
	return furthest;
}
void dfs(int u, vector<int> &vi){
	visited[u] = true;
	vi.push_back(u);
	for (int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i];
		if (!visited[v] && exist[u][v]){
			dfs(v, vi);
		}
	}
	visited[u] = false;
}
void deleteLeaf(int u){
	for (int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i];
		if (exist[u][v] && dd[v] >= 1){
			dd[v]--;
		}
	}
}

int findCenter(vector<int> vs,int &rr){
	int counter = vs.size();
	vector<int> v;
	int distance = 0;
	int nn;
	while (counter > 2){
		distance++;
		nn = 0;
		for (int i = 0; i < vs.size(); i++){
			if (dd[vs[i]] == 1){
				dd[vs[i]] = -1;
				counter--;
				tmp[nn] = vs[i];
				nn++;
				//v.push_back(vs[i]);
				//deleteLeaf(vs[i]);
			}
		}
		for (int i = 0; i < nn; i++){
			deleteLeaf(tmp[i]);
		}
		//v.clear();
	}
	rr = distance+(counter==2);
	for (int i = 0; i < vs.size(); i++){
		if (dd[vs[i]] >= 0){
			return vs[i];
		}
	}
}
int getMaximum(int u){
	int maximum = -1;
	visited[u] = true;
	for (int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i];
		if (exist[u][v] && !visited[v]){
			maximum = max(maximum, getMaximum(v));
		}
	}
	visited[u] = false;
	return maximum + 1;
}
void output(){
	printf("%d\n", rv[0]);
	printf("%d %d\n", rv[1],rv[2]);
	printf("%d %d\n", rv[3],rv[4]);
}
void updateOutput(int d, int oa, int ob, int na, int nb){
	rv[0] = d;
	rv[1] = min(oa,ob);
	rv[2] = max(oa,ob);
	rv[3] = min(na, nb);
	rv[4] = max(na, nb);
}
int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		int minimum = 2147483647;
		dia.clear();
		scanf("%d", &N);
		edge = vector<vector<int> >(N, vector<int>());
		memset(visited, false, N*sizeof(bool));
		memset(exist, false, sizeof(exist));
		memset(degree, 0, N*sizeof(int));

		for (int i = 0; i < N - 1; i++){
			scanf("%d %d", &a, &b);
			a--;
			b--;
			exist[a][b] = exist[b][a] = true;
			edge[a].push_back(b);
			edge[b].push_back(a);
			degree[a]++;
			degree[b]++;
		}
		getDia(0,ddd[0],a,true);
		int rc, lc,d1,d2,k;
		for (int i = 0; i < dia.size() - 1; i++){
			exist[dia[i]][dia[i + 1]] = exist[dia[i + 1]][dia[i]] = false;
			//ri.clear();
			//le.clear();
			//memset(visited, false, N*sizeof(bool));
			//dfs(dia[i], ri);
			//memset(visited, false, N*sizeof(bool));
			//dfs(dia[i + 1], le);
			//memcpy(dd, degree, N*sizeof(int));
			/*
			for (int j = 0; j < ri.size(); j++){
				dd[ri[j]] = degree[ri[j]];
			}
			dd[dia[i]]--;
			dd[dia[i + 1]]--;
			rc = findCenter(ri,ddd[0]);
			*/
			//memcpy(dd, degree, N*sizeof(int));
			/*
			for (int j = 0; j < le.size(); j++){
				dd[le[j]] = degree[le[j]];
			}
			dd[dia[i]]--;
			dd[dia[i + 1]]--;
			lc = findCenter(le,ddd[1]);
			*/
			//memset(visited, false, N*sizeof(bool));
			
			d1 = getDia(dia[i], ddd[0], rc,false);
			d2 = getDia(dia[i + 1], ddd[1], lc,false);
			k = ddd[0] + ddd[1] + 1;
			k = max(k, max(d1, d2));
			if (k < minimum){
				minimum = k;
				updateOutput(k, dia[i] + 1, dia[i + 1] + 1, rc + 1, lc + 1);
			}
			exist[dia[i]][dia[i + 1]] = exist[dia[i + 1]][dia[i]] = true;
		}
		output();
	}
	return 0;
}