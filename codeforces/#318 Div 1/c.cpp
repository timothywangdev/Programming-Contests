#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
vector<int> G[MAXN];
bool del[MAXN];
int leg[MAXN];

void dfs(int v, int p = 0) {
    del[v] = true;
    for (int ch : G[v]) {
        if (ch == p) continue;
        if (G[ch].size() <= 2) dfs(ch, v);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) if (G[i].size() == 1) dfs(i);
    for (int i = 1; i <= N; i++) {
        for (int ch : G[i]) if (del[ch]) leg[i]++;
    }
    for (int i = 1; i <= N; i++) {
        if (del[i]) continue;
        int cnt = 0;
        for (int ch : G[i]) if (!del[ch]) {
            if (G[ch].size() - min(2, leg[ch]) > 1) cnt++;
        }
        if (cnt > 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
