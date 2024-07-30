#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> items;

    for (int i = 0; i < n; i++) {
        int v, c, k;
        cin >> v >> c >> k;
        for (int j = 1; k > 0; j <<= 1) {
            int num = min(j, k);
            items.push_back({v * num, c * num});
            k -= num;
        }
    }

    vector<int> dp(m + 1, 0);

    for (auto& item : items) {
        int v = item.first;
        int c = item.second;
        for (int j = m; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + c);
        }
    }

    cout << dp[m] << "\n";
    return 0;
}