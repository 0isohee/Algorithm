#include<iostream>
#include<stack>
using namespace std;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    stack<int> s;
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        int m;
        cin >> m;
        if (m == 1) {
            int x;
            cin >> x;
            s.push(x);
        } else if (m==2) {
            if (!s.empty()) {
                cout << s.top() << "\n";
                s.pop();
            } else {
                cout << -1 << "\n";
            }
        } else if (m==3) {
            cout << s.size() << "\n";
        } else if (m==4) {
            if (!s.empty()) {
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
        } else {
            if (!s.empty()) {
                cout << s.top() << "\n";
            } else {
                cout << -1 << "\n";
            }
        }   
    }
    return 0;
}