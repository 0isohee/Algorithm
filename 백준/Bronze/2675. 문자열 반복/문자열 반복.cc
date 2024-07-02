#include<iostream>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r;
        string s;
        cin >> r;
        cin >> s;

        int s_length = s.length();
        for (int l = 0; l < s_length; l++) {
            for (int c = 0; c < r; c++) {
                cout << s[l];
            }
        }
        cout << "\n";
    }
    return 0;
}