#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent, size, score;

public:
    UnionFind(int n, vector<int> &points) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        score.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            score[i] = points[i - 1]; // Pontuação inicial dos jogadores
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (size[rootA] < size[rootB]) swap(rootA, rootB);
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
            score[rootA] += score[rootB];
        }
    }

    int getScore(int x) {
        return score[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        vector<int> points(N);
        for (int i = 0; i < N; i++) cin >> points[i];

        UnionFind uf(N, points);
        int rafael = 1, victories = 0;

        for (int i = 0; i < M; i++) {
            int Q, A, B;
            cin >> Q >> A >> B;
            if (Q == 1) {
                uf.unite(A, B);
            } else {
                int rootA = uf.find(A);
                int rootB = uf.find(B);
                if (rootA == rootB) continue; // Empate não conta

                if (rootA == uf.find(rafael) && uf.getScore(rootA) > uf.getScore(rootB)) {
                    victories++;
                } else if (rootB == uf.find(rafael) && uf.getScore(rootB) > uf.getScore(rootA)) {
                    victories++;
                }
            }
        }
        cout << victories << "\n";
    }
    return 0;
}
