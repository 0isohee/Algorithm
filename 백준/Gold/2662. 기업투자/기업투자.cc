#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> companyList(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        int money;
        cin >> money;
        for (int j = 1; j <= m; j++) {
            cin >> companyList[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> invest(n + 1, vector<int>(m + 1, 0));

    for (int company = 1; company <= m; company++) {
        for (int money = 1; money <= n; money++) {
            for (int invest_money = 0; invest_money <= money; invest_money++) {
                int current_profit = dp[money - invest_money][company - 1] + companyList[invest_money][company];
                if (current_profit > dp[money][company]) {
                    dp[money][company] = current_profit;
                    invest[money][company] = invest_money;
                }
            }
        }
    }

    cout << dp[n][m] << "\n";

    vector<int> allocation(m + 1, 0);
    int remaining_money = n;
    for (int company = m; company >= 1; company--) {
        allocation[company] = invest[remaining_money][company];
        remaining_money -= allocation[company];
    }

    for (int company = 1; company <= m; company++) {
        cout << allocation[company] << " ";
    }
    cout << "\n";

    return 0;
}
