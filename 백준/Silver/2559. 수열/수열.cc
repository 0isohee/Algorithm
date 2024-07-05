#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> temperatures(N);
    for (int i = 0; i < N; i++) {
        cin >> temperatures[i];
    }

    int current_sum = 0;
    for (int i = 0; i < K; i++) {
        current_sum += temperatures[i];
    }

    int max_sum = current_sum;
    for (int i = K; i < N; i++) {
        current_sum = current_sum - temperatures[i - K] + temperatures[i];
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";
    return 0;
}