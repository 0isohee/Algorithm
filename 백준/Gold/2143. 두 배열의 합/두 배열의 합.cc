#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    long long T;
    int n, m;
    cin >> T >> n;

    vector<long long> A(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    cin >> m;
    vector<long long> B(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }

    // A의 부분 배열 합을 저장하는 해시맵
    unordered_map<long long, int> sum_A;
    for (int i = 1; i <= n; i++) {
        long long sum = 0;
        for (int j = i; j <= n; j++) {
            sum += A[j];
            sum_A[sum]++;
        }
    }

    // B의 부분 배열 합을 확인하면서 T에서 뺀 값이 sum_A에 있는지 확인
    long long cnt = 0;
    for (int i = 1; i <= m; i++) {
        long long sum = 0;
        for (int j = i; j <= m; j++) {
            sum += B[j];
            if (sum_A.find(T - sum) != sum_A.end()) {
                cnt += sum_A[T - sum];
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}