#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    
    vector<int> numbers(N,0);
    for (int i=0; i<N; i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    
    cout << numbers[0] << " " << numbers[N-1] << "\n";
    return 0;
}