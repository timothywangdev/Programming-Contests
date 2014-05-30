#include <iostream>
#include <string.h>
#include <vector>
#include <iomanip>
#define INF 842150450
using namespace std;

int a,b,dist[101][101];
bool seen[101];
vector<int> pages;
void add(int k){
	if (!seen[k]){
		seen[k] = true;
		pages.push_back(k);
	}
}
int counter = 0;
int main(){
	while (cin >> a >> b){
		if (!a&&!b){
			break;
		}
		cout << "Case " << counter + 1 << ": average length between pages = ";
		counter++;
		memset(dist, 50, sizeof(dist));
		memset(seen, false, sizeof(seen));
		pages.clear();
		dist[a][b] = 1;
		add(a);
		add(b);
		while (cin >> a >> b){
			if (!a&&!b){
				break;
			}
			dist[a][b]=1;
			add(a);
			add(b);
		}
		for (int i = 0; i < pages.size(); i++){
			for (int j = 0; j < pages.size(); j++){
				for (int k = 0; k < pages.size(); k++){
					if (dist[pages[j]][pages[k]]>dist[pages[j]][pages[i]] + dist[pages[i]][pages[k]]){
						dist[pages[j]][pages[k]]=dist[pages[j]][pages[i]] + dist[pages[i]][pages[k]];
					}
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < pages.size(); i++){
			for (int j = 0; j < pages.size(); j++){
				if (i != j){
					sum += dist[pages[i]][pages[j]];
				}
			}
		}
		cout << fixed << setprecision(3) << (double)sum / (double)(pages.size()*(pages.size() - 1)) << " clicks"<<endl;
	}
	return 0;
}