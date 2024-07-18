#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<utility>

using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    int origin_N = N;

    while (true){

        int cnt = 0;
        for (int b=0; b<32; b++){
            if ((origin_N) & (1 << b)) {
                cnt++;
            }
        }

        if (cnt <= K) break;
        origin_N ++;
    }
    cout << origin_N - N << "\n";
    return 0;
}