#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> passenger(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> passenger[i];
    }
    int cnt;
    cin >> cnt;

    vector<int> sum(N + 1, 0);
    vector<int> dp(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        sum[i] = sum[i - 1] + passenger[i];
    }

    for (int i = cnt; i <= N; i++) {
        dp[i] = max(dp[i - 1], sum[i] - sum[i - cnt]);
    }

    vector<int> dp2(N + 1, 0);
    for (int i = cnt * 2; i <= N; i++) {
        dp2[i] = max(dp2[i - 1], dp[i - cnt] + (sum[i] - sum[i - cnt]));
    }

    int max_passengers = 0;
    for (int i = cnt * 3; i <= N; i++) {
        max_passengers = max(max_passengers, dp2[i - cnt] + (sum[i] - sum[i - cnt]));
    }

    cout << max_passengers << "\n";
    return 0;
}
