#include<iostream>
#include<vector>

using namespace std;


int main(){
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    long long S;
    cin >> N >> S;
    vector<int> number(N, 0);

    for (int i=0; i<N; i++){
        cin >> number[i];
    }
    
    int start = 0;
    int end = 0;
    long long current_sum = 0;
    int min_length = N + 1;

    while (end < N) {
        
        while (current_sum < S && end < N) {
            current_sum += number[end];
            end++;
        }

        while (current_sum >= S && start < N) {
            min_length = min(min_length, end - start);
            current_sum -= number[start];
            start++;
        }
    }

    if (min_length == N + 1) {
        cout << 0 << "\n";
    } else {
        cout << min_length << "\n";
    }

    return 0;
}