#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    
    vector<int> coin(N,0);
    for (int i=0; i<N; i++){
        cin >> coin[i];
    }
    sort(coin.rbegin(), coin.rend());

    int cnt = 0;
    for (int i=0; i<N; i++){
        if (coin[i] > K) continue;
        if (K == 0) break;
        cnt += (int) (K / coin[i]);
        K -= (coin[i] * (int) (K / coin[i]));
    }  
    cout << cnt << "\n";
    return 0;
}