#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> coins(n);
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }
        int M;
        cin >> M;

        vector<int> dp(M + 1, 0);
        dp[0] = 1; 
        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= M; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        cout << dp[M] << "\n";
    }
    return 0;
}