#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<vector<int>> dp;
vector<bool> visited;

void DFS(int node) {
    visited[node] = true;
    dp[node][0] = 0;  // 이 노드가 얼리 어답터가 아닌 경우
    dp[node][1] = 1;  // 이 노드가 얼리 어답터인 경우

    for (int child : tree[node]) {
        if (!visited[child]) {
            DFS(child);
            dp[node][0] += dp[child][1];  // 현재 노드가 얼리 어답터가 아니면 자식 노드는 얼리 어답터여야 함
            dp[node][1] += min(dp[child][0], dp[child][1]);  // 현재 노드가 얼리 어답터면 자식 노드는 얼리 어답터일 수도 있고 아닐 수도 있음
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    tree.resize(N + 1);
    dp.resize(N + 1, vector<int>(2));
    visited.resize(N + 1, false);

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    DFS(1);

    cout << min(dp[1][0], dp[1][1]) << "\n";
    return 0;
}
