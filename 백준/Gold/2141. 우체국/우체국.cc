#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<long long, long long>> peoples(N);
    long long total_people = 0;

    for (int i = 0; i < N; i++) {
        long long x, a;
        cin >> x >> a;
        total_people += a;
        peoples[i] = {x, a};
    }
    sort(peoples.begin(), peoples.end());

    long long half_people = (total_people + 1) / 2;
    long long cumulative_people = 0;
    int min_idx = 0;

    for (int i = 0; i < N; i++) {
        cumulative_people += peoples[i].second;
        if (cumulative_people >= half_people) {
            min_idx = peoples[i].first;
            break;
        }
    }
    
    cout << min_idx << "\n";
    return 0;
}
