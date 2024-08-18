#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> times(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    sort(times.begin(), times.end());

    int total_time = 0;
    int accumulated_time = 0;

    for (int i = 0; i < n; i++) {
        accumulated_time += times[i];
        total_time += accumulated_time;
    }

    cout << total_time << "\n";
    return 0;
}