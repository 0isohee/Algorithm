#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> weights(N);

    for (int i = 0; i < N; ++i){
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());

    int sum = 0;
    for (int i = 0; i < N; ++i){
        if (weights[i] > sum + 1){
            break;
        }
        sum += weights[i];
    }

    cout << sum + 1 << "\n";
    return 0;
}
