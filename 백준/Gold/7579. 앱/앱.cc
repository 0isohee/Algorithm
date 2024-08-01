#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M;
    vector<long long> memory(N,0);
    vector<long long> cost(N,0);

    for (int i=0; i<N; i++){
        cin >> memory[i];
    }
    for (int i=0; i<N; i++){
        cin >> cost[i];
    }

    int max_cost = 100 * N;  
    vector<long long> dp(max_cost + 1, 0); 

    for (int i=0; i<N; i++){
        for (int j=max_cost; j>=cost[i]; j--){
            dp[j] = max(dp[j], dp[j-cost[i]] + memory[i]);
        }
    }

    for (int i=0; i<=max_cost; i++){
        if (dp[i] >= M){
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
