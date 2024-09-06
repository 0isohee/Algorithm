#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    int N, K;
    cin >> N >> K;
    vector<int> numbers(N,0);
    for (int i=0; i<N; i++) {
        cin >> numbers[i];
    }
    sort(numbers.rbegin(), numbers.rend());
    
    cout << numbers[K-1] << "\n";
    
    return 0;
}