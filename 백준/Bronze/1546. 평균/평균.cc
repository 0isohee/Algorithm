#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> scores(n); // 벡터 크기를 n으로 초기화
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    double max_score = -1e9; // 큰 음수로 초기화, double 타입 사용
    for (int i = 0; i < n; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }

    for (int i = 0; i < n; i++) {
        scores[i] = scores[i] / max_score * 100; // max_score로 변경
    }

    double sumv = 0;
    for (int i = 0; i < n; i++) {
        sumv += scores[i];
    }

    cout << sumv / n << endl;

    return 0;
}
