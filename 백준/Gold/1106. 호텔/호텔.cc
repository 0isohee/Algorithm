#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c, n;
    cin >> c >> n;
    vector<pair<int, int>> vt(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vt[i] = {a, b};
    }

    for (int i = 1; i <= 100000; i++) {
        for (int j = 0; j < n; j++) {
            if (i % vt[j].first == 0) {
                dp[i] = max(dp[i], (i / vt[j].first) * vt[j].second);
            }
            if (i - vt[j].first >= 0) {
                dp[i] = max(dp[i], dp[i - vt[j].first] + vt[j].second);
            }
        }
        if (c <= dp[i]) {
            cout << i;
            return 0;
        }
    }
    return 0;
}