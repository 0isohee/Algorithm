#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<long long, long long>> trails(N);

    for (int i = 0; i < N; i++) {
        long long h, o;
        cin >> h >> o;
        if (h > o) swap(h, o);
        trails[i] = {h, o};
    }
    sort(trails.begin(), trails.end(), [](pair<long long, long long>& a, pair<long long, long long>& b) {
        return a.second < b.second;  
    });

    long long d;
    cin >> d;

    int ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (const auto& trail : trails) {
        long long start = trail.first;
        long long end = trail.second;

        if (end - start > d) continue; 

        pq.push(start);
        while (!pq.empty() && pq.top() < end - d) {
            pq.pop();
        }
        ans = max(ans, static_cast<int>(pq.size()));
    }

    cout << ans << "\n";
    return 0;
}
