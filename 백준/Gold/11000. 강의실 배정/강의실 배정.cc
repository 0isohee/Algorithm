#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<long long, long long>> lectures(N);
    for (int i = 0; i < N; ++i) {
        cin >> lectures[i].first >> lectures[i].second;
    }

    sort(lectures.begin(), lectures.end());
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    pq.push(lectures[0].second);

    for (int i = 1; i < N; ++i) {
        if (lectures[i].first >= pq.top()) {
            pq.pop(); // 방 재사용
        }
        pq.push(lectures[i].second);
    }
    cout << pq.size() << "\n";

    return 0;
}
