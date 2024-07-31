#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main() {
    for (int t = 0; t < 3; t++) {
        int n;
        cin >> n;

        vector<pair<int, int>> coins(n);
        int total = 0;

        for (int i = 0; i < n; i++) {
            int price, cnt;
            cin >> price >> cnt;
            total += (price * cnt);
            coins[i] = {price, cnt};
        }

        if (total % 2 != 0) {
            cout << 0 << "\n";
            continue;
        }

        int half = total / 2;
        vector<int> dp(half + 1, 0);
        dp[0] = 1;

        for (const auto& coin : coins) {
            int price = coin.first;
            int cnt = coin.second;

            for (int j = half; j >= price; j--) {
                for (int k = 1; k <= cnt && k * price <= j; k++) {
                    dp[j] |= dp[j - k * price];
                }
            }
        }

        if (dp[half]) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}