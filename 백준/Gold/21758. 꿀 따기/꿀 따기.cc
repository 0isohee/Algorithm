#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> wall(n+1,0);
    vector<int> wall_sum(n + 1, 0);

    cin >> wall[1];
    wall_sum[1] = wall[1];

    for (int i = 2; i <= n; i++) {
        cin >> wall[i]; 
        wall_sum[i] = wall_sum[i - 1] + wall[i];
    }

    int max_honey = 0;

    for (int i = 2; i < n; i++) {
        int honey = wall_sum[n] - wall[1] - wall[i] + wall_sum[n] - wall_sum[i];
        max_honey = max(max_honey, honey);
    }

    for (int i = 2; i < n; i++) {
        int honey = wall_sum[i] - wall[1] + wall_sum[n - 1] - wall_sum[i - 1];
        max_honey = max(max_honey, honey);
    }

    for (int i = 2; i < n; i++) {
        int honey = wall_sum[i-1] + wall_sum[n-1] - wall[i];
        max_honey = max(max_honey, honey);
    }

    cout << max_honey << "\n";
    return 0;
}
