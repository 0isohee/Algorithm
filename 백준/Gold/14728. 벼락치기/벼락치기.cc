#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N, T;
    cin >> N >> T;

    vector<pair<int, int>> subjects(N);

    for (int i=0; i<N; i++){
        int k, s;
        cin >> k >> s;
        subjects[i] = {s,k};
    }
    sort(subjects.begin(), subjects.end());

    vector<int> dp(T+1, 0);

    for (int i=N-1; i>-1; i--){
        int score = subjects[i].first;
        int time = subjects[i].second;

        for (int t=T; t>=time; t--){
            dp[t] = max(dp[t-time]+score, dp[t]);
        }
    }
    cout << dp[T] << "\n";
    return 0;
}