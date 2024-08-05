#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main() {
    while (true){
        int n;
        double m;
        cin >> n >> m;

        if (n == 0 && m == 0.00) {
            break;
        }

        int M = static_cast<int>(m * 100);

        vector<pair<int, int>> candy(n);

        for (int i=0; i<n; i++){
            int c;
            double p;
            cin >> c >> p;
            int price = static_cast<int>(p * 100 + 0.5);
            candy[i] = {c, price};
        }

        vector<int> dp(M+1, 0);

        for (int i=0; i<n; i++){
            int c = candy[i].first;
            int p = candy[i].second;
            for (int j=p; j<=M; j++){
                dp[j] = max(dp[j], dp[j-p] + c);
            }
        }
        cout << dp[M] << "\n";
    }
    return 0;
}