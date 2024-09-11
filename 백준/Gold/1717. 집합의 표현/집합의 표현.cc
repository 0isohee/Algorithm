#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n + 1);  // n+1개의 집합이므로, 0부터 n까지.
        rank.resize(n + 1, 0); // 랭크 초기화
        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // 초기에는 각자 자기 자신이 부모
        }
    }

    // find 함수: 경로 압축을 적용하여 트리의 높이를 줄임
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  // 경로 압축
        }
        return parent[u];
    }

    // union 함수: 랭크를 사용하여 두 집합을 합침
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            // 랭크를 기준으로 더 낮은 트리를 더 높은 트리에 붙임
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    // 두 원소가 같은 집합에 속하는지 확인하는 함수
    bool isSameSet(int u, int v) {
        return find(u) == find(v);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int queryType, a, b;
        cin >> queryType >> a >> b;
        if (queryType == 0) {
            uf.unionSets(a, b);
        } else if (queryType == 1) {
            cout << (uf.isSameSet(a, b) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}