#include <iostream>
#include <cmath>
using namespace std;

int N;

bool isSosu(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void DFS(int n, int l) {
    if (l == N) {
        cout << n << "\n";
    } else {
        for (int i = 1; i <= 9; i += 2) {  // 홀수만 추가
            int newV = n * 10 + i;
            if (isSosu(newV)) {
                DFS(newV, l + 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
    
    return 0;
}