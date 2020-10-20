class UnionFind {
    private:
        vector<int> p, rank;
    public:
        UnionFind(int n) {
            p.assign(n, 0);
            rank.assign(n, 0);
            for(int i = 0; i< n; i++) {
                p[i] = i;
            }
        }
        // O(alpha(n)) approx O(1)
        // alpha(n):inverse Ackermann function
        int findSet(int i) {
          return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }
        // O(alpha(n)) approx O(1)
        // alpha(n):inverse Ackermann function
        bool isSameSet(int i, int j) {
          return findSet(i) == findSet(j);
        }
        // O(alpha(n)) approx O(1)
        // alpha(n):inverse Ackermann function
        void unionSet(int i, int j) {
          if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
              p[y]=x;
            } else {
              p[x] = y;
              if (rank[x] == rank[y]) rank[y]++;
            }
          }
        }
};
