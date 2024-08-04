#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
vector<int> parent;

void DFS(int node) {
    visited[node] = true;
    for (int child : tree[node]) {
        if (!visited[child]) {
            parent[child] = node;
            DFS(child);
        }
    }
}

int main() {
    int N;
    cin >> N;

    tree.resize(N + 1);
    visited.resize(N + 1, false);
    parent.resize(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int left, right;
        cin >> left >> right;
        tree[left].push_back(right);
        tree[right].push_back(left);
    }

    DFS(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}
