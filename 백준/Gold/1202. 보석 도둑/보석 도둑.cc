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

    int N, K;
    cin >> N >> K;

    vector<pair<long long, long long>> jewels(N);
    for (int i = 0; i < N; i++) {
        int m, v;
        cin >> m >> v;
        jewels[i] = {m, v};
    }

    vector<long long> bag(K);
    for (int i = 0; i < K; i++) {
        cin >> bag[i];
    }
    sort(bag.begin(), bag.end());
    sort(jewels.begin(), jewels.end());

    priority_queue<long long> pq;
    long long max_cost = 0;
    int j = 0;
    for (int i = 0; i < K; i++) {
        while (j < N && jewels[j].first <= bag[i]) {
            pq.push(jewels[j].second);
            j++;
        }
        if (!pq.empty()) {
            max_cost += pq.top();
            pq.pop();
        }
    }

    cout << max_cost << "\n";
    return 0;
}