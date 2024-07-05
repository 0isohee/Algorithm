#include<iostream>
using namespace std;

int dp[51][51][51]; 

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    if (dp[a][b][c] != 0) return dp[a][b][c];

    if (a < b && b < c) {
        dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    } else {
        dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    return dp[a][b][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 50; ++i) {
        for (int j = 0; j <= 50; ++j) {
            for (int k = 0; k <= 50; ++k) {
                dp[i][j][k] = 0;
            }
        }
    }

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }

    return 0;
}
