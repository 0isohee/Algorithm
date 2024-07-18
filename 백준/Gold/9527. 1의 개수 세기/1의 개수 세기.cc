#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<utility>

using namespace std;

long long count_ones(long long n) {
    if (n < 0) return 0;
    long long count = 0;
    long long x = 1;
    while (x <= n) {
        count += (n + 1) / (x << 1) * x + max(0LL, (n + 1) % (x << 1) - x);
        x <<= 1;
    }
    return count;
}

long long sum_ones_in_range(long long A, long long B) {
    return count_ones(B) - count_ones(A - 1);
}

int main() {

    long long A, B;
    cin >> A >> B;

    cout << sum_ones_in_range(A, B) << "\n";
    return 0;
}