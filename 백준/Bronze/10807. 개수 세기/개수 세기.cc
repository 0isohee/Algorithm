#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    
    vector<int> numbers(N,0);
    for (int i=0; i<N; i++){
        cin >> numbers[i];
    }
    int ans = 0;
    int v;
    cin >> v;
    for (int i=0; i<N; i++){
        if (numbers[i] == v) {
            ans ++;
        }
    }

    cout << ans << "\n";
    return 0;
}