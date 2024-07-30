#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> subjects(k);

    for (int i = 0; i < k; i++) {
        int l, t;
        cin >> l >> t;
        subjects[i] = {l, t};
    }
    sort(subjects.begin(), subjects.end());

    vector<int> dp(n + 1, 0);

    for (int i = 0; i < k; i++) {
        int score = subjects[i].first;
        int time = subjects[i].second;
        for (int j = n; j >= time; j--) {
            dp[j] = max(dp[j], dp[j - time] + score);
        }
    }
    
    int maxv = 0;
    for (int i = 1; i <= n; i++) {
        maxv = max(maxv, dp[i]);
    }
    cout << maxv << "\n";
    return 0;
}