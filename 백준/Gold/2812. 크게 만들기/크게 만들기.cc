#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    string number;
    cin >> number;

    stack<char> s;
    int to_remove = K;

    for (char digit : number) {
        while (!s.empty() && s.top() < digit && to_remove > 0) {
            s.pop();
            to_remove--;
        }
        s.push(digit);
    }

    // 아직 제거할 숫자가 남아있다면 스택에서 제거
    while (to_remove > 0) {
        s.pop();
        to_remove--;
    }

    // 스택에서 최종 숫자를 구성
    string result(s.size(), '0');
    int index = s.size() - 1;
    while (!s.empty()) {
        result[index--] = s.top();
        s.pop();
    }

    cout << result << "\n";
    return 0;
}
